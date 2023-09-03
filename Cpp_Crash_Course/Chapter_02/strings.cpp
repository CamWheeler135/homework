#include <cstdio>
#include <string>
#include <iostream>

int main(void) {
    char bar_string[] = "Hello World\n";
    printf("%s", bar_string);

    char *foo_string = "Hello World\n";
    printf("%s", foo_string);

    std::string baz_string = "Hello World\n";
    std::cout << bar_string << std::endl; // printf only accepts C-style strings https://stackoverflow.com/questions/10865957/printf-with-stdstring. 
}