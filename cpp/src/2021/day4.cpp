#include "advent-of-code.h"

std::vector<std::vector<std::vector<std::string>>> split_boards(std::vector<std::string> raw_input);
void part_one(std::vector<std::string> &raw_input);
void part_two(std::vector<std::string> &raw_input);

int main() {
  std::vector<std::string> input_raw{split(read_input_str(2021, 4), "\n\n")};

  part_one(input_raw);
  part_two(input_raw);

  return 0;
}

void part_one(std::vector<std::string> &raw_input) {
  std::vector<std::string> called_numbers{split(raw_input[0], ",")};
  std::vector<std::vector<std::vector<std::string>>> boards{split_boards(raw_input)};
  
  return;
}

void part_two(std::vector<std::string> &raw_input) {
  return;
}

std::vector<std::vector<std::vector<std::string>>> split_boards(std::vector<std::string> raw_input) {
  std::vector<std::vector<std::vector<std::string>>> boards;

  for (std::string board: raw_input | std::views::drop(1)) {
    std::vector<std::vector<std::string>> board_vec{};

    for (auto row_raw: split(board, "\n")) {
      std::vector<std::string> row_vec{};

      std::vector<std::string> row{split(row_raw, " ")};
      row.erase(std::remove(row.begin(), row.end(), " "), row.end());
      row.erase(std::remove(row.begin(), row.end(), ""), row.end());

      for (auto value: row) {
	row_vec.push_back(value);
      }

      board_vec.push_back(row_vec);
    }

    boards.push_back(board_vec);
  }

  return boards;
}
