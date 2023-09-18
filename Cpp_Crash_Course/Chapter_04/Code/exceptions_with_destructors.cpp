#include <iostream>
#include <stdexcept>

class CyberdyneSerries800 {
public:
    CyberdyneSerries800() {
        std::cout << "CyberdyneSerries800 constructed" << std::endl;
    }

    ~CyberdyneSerries800() {
        std::cout << "CyberdyneSerries800 destroyed" << std::endl;
        throw std::runtime_error{ "CyberdyneSerries800 destructor threw an error" };
    }
};

int main(void) {

    try {
        CyberdyneSerries800 terminator;
        throw std::runtime_error{ "Main threw an error" };
    }
    catch (std::exception e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

}

