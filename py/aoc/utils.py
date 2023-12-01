def parse_input(year: int, day: int) -> list[str]:
    with open(f"../input/{year}/{day}", "r") as f:
        return f.read().splitlines()
