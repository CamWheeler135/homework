#include <iostream>
#include <string>

class Class1 {
public:
    Class1(int num, std::string name)
        : number{ num }, name{ name } {}

    void print_info() {
        std::cout << "The number of this class " << this->number << std::endl;
        std::cout << "The name of this class " << this->name << std::endl; 
    }

    const int number; // Member init lists needed here. 
    std::string name; // Not needed here but works :)
};

int main(void) {
    Class1 this_class{ 12, "Instance 1"};
    this_class.print_info();
}