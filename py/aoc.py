import sys

from aoc import run

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <year> <day>")
        sys.exit(1)
    run(int(sys.argv[1]), int(sys.argv[2]))
