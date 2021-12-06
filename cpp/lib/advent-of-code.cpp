#include "advent-of-code.h"

std::vector<std::string> read_input(int year, int day) {
  std::vector<std::string> inputVec;
  std::string line;
  std::stringstream input_file_name_raw;
  input_file_name_raw << "input/" << year << "/" << day;

  std::string input_file_name{input_file_name_raw.str()};

  std::ifstream input_file{input_file_name};

  if (input_file.is_open()) {
    while (getline(input_file, line)) {
      if (line.size() > 0) {
        inputVec.push_back(line);
      }
    }
    input_file.close();
  } else {
    std::cout << "Unable to open file" << std::endl;
  }

  return inputVec;
}

std::string read_input_str(int year, int day) {
  std::stringstream input_file_name_raw;
  input_file_name_raw << "input/" << year << "/" << day;

  std::ifstream input_file{input_file_name_raw.str()};

  std::stringstream input_str;
  input_str << input_file.rdbuf();

  return input_str.str();
}

std::vector<std::string> split(const std::string &s, std::string delimiter) {
  size_t pos_start{0}, pos_end, delim_len{delimiter.length()};
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}
