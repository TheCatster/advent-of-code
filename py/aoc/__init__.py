from aoc import y2023d1

def run(year: int, day: int):
    match year, day:
        case 2023, 1:
            y2023d1.part_one()
            y2023d1.part_two()
        case _:
            raise ValueError("Not a valid year!")
