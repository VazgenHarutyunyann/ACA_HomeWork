#include <iostream>
#include <exception>

class A 
{
public:
    ~A() 
    {
        try 
        {
            throw "Exception from destructor";
        } 
        catch (const char* exeption) 
        {
            std::cout << "Caught exception in destructor: " << exeption << std::endl;
        }
    }
};

int main() {
    try 
    {
        A obj;
    } 
    catch (const std::exception& exeption) 
    {
        std::cout << "Caught exception in main: " << exeption.what() << std::endl;
    }

    return 0;
}