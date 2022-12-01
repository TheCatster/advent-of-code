use std::{env, io};
use std::fs;

fn read_input(year: u32, day: u32) -> String {
    fs::read_to_string(format!("../../../input/{}/{}", year, day))
        .expect("Something went wrong reading the file!")
}

fn part_one() {
    let increase_counter = 0;
}

fn part_two() {
    let increase_counter = 0;
}

fn main() {
    let input = read_input(2022, 1);
    println!("{}", &input);
}
