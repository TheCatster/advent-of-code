#include "advent-of-code.h"

void part_one(std::vector<int> &int_input);
void part_two(std::vector<int> &int_input);

int main()
{
    std::vector<std::string> raw_input = read_input(2021, 1);
    std::vector<int> int_input;

    std::transform(raw_input.begin(), raw_input.end(), std::back_inserter(int_input),
                   [](const std::string &str)
                   { return std::stoi(str); });

    part_one(int_input);
    part_two(int_input);

    return 0;
}

void part_one(std::vector<int> &int_input)
{
    int increase_counter = 0;

    for (int i = 1; i < int_input.size(); i++)
    {
        increase_counter += int_input[i] > int_input[i - 1];
    }

    std::cout << "Part One: " << increase_counter << std::endl;
}

void part_two(std::vector<int> &int_input)
{
    int increase_counter = 0;

    for (int i = 3; i < int_input.size(); i++)
    {
        increase_counter += int_input[i] > int_input[i - 3];
    }

    std::cout << "Part Two: " << increase_counter << std::endl;
}