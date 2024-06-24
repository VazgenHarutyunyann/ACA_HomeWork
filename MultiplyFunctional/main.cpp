#include <iostream>
#include <functional>

int main()
{
    auto multiply = [](const auto& value1){return [value1](const auto& value2){return value1 * value2;};};

    auto result = multiply(8)(3);
    std::cout << "Result = " << result << std::endl;

    return 0;
}