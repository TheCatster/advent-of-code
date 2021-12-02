def read_input(year: int, day: int):
    with open(f"input/{year}/{day}", "r") as f:
        return f.read()


inputs = [int(x) for x in read_input(2021, 1).split("\n")]


def part_one():
    increase_counter = 0
    for i in range(0, len(inputs) - 1):
        if inputs[i] < inputs[i + 1]:
            increase_counter += 1
    print(f"Part One: {increase_counter}")


def part_two():
    increase_counter = 0
    for i in range(0, len(inputs) - 3):
        if (inputs[i] + inputs[i + 1] + inputs[i + 2]) < (
            inputs[i + 1] + inputs[i + 2] + inputs[i + 3]
        ):
            increase_counter += 1
    print(f"Part Two: {increase_counter}")


part_one()
part_two()
