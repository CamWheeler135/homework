/* 
Here we are making a class that will allow users to add multiple C-style strings together and print them out
to the terminal. 
*/
#include <iostream>
#include <stdexcept>
#include <cstring>

class SimpleString {
private:
    size_t max_size;
    size_t length;
    char* buffer;

public:
    // Constructor
    SimpleString(size_t max_size) :
        max_size{ max_size }, length{} {
            if (max_size == 0) {
                throw std::runtime_error{ "The max size must be at least 1. "};
            }
            buffer = new char[max_size]; // Allocating new memory from the heap of max_size. Because we are allocating we must delete.
            buffer[0] = 0;
        }

    // Destructor
    ~SimpleString() {
        delete[] buffer;
    }

    // Prints out a string and its tag.
    void print_string() const {
        std::cout << buffer; 
    }

    void print_message(const char* message) {
        std::cout << message << std::endl; 
    }

    // Adds a string and appends a newline and a null byte to the end of the string.
    bool append_line(char* string_to_add) {
        const auto len_of_str = strlen(string_to_add);
        // Check that the max size is at least 1.
        if (len_of_str + length + 2 > max_size) {
            return false;
        }
        std::strncpy(buffer + length, string_to_add, max_size - length);
        length += len_of_str;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
};

int main(void) {
    SimpleString my_sentence{30};
    my_sentence.append_line("Hello");

    if (!my_sentence.append_line("My name is")) {
        std::cout << "The sentence is too long to fit into the buffer you have created, add more buffer.\n";
        return 1;
    }

    if (!my_sentence.append_line("Cameron Wheeler")) {
        std::cout << "The sentence is too long to fit into the buffer you have created, add more buffer.\n";
        return 1;
    }

    my_sentence.print_string();
}


