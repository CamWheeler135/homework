#include <iostream>
#include <utility>

void print_int(int& x) {
    std::cout << "lvalue " << x << std::endl;
}

void print_int(int&& x) {
    int rval_x = std::move(x);
    std::cout << "rvalue " << rval_x << std::endl;
}

int main(void) {
    int my_int = 10;
    print_int(my_int);
    print_int(10);
}

