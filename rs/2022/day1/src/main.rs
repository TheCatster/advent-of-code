use utils::read_input;

fn strs_to_nums(input: &[Vec<String>]) -> Vec<u32> {
    input.iter().map(|values|
            values
                .to_vec()
                .iter()
                .map(|x| x
                    .as_str()
                    .parse::<u32>()
                    .expect("Ah! Number conversion failed."))
                .sum())
        .collect()
}

fn part_one(input: &[Vec<String>]) -> u32 {
    strs_to_nums(input).iter().max().expect("No maximum can be found!").to_owned()
}

fn part_two(input: &[Vec<String>]) -> u32 {
    let mut mod_input =  strs_to_nums(input);

    mod_input.sort();
    mod_input.reverse();

    mod_input.iter().take(3).map(|x| x.to_owned()).sum()
}

fn main() {
    let input = read_input(2022, 1);
    let input_lst = input.lines()
        .map(|x| x.to_string())
        .collect::<Vec<_>>()
        .split(|x| x.is_empty())
        .map(|x| x.to_owned())
        .collect::<Vec<_>>();

    println!("The answer to part one is: {}", part_one(&input_lst));
    println!("The answer to part two is: {}", part_two(&input_lst));
}
