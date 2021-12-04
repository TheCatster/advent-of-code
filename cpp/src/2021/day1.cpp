#include "advent-of-code.h"

int main()
{
    std::vector<std::string> raw_input = read_input(2021, 1);

    for (auto &value : raw_input)
    {
        std::cout << value << std::endl;
    }

    return 0;
}
