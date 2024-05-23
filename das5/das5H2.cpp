#include <iostream>

void* operator new(std::size_t size) {
    static bool firstTime = true;
    if (firstTime) {
        std::cout << "Hello World" << std::endl;
        firstTime = false;
    }

    return malloc(size);
}

int main() {

    int* ptr = new int;

    delete ptr;
    ptr = nullptr;

    return 0;
}