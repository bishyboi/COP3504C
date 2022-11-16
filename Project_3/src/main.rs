//use std::fs::{File};
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


// Code taken from https://kerkour.com/rust-read-file 
fn read_file_vec(filepath: &str) -> Result<Vec<u8>, Box<dyn std::error::Error>> {
    let data = std::fs::read(filepath)?;
    Ok(data)
}

// Code taken from https://stackoverflow.com/questions/65702940/how-to-write-file-from-vecu8 
fn create_image(image_bytes: &Vec<u8>, output_path: &str){
    std::fs::write(output_path, image_bytes).expect("Failed to write to file.");
}

// Combines Header data and image data into one byte array
fn generate_tga_bytes(header: &mut Header, pixel_data: &Vec<Pixel>) -> Vec<u8>{
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
        tga_bytes.push(pixel.blue);
        tga_bytes.push(pixel.green);
        tga_bytes.push(pixel.red);
    }

    tga_bytes
}

// Returns a Header object and image data in Vec<u8>
fn get_tga_data(input_path: &str) -> (Header, Vec<Pixel>) {
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

    (header, pixels)
}

fn filter_red(pixel_data: &mut Vec<Pixel>){
    for pixel in pixel_data{
        pixel.red = 255;
    }
}

fn main() {
    let input_path: &str = "input/car.tga";

    let (mut header, mut pixel_data) = get_tga_data(input_path);

    filter_red(&mut pixel_data);
    
    let generated_bytes: Vec<u8> = generate_tga_bytes(&mut header, &pixel_data);
    create_image(&generated_bytes, "output/car.tga");
}
