#[derive(Clone)]
struct Header {
    id_length: u8,
    color_map_type: u8,
    image_type_code: u8,
    color_map_origin: Vec<u8>,
    color_map_length: Vec<u8>,
    color_map_depth: u8,
    x_origin: Vec<u8>,
    y_origin: Vec<u8>,
    width: Vec<u8>,
    height: Vec<u8>,
    bits_per_pixel: u8,
    image_descriptor:u8
}

#[derive(Clone, Copy)]
struct Pixel{
    red: u8,
    green: u8,
    blue: u8
}

struct TGA{
    header: Header,
    pixel_data: Vec<Pixel>
}
// Code taken from https://kerkour.com/rust-read-file 
fn read_file_vec(filepath: &str) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
    let data = std::fs::read(filepath)?;
    Ok(data)
}

// Code taken from https://stackoverflow.com/questions/65702940/how-to-write-file-from-vecu8 
// Takes raw byte data and writes it to a file
fn create_image(image_bytes: &Vec<u8>, output_path: &str){
    std::fs::write(output_path, image_bytes).expect("Failed to write to file.");
}

// Combines Header data and image data from a TGA object into one byte array
fn generate_tga_bytes(tga: TGA) -> Vec<u8>{
    let mut header: Header = tga.header;
    let pixel_data: Vec<Pixel> = tga.pixel_data;

    let mut tga_bytes: Vec<u8> = vec![];
    // Lord, forgive this abomination

    tga_bytes.push(header.id_length);
    tga_bytes.push(header.color_map_type);
    tga_bytes.push(header.image_type_code);

    tga_bytes.append(&mut header.color_map_origin);
    tga_bytes.append(&mut header.color_map_length);

    tga_bytes.push(header.color_map_depth);

    tga_bytes.append(&mut header.x_origin);
    tga_bytes.append(&mut header.y_origin);
    tga_bytes.append(&mut header.width);
    tga_bytes.append(&mut header.height);

    tga_bytes.push(header.bits_per_pixel);
    tga_bytes.push(header.image_descriptor);

    for pixel in pixel_data{
        tga_bytes.push(pixel.red);
        tga_bytes.push(pixel.green);
        tga_bytes.push(pixel.blue);
    }

    tga_bytes
}

// Returns a Header object and image data in Vec<u8>
fn get_tga_data(input_path: &str) -> TGA{
    let raw_data: Vec<u8> = read_file_vec(input_path).expect("Failed to open file.");

    // Lord, forgive this abomination even more
    let header: Header = Header { 
        id_length: raw_data[0], 
        color_map_type: raw_data[1], 
        image_type_code: raw_data[2], 
        color_map_origin: raw_data[3..5].to_vec(), 
        color_map_length: raw_data[5..7].to_vec(), 
        color_map_depth: raw_data[7], 
        x_origin: raw_data[8..10].to_vec(), 
        y_origin: raw_data[10..12].to_vec(), 
        width: raw_data[12..14].to_vec(), 
        height: raw_data[14..16].to_vec(), 
        bits_per_pixel: raw_data[16], 
        image_descriptor: raw_data[17]
    };

    let mut pixels: Vec<Pixel>= vec![];
    
    let mut counter: u8 = 2;
    let mut pixel: Pixel = Pixel { red: 0, green: 0, blue: 0 };

    for byte in raw_data[18..].to_vec(){
        match counter {
            2 => {
                pixel.red= byte;
                counter-=1;
            },
            1 => {
                pixel.green = byte;
                counter-=1;
            }
            0=> {
                pixel.blue = byte;
                counter=2;
                pixels.push(pixel);
            }
            _=> println!("Error: something broke")
        }
    }

    TGA{header: header, pixel_data: pixels}
}

fn multiply(a: &TGA, b: &TGA) -> TGA{

    let mut pixels: Vec<Pixel> = vec![];
    
    for pixel_num in 0..a.pixel_data.len(){
        pixels.push(multiply_pixels(&a.pixel_data[pixel_num], &b.pixel_data[pixel_num]));
    }

    TGA { header: a.header.clone(), pixel_data: pixels }
}

