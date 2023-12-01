from aoc.utils import parse_input

input = parse_input(2023, 1)

replacements = {
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}

def replace(line) -> str:
    substrings = [line[i:j+1] for i in range(len(line)) for j in range(i,len(line))]
    substrings = [s for s in substrings if s in replacements.keys()]

    if substrings:
        line = line.replace(substrings[-1],f'{replacements[substrings[-1]]}')
        line = line.replace(substrings[0],f'{replacements[substrings[0]]}')

    return line

def part_one():
    nums_lst = [list(filter(str.isdigit, line)) for line in input]
    fltrd = [list(map(int, value_lst)) for value_lst in nums_lst]
    digits = [int(f"{lst[0]}{lst[-1]}") for lst in fltrd]
    total = sum(digits)
    print(f"part_one: solution is {total}")

def part_two():
    input_cleaned = [replace(line) for line in input]
    nums_lst = [list(filter(str.isdigit, line)) for line in input_cleaned]
    fltrd = [list(map(int, value_lst)) for value_lst in nums_lst]
    digits = [int(f"{lst[0]}{lst[-1]}") for lst in fltrd]
    total = sum(digits)
    print(f"part_two: solution is {total}")
