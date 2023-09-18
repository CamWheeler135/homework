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
    try {
    number_rejector.throw_an_exception(11);
    number_rejector.throw_an_exception(1524371236412);
    number_rejector.throw_an_exception(10);
    number_rejector.throw_an_exception(1);   
    }
    catch (const std::runtime_error error) {
        std::cout << "Exception caught with error message " << error.what() << std::endl;
    }
}