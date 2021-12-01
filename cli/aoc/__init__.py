import typing
import subprocess
import os
import requests

__version__ = "0.1.0"

intro_emojis = "🎄🎄🎄"

### These are preconfigured for my needs. This program isn't designed to be used by everyone as-is.
language_commands = {
    "jl": "julia jl/{year}/day{day}.jl",
    "py": "python3 py/{year}/day{day}.py",
    "rs": "cargo run --manifest-path rs/{year}/Cargo.toml --bin day{day}",
    "c": "gcc -o c/{year}/day{day}.out c/{year}/day{day}.c && c/{year}/day{day}.out",
    "cpp": "g++ -o cpp/{year}/day{day}.out cpp/{year}/day{day}.cpp && cpp/{year}/day{day}.out",
}


def execute_file(language: str, year: int, day: int) -> str:
    try:
        command = language_commands[language].format(day=day, year=year)
    except KeyError:
        return "The selected language isn't currently registered!"

    (exit_code, output) = subprocess.getstatusoutput(command)

    if exit_code == 0:
        return output
    else:
        return "The file could not be executed."


def retrieve_input(year: int, day: int):
    input_file = f"input/{year}/{day}"

    if not os.path.isfile(input_file):
        # Example input URL: https://adventofcode.com/2020/day/7/input
        print("First time running this year and date: retrieving input!")

        try:
            cookies = {"session": os.getenv("AOC_TOKEN")}
        except EnvironmentError:
            print("There is no token in the .env file! Add yours!")
            return

        url = f"https://adventofcode.com/{year}/day/{day}/input"
        response = requests.get(
            url,
            cookies=cookies,
            headers={"User-Agent": "advent-of-code thecatster"},
        )

        if response.ok:
            with open(input_file, "w") as f:
                f.write(response.text)
                f.truncate(f.tell() - 1)
        else:
            print("Request for input failed.")
            return


def run():
    print(f"{intro_emojis} Welcome to Advent of Code! {intro_emojis}")

    language = input("Please enter the file extension of the language to run: ")
    year = input("Please enter the year number you would like to run: ")
    day = input("Please enter the day number you would like to run: ")

    retrieve_input(year, day)
    print(execute_file(language, year, day))

    return
