def read_input(year: int, day: int):
    with open(f"input/{year}/{day}", "r") as f:
        return f.read()


inputs = [x for x in read_input(2021, 2).split("\n")]


def part_one():
    depth = 0
    horizontal = 0

    for line in inputs:
        (command, value) = line.split(" ")
        if command == "forward":
            horizontal += int(value)
        elif command == "up":
            depth -= int(value)
        else:
            depth += int(value)

    print(f"Part One: {depth * horizontal}")


def part_two():
    aim = 0
    depth = 0
    horizontal = 0

    for line in inputs:
        (command, value) = line.split(" ")
        if command == "forward":
            horizontal += int(value)
            depth += int(value) * aim
        elif command == "up":
            aim -= int(value)
        else:
            aim += int(value)

    print(f"Part Two: {depth * horizontal}")


part_one()
part_two()
