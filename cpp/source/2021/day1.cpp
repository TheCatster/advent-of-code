#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string read_input(int year, int day);

int main()
{
    std::cout << "Test for C++!" << std::endl;

    std::string raw_input = read_input(2021, 1);
    return 0;
}

std::string read_input(int year, int day)
{
    std::string line;
    std::stringstream input_file_name_raw;
    input_file_name_raw << "input/" << year << "/" << day;

    std::string input_file_name = input_file_name_raw.str();

    std::ifstream input_file(input_file_name);

    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            std::cout << line << std::endl;
        }
        input_file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }

    return "Hello, world!";
}
