#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <stdlib.h>

int main()
{
    std::list<std::string> numbers;
    std::ifstream infile("100_numbers.txt");
        std::string line;
        std::string result = "";

        while (std::getline(infile, line))
        {
        numbers.push_back(line);
        }

    int summOfRow = 0;

    for(int i = 49; i >= 0 ; i--)
    {
        for(std::list<std::string>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
        {
            summOfRow += atoi((*iter).substr(i, 1).c_str());
            
        }

        result.insert(0,std::to_string(summOfRow % 10));

        summOfRow /= 10;
    }

    result.insert(0,std::to_string(summOfRow));
    std::cout << result.substr(0,10) << std::endl;

    return 0;
}