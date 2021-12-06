#include "advent-of-code.h"

void part_one(std::vector<std::string> &raw_input);
void part_two(std::vector<std::string> &raw_input);

int main() {
  std::vector<std::string> raw_input{read_input(2021, 3)};

  part_one(raw_input);
  part_two(raw_input);

  return 0;
}

void part_one(std::vector<std::string> &raw_input) {
  std::vector<int> counter_vec(12, 0);

  std::string gamma_bin_str{""};
  std::string epsilon_bin_str{""};

  for (auto &raw_number : raw_input) {
    for (int i{0}; i < raw_number.size(); i++) {
      std::string raw_digit{(1, raw_number[i])};
      int digit{std::stoi(raw_digit)};

      counter_vec[i] += digit;
    }
  }

  for (auto &x : counter_vec) {
    int num_ones{x};
    int num_zeroes{raw_input.size() - num_ones};

    if (num_ones > num_zeroes) {
      gamma_bin_str += "1";
      epsilon_bin_str += "0";
    } else {
      gamma_bin_str += "0";
      epsilon_bin_str += "1";
    }
  }

  int gamma_value{std::stoi(gamma_bin_str, 0, 2)};
  int epsilon_value{std::stoi(epsilon_bin_str, 0, 2)};

  std::cout << "Part One: " << gamma_value * epsilon_value << std::endl;
}

void part_two(std::vector<std::string> &raw_input) {
}
