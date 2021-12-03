use std::env;
use std::fs;

fn read_input(year: u32, day: u32) {
    let contents = fs::read_to_string(format!("input/{}/{}", year, day))
        .expect("Something went wrong reading the file");

    println!("With text:\n{}", contents);
}

fn part_one() {
    let increase_counter = 0;
}

fn part_two() {
    let increase_counter = 0;
}

fn main() {
    read_input(2021, 1);
}
