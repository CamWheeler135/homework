/* Full SimpleString Class with copy and move semantics. */

#include <iostream>
#include <utility>
#include <cstring>
#include <stdexcept>


class SimpleString {
private:
    char* buffer;
    size_t max_size;
    size_t length;

public:

    // Constructor 
    SimpleString(size_t max_size)
        : max_size{max_size}, length{} {
            if (max_size < 0) {
                throw std::runtime_error("The minimum size is at least 1");
            }
            buffer = new char[max_size]; // array of max_size chars.
            buffer[0] = 0;
        }

    // Destructor
    ~SimpleString() {
        delete buffer;
    }

    // Copy Constructor
    SimpleString(const SimpleString& other) 
        : max_size{other.max_size}, length{other.length}, buffer{new char[other.max_size]} {
            std::strncpy(buffer, other.buffer, max_size);
        }
    
    // Move Constructor
    SimpleString(SimpleString&& other) noexcept
        : max_size{other.max_size}, length{other.length}, buffer{other.buffer} {
            other.buffer = nullptr;
            other.max_size = 0;
            other.length = 0;
        }
    
    // Copy Operator
    SimpleString& operator=(const SimpleString& other) {
        if (this == &other) {
            return *this;
        }
        const auto new_buffer = new char[other.max_size];
        delete buffer;
        buffer = new_buffer;
        max_size = other.max_size;
        length = other.length;
        std::strncpy(buffer, other.buffer, max_size);
        return *this;
    }

    // Move Operator
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete buffer;
        buffer = other.buffer;
        max_size = other.max_size;
        length = other.length;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
        return *this;
    }

    // Prints out a string and its tag.
    void print_string() const {
        std::cout << buffer << std::endl; 
    }

    // Prints a message.
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
