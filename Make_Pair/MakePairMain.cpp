#include <iostream>
#include <string>

#include "MakePair.hpp"

int main() {
    auto pair1 = make_my_pair(42, 3.14);
    pair1.print();

    std::string temp = "A";
    auto pair2 = make_my_pair(temp, 123);
    pair2.print();

    auto pair3 = make_my_pair(std::string("G"), 456);
    pair3.print();

    return 0;
}