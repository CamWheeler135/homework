#include <iostream>
#include <string> 

void print_message(const std::string message) {
    std::cout << message << std::endl;
    message[0] = "E"; // Throws an error.
}
