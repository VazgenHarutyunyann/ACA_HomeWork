#include <iostream>
#include <map>
#include <string>

std::string intToString(const int& number)
{
    std::map<int , std::string> myMap = 
    {
        {0 , "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"}
    };


    return myMap[number];
    
}

std::string numberToString(const int& number)
{
    std::string result = "";
    std::string numberStr = std::to_string(number);

    for (char c : numberStr)
    {
        int digit = c - '0';
        std::string literal = intToString(digit);

        if (result.empty())
        {
            result = literal;
        }
        else
        {
            result = result + " " + literal;
        }
        
    }

    return result;
    
}


int main()
{
    int number = 0;
    std::cout << "Write number: ";
    std::cin >> number;

    std::string temp = numberToString(number);
    std::cout << temp;


    return 0;
}