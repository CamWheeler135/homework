#include <iostream>

int main(void) {
    int number_1 = 42;
    int number_2 = 4242;

    int& reference = number_1;
    std::cout << "Number 1 " << number_1 << std::endl;
    std::cout << "Number 1 reference " << reference << std::endl;

    reference = number_2;

    std::cout << "Number 1 " << number_1 << std::endl;
    std::cout << "Number 1 reference " << reference << std::endl;
    std::cout << "Number  2 " << number_2 << std::endl;
}