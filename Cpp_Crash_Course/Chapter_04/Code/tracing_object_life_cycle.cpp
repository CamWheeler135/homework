#include <iostream>
#include <string>

class Tracer {
private:
    const std::string name;

public:
    // Constructor
    Tracer(std::string name) : name{ name } {
            std::cout << name << " constructed" << std::endl;
        }
    
    // Destructor
    ~Tracer() {
        std::cout << name << " Destroyed" << std::endl;
    }
};


static Tracer t1{ "Static variable" };
thread_local Tracer t2{ "Thread-local variable" };

int main() {
    std::cout << "A" << std::endl;
    Tracer t3{ "Automatic variable" };
    std::cout << "B" << std::endl;
    Tracer* t4 = new Tracer{ "Dynamic variable" };
    std::cout << "C" << std::endl;
    delete t4;
}