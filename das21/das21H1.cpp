#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

const int lines = 8;

enum Type
{
    Integer,
    String,
    Double
};

struct Data
{
    Type valueType;
    std::string value;
};

bool isInt(const std::string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool isDouble(const std::string& str)
{
    int temp = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
        {
            if (str[i] == '.' && temp == 0)
            {
                ++temp;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void readFile(const std::string& fileName, Data myLine[], int& count)
{
    std::ifstream file(fileName);
    std::string line;

    if(!file.is_open())
    {
        std::cout << "File is not opened: " << fileName << std::endl;
        return;
    }

    while (getline(file, line) && count < lines)
    {
        myLine[count].value = line;
        if (isInt(line))
        {
            myLine[count].valueType = Integer;
        }
        else if (isDouble(line))
        {
            myLine[count].valueType = Double;
        }
        else
        {
            myLine[count].valueType = String;
        }

        ++count;
    }

    file.close();
}

void print(const Data myLine[])
{
    for (int i = 0; i < lines; ++i)
    {
        std::cout << "Value: " << myLine[i].value << " Type: ";
        switch (myLine[i].valueType)
        {
        case Integer:
            std::cout << "Int" << std::endl;
            break;
        case Double:
            std::cout << "Double" << std::endl;
            break;
        case String:
            std::cout << "String" << std::endl;
            break;
        }
    }
}

int main()
{
    std::string fileName = "das21/HomeWork.txt";
    Data myLine[lines];
    int count = 0;

    readFile(fileName, myLine, count);
    print(myLine);

    return 0;
}