#include "advent-of-code.h"

std::vector<std::string> read_input(int year, int day)
{
    std::vector<std::string> inputVec;
    std::string line;
    std::stringstream input_file_name_raw;
    input_file_name_raw << "input/" << year << "/" << day;

    std::string input_file_name = input_file_name_raw.str();

    std::ifstream input_file(input_file_name);

    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            if (line.size() > 0)
            {
                inputVec.push_back(line);
            }
        }
        input_file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    return inputVec;
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}