fn multiply_pixels(a: &Pixel, b: &Pixel) -> Pixel {
    let (mut a_red, mut a_green, mut a_blue) = ((a.red as f64)/(255.0), (a.green as f64)/(255.0), (a.blue as f64)/(255.0));

    let (b_red, b_green, b_blue) = (b.red as f64, b.green as f64, b.blue as f64);

    a_red*= b_red;
    a_green*= b_green;
    a_blue*= b_blue;

    a_red += 0.5f64;
    a_green+= 0.5f64;
    a_blue+= 0.5f64;

    Pixel { red: a_red as u8, green: a_green as u8, blue: a_blue as u8 }
}

// Order matters!
fn subtract(top: &TGA, bottom: &TGA) -> TGA{
    let mut pixels: Vec<Pixel> = vec![];
    
    for pixel_num in 0..top.pixel_data.len(){
        pixels.push(subtract_pixels(&top.pixel_data[pixel_num], &bottom.pixel_data[pixel_num]));
    }

    TGA { header: bottom.header.clone(), pixel_data: pixels }
}

fn subtract_pixels(top: &Pixel, bottom: &Pixel) -> Pixel {
    let mut pixel: Pixel = Pixel { red: 0, green: 0, blue: 0};
    if top.red <= bottom.red {
        pixel.red = bottom.red-top.red;
    }
    if top.green <= bottom.green {
        pixel.green = bottom.green - top.green;
    }
    if top.blue <= bottom.blue {
        pixel.blue = bottom.blue - top.blue;
    }

    pixel
}

fn screen(a: &TGA, b: &TGA) -> TGA{
    let mut pixels: Vec<Pixel> = vec![];
    
    for pixel_num in 0..a.pixel_data.len(){
        pixels.push(screen_pixels(&a.pixel_data[pixel_num], &b.pixel_data[pixel_num]));
    }

    TGA { header: a.header.clone(), pixel_data: pixels }
}

fn screen_pixels(a: &Pixel, b: &Pixel) -> Pixel {
    let mut pixel: Pixel = Pixel { red: 255, green: 255, blue: 255 };

    let (a_red, a_green, a_blue) = ((a.red as f64)/(255.0), (a.green as f64)/(255.0), (a.blue as f64)/(255.0));
    let (b_red, b_green, b_blue) = ((b.red as f64)/(255.0), (b.green as f64)/(255.0), (b.blue as f64)/(255.0));

    pixel.red -= ((1 as f64-a_red)*(1 as f64-b_red)*(255 as f64) + 0.5f64) as u8;
    pixel.green -= ((1 as f64-a_green)*(1 as f64-b_green)*(255 as f64) + 0.5f64) as u8;
    pixel.blue -= ((1 as f64-a_blue)*(1 as f64-b_blue)*(255 as f64)+  0.5f64) as u8;

    pixel
}

// Order matters!
fn overlay(a: &TGA, b: &TGA) -> TGA {
    let mut pixels: Vec<Pixel> = vec![];
    
    for pixel_num in 0..a.pixel_data.len(){
        pixels.push(overlay_pixels(&a.pixel_data[pixel_num], &b.pixel_data[pixel_num]));
    }

    TGA { header: a.header.clone(), pixel_data: pixels }
}

fn overlay_pixels(a: &Pixel, b: &Pixel) -> Pixel {
    let (mut a_red, mut a_green, mut a_blue) = ((a.red as f64)/(255.0), (a.green as f64)/(255.0), (a.blue as f64)/(255.0));

    let (b_red, b_green, b_blue) = (b.red as f64 /255.0, b.green as f64/255.0, b.blue as f64/255.0);

    if b.red <128 {
        a_red*= b_red*2.0;
    }else{
        a_red = 1.0 - 2.0*(1.0-a_red) * (1.0-b_red);
    }

    if b.green <128 {
        a_green*= b_green*2.0;
    }else{
        a_green = 1.0 - 2.0*(1.0-a_green) * (1.0-b_green);
    }

    if b.blue <128 {
        a_blue*= b_blue*2.0;
    }else{
        a_blue = 1.0 - 2.0*(1.0-a_blue) * (1.0-b_blue);
    }

    a_red*=255.0;
    a_green*=255.0;
    a_blue*=255.0;

    a_red += 0.5f64;
    a_green+= 0.5f64;
    a_blue+= 0.5f64;
    
    Pixel { red: a_red as u8, green: a_green as u8, blue: a_blue as u8 }
}

