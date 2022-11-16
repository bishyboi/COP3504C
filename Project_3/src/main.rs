use std::os::raw;

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
fn generate_tga_bytes(header: Header, image_bytes: Vec<u8>) {
    //
}

// Returns a Header object and image data in Vec<u8>
fn get_tga_bytes(input_path: &str) -> (Header, Vec<u8>) {
    let raw_data: Vec<u8> = read_file_vec(input_path).expect("Failed to open file.");
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

    let image_bytes = raw_data[18..].to_vec();

    (header, image_bytes)
}

fn main() {
    let input_path = "input/car.tga";
    let image_bytes = read_file_vec(input_path).expect("Could not read file.");
    create_image(&image_bytes, "output/car.tga");
}
