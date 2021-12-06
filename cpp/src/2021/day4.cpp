#include "advent-of-code.h"

int main() {
  std::vector<std::string> input_raw{split(read_input_str(2021, 4), "\n\n")};
  std::vector<std::string> called_numbers{split(input_raw[0], ",")};
  std::vector<std::string> boards;

  for (std::string i : input_raw | std::views::drop(1)) {
    boards.push_back(i);
  }

  std::cout << boards[0] << std::endl;

  return 0;
}
