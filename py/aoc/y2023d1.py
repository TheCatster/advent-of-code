import re
from aoc.utils import parse_input

input = parse_input(2023, 1)

def multiple_replace(text):
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
    # Create a regular expression from the dictionary keys
    regex = re.compile("(%s)" % "|".join(map(re.escape, replacements.keys())))
    # For each match, look-up corresponding value in dictionary
    return regex.sub(lambda mo: replacements[mo.group()], text)

def part_one():
    nums_lst = [list(filter(str.isdigit, line)) for line in input]
    fltrd = [list(map(int, value_lst)) for value_lst in nums_lst]
    digits = [int(f"{lst[0]}{lst[-1]}") for lst in fltrd]
    total = sum(digits)
    print(f"part_one: solution is {total}")

def part_two():
    input_cleaned = [multiple_replace(line) for line in input]
    nums_lst = [list(filter(str.isdigit, line)) for line in input_cleaned]
    fltrd = [list(map(int, value_lst)) for value_lst in nums_lst]
    digits = [int(f"{lst[0]}{lst[-1]}") for lst in fltrd]
    total = sum(digits)
    print(f"part_two: solution is {total}")
