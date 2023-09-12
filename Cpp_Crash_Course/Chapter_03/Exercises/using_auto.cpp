#include <iostream>


int main(void) {
    auto number = 100;
    auto& number_ref = number;
    std::cout << number << std::endl;
    std::cout << number_ref << std::endl;

    auto number_2 = 200;
    number_ref = number_2;
    std::cout << number << std::endl;
    std::cout << number_ref << std::endl;
    std::cout << number_2 << std::endl;

}