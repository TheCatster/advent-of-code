#include "advent-of-code.h"

/*
** Part two of day three took a lot out of me.
** I had to look up some minor things, but more or less was able to rethink this
*myself.
**
** Woo hoo!
**
*/

void part_one(std::vector<std::string> &raw_input);
void part_two(std::vector<std::string> &raw_input);

std::vector<int> count_ones(std::vector<std::string> &raw_input);

int calculate_gamma_rate(std::vector<int> counter,
                         std::vector<std::string> input);
int calculate_epsilon_rate(std::vector<int> counter,
                           std::vector<std::string> input, int gamma_rate);
int calculate_rating(std::vector<std::string> &raw_input, std::string option);

int main() {
  std::vector<std::string> raw_input{read_input(2021, 3)};

  part_one(raw_input);
  part_two(raw_input);

  return 0;
}

std::vector<int> count_ones(std::vector<std::string> &raw_input) {
  std::vector<int> ones_pos{};
  for (int i{0}; i < static_cast<int>(raw_input[0].size()); ++i) {
    ones_pos.push_back(0);
  }

  for (const std::string &line : raw_input) {
    for (int i{0}; i < static_cast<int>(line.size()); ++i) {
      if (line[i] == '1') {
        ++ones_pos[i];
      }
    }
  }

  return ones_pos;
}

void part_one(std::vector<std::string> &raw_input) {
  std::vector<int> counter{count_ones(raw_input)};

  int gamma_rate{calculate_gamma_rate(counter, raw_input)};
  int epsilon_rate{calculate_epsilon_rate(counter, raw_input, gamma_rate)};

  std::cout << "Part One: " << gamma_rate * epsilon_rate << std::endl;
}

int calculate_gamma_rate(std::vector<int> counter,
                         std::vector<std::string> input) {
  int gamma_rate{0};

  for (auto count_ones : counter) {
    int count_zeroes{static_cast<int>(input.size()) - count_ones};
    if (count_ones > count_zeroes) {
      ++gamma_rate;
    }

    gamma_rate <<= 1;
  }

  gamma_rate >>= 1;

  return gamma_rate;
}

int calculate_epsilon_rate(std::vector<int> counter,
                           std::vector<std::string> input, int gamma_rate) {
  int significant_bit_mask{0};

  for (int i{0}; i < static_cast<int>(counter.size()); ++i) {
    ++significant_bit_mask;
    significant_bit_mask <<= 1;
  }

  significant_bit_mask >>= 1;

  return (~gamma_rate & significant_bit_mask);
}

void part_two(std::vector<std::string> &raw_input) {
  int oxygen_generator_rating{calculate_rating(raw_input, "oxygen")};
  int co2_scrubber_rating{calculate_rating(raw_input, "co2")};

  std::cout << "Part Two: " << oxygen_generator_rating * co2_scrubber_rating
            << std::endl;
}

int calculate_rating(std::vector<std::string> &raw_input, std::string option) {
  int curr_bit_pos{0};
  std::vector<std::string> input{raw_input};

  while (static_cast<int>(input.size()) != 1) {
    std::vector<int> counter{count_ones(input)};
    int count_ones{counter[curr_bit_pos]};
    int count_zeroes{static_cast<int>(input.size()) - count_ones};

    char filter{option == "oxygen" ? count_ones >= count_zeroes ? '1' : '0'
                : count_ones >= count_zeroes ? '0'
                                             : '1'};

    std::vector<std::string> new_input;
    std::copy_if(input.begin(), input.end(), std::back_inserter(new_input),
                 [curr_bit_pos, filter](const std::string &line) {
                   return line[curr_bit_pos] == filter;
                 });

    input = new_input;
    ++curr_bit_pos;
  }

  return std::stoi(input[0], nullptr, 2);
}
