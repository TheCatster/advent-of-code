#include "advent-of-code.h"

void part_one(std::vector<std::string> &raw_input);
void part_two(std::vector<std::string> &raw_input);

int main() {
  std::vector<std::string> raw_input{read_input(2021, 2)};

  part_one(raw_input);
  part_two(raw_input);

  return 0;
}

void part_one(std::vector<std::string> &raw_input) {
  int depth{0};
  int horizontal{0};

  for (auto line : raw_input) {
    auto values{split(line, ' ')};
    std::string command{values[0]};
    int value{std::stoi(values[1])};

    if (command == "forward") {
      horizontal += value;
    } else if (command == "up") {
      depth -= value;
    } else {
      depth += value;
    }
  }

  std::cout << "Part One: " << depth * horizontal << std::endl;
}

void part_two(std::vector<std::string> &raw_input) {
  int aim{0};
  int depth{0};
  int horizontal{0};

  for (auto line : raw_input) {
    auto values{split(line, ' ')};
    std::string command{values[0]};
    int value{std::stoi(values[1])};

    if (command == "forward") {
      horizontal += value;
      depth += value * aim;
    } else if (command == "up") {
      aim -= value;
    } else {
      aim += value;
    }
  }

  std::cout << "Part Two: " << depth * horizontal << std::endl;
}
