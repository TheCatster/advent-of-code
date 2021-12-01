def read_input(year: int, day: int):
    with open(f"input/{year}/{day}", "r") as f:
        return f.read()


print(read_input(2021, 1).split("\n"))
