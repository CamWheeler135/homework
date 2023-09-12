/*Create read_from and write_to functions, these functions should read or write to upper or lower as appropriate.
Perform bounds checking to prevent buffer overflow.*/
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

// Read from a file
void read_file(std::string file_name) {

    std::string line; // Because we are using std::string, we cannot buffer overflow as it will grow with each character.
    std::ifstream ReadFile(file_name);

    // Iterate through each line and print to the console.
    while (std::getline(ReadFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    ReadFile.close();
}

// write to a file in upper or lower.
void write_to_file(std::string file_name, bool upper_case, std::string line_to_write) {

    // Create or Open the file.
    std::ofstream WriteFile(file_name);

    // Check that the file is open, the write to it, either in upper or lower.
    if (WriteFile.is_open()) {
        if (upper_case) {
            std::transform(line_to_write.begin(), line_to_write.end(), line_to_write.begin(), toupper);
        }
        else {
            std::transform(line_to_write.begin(), line_to_write.end(), line_to_write.begin(), tolower);
        }

        WriteFile << line_to_write;
    }

    WriteFile.close();
}

int main(void) {
    // Lets read from the file and print it to the console
    read_file("file_to_read_from.txt");

    // Lets write to a file in lower case.
    write_to_file("file_to_write_to1.txt", false, "This sHouLd be iN Lower caSe.");

    // Now lets try upper case
    write_to_file("file_to_write_to2.txt", true, "this should be in upper case.");

    return 0;
}
