#include <cstdio>
#include <string>
#include <iostream>

class Company {
private:
    std::string name;

public:
    // Setter.
    bool set_name(std::string new_name){
        if (new_name != "Apple") {
            return false;
        }
        else {
            name = new_name;
            return true;
        }
    }

    // Getter
    std::string get_name(){
        return name;
    }
};

int main(void){
    Company Apple;
    if (!Apple.set_name("Microsoft")){
        Apple.set_name("Apple");
    }
    std::cout << "The name of the company is " << Apple.get_name() << std::endl;
}