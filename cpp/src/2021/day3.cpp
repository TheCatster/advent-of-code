#include "advent-of-code.h"

void part_one(std::vector<std::string> &raw_input);
void part_two(std::vector<std::string> raw_input);
std::vector<std::string> calculate_oxygen(std::vector<std::string> input_list,
                                          int &position);
std::vector<std::string> calculate_co2(std::vector<std::string> input_list,
                                       int &position);

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

void part_two(std::vector<std::string> raw_input) {
  std::vector<std::string> modified_oxygen{};
  std::vector<std::string> modified_co2{};

  for (int i{0}; i < raw_input[0].size(); i++) {
    std::vector<std::string> temp_ox{calculate_oxygen(modified_oxygen, i)};
    modified_oxygen.clear();
    modified_oxygen.assign(temp_ox, temp_ox.size());
    // modified_co2 = calculate_co2(modified_co2, i);
  }

  for (auto x : modified_oxygen) {
    std::cout << x << std::endl;
  }
}

std::vector<std::string> calculate_oxygen(std::vector<std::string> input_list,
                                          int &position) {
  int max{0};
  std::vector<std::string> modified_list{0};

  for (auto &raw_number : input_list) {
    std::string raw_digit{(1, raw_number[position])};
    int digit{std::stoi(raw_digit)};

    max += digit;
  }

  int num_ones{max};
  auto num_zeroes{input_list.size() - num_ones};

  if (num_ones > num_zeroes) {
    max = 1;
  } else if (num_ones < num_zeroes) {
    max = 0;
  } else {
    max = 1;
  }

  for (auto x : input_list) {
    std::string raw_digit{(1, x[position])};
    int digit{std::stoi(raw_digit)};

    if (digit == max) {
      modified_list.push_back(x);
    }
  }
}

std::vector<std::string> calculate_co2(std::vector<std::string> input_list,
                                       int &position) {}
