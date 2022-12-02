use std::fs;

pub fn read_input(year: u32, day: u32) -> String {
    fs::read_to_string(format!("../../../input/{}/{}", year, day))
        .expect("Something went wrong reading the file!")
}
