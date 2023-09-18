#include <iostream>
#include <stdexcept>

class Reject10 {
public:
    void throw_an_exception(long x) {
        if (x == 10) {
            throw std::runtime_error("The number 10 has been entered, this is not allowed");
        }
        else {
            std::cout << "This number is okay" << std::endl;
        }
    }
};

int main(void) {
    Reject10 number_rejector;
    number_rejector.throw_an_exception(11);
    number_rejector.throw_an_exception(1524371236412);
    number_rejector.throw_an_exception(10);
    number_rejector.throw_an_exception(1);
}