fn test_image(output: &Vec<u8>, example: &Vec<u8>) -> bool {
    let mut pass:bool = true;

    for i in 1..output.len(){
        if output[i]!= example[i]{
            pass = false;
        }
    }

    pass
}

fn print_test(tga: TGA, s: &str, no: u8) {
    let generated_bytes = generate_tga_bytes(tga);
    let example_path = format!("examples/EXAMPLE_{}.tga",s);
    let output_path = format!("output/{}.tga",s);
    let test_bytes = read_file_vec(&example_path).expect("Could not open file.");
    create_image(&generated_bytes, &output_path);
    
    println!("Task #{} Test: {}", no, test_image(&generated_bytes, &test_bytes));
}
fn main() {
    let car = get_tga_data("input/car.tga");
    let circles = get_tga_data("input/circles.tga");

    let layer_blue = get_tga_data("input/layer_blue.tga");
    let layer_green = get_tga_data("input/layer_green.tga");
    let layer_red = get_tga_data("input/layer_red.tga");

    let layer1 = get_tga_data("input/layer1.tga");
    let layer2 = get_tga_data("input/layer2.tga");

    let pattern2 = get_tga_data("input/pattern2.tga");
    let pattern1 = get_tga_data("input/pattern1.tga");

    let text = get_tga_data("input/text.tga");
    let text2 = get_tga_data("input/text2.tga");


    let part1 = multiply(&layer1, &pattern1);
    print_test(part1, "part1", 1);
    
    let part2 = subtract(&layer2, &car);
    print_test(part2, "part2", 2);

    let part3_temp = multiply(&layer1, &pattern2);
    let part3 = screen(&text, &part3_temp);
    print_test(part3, "part3", 3);

    let part4_temp = multiply(&layer2, &circles);
    let part4 = subtract(&pattern2, &part4_temp);
    print_test(part4, "part4", 4);

    let part5 = overlay(&layer1, &pattern1);
    print_test(part5, "part5", 5);

    // Part 6
    {
        let mut pixels: Vec<Pixel> = vec![];

        for i in 1..car.pixel_data.len(){
            let red: u8 = car.pixel_data[i].red;
            let blue: u8 = car.pixel_data[i].blue;
            
            let mut green: f64 = car.pixel_data[i].green as f64 / 255.0;

            if green + 200.0/255.0 > 1.0{
                green = 1.0;
            } else{
                green+=200.0/255.0;
            }

            green*=255.0;
            green += 0.5f64;

            let new_pixel = Pixel { red: red, green: green as u8, blue: blue };
            
            pixels.push(new_pixel);
        }

        let part6: TGA = TGA { header: car.header.clone(), pixel_data: pixels };
        print_test(part6, "part6", 6);
    }

    
    // Part 7
    {
        let mut pixels: Vec<Pixel> = vec![];

        for i in 1..car.pixel_data.len(){

            let modded_pixel: Pixel = if (car.pixel_data[i].blue as u32 *4 as u32) < 255 as u32
                                    {Pixel { red: 0, 
                                             green: car.pixel_data[i].green, 
                                             blue: car.pixel_data[i].blue*4}
                                    } else 
                                    {Pixel { red: 0, 
                                             green: car.pixel_data[i].green, 
                                             blue: 255}
                                    };
            
            
            pixels.push(modded_pixel);
        }

        let part7: TGA = TGA { header: car.header.clone(), pixel_data: pixels };
        print_test(part7, "part7", 7);
    }

    // Part 8
    {
        let mut pixels: Vec<Pixel> = vec![];

        for i in 1..car.pixel_data.len(){

            let modded_pixel: Pixel = Pixel { red: car.pixel_data[i].red, green: 0, blue: 0 };
            
            
            pixels.push(modded_pixel);
        }

        let part8_r: TGA = TGA { header: car.header.clone(), pixel_data: pixels };
        print_test(part8_r, "part8_r", 81);
    }
}
