#include <cstdio>
#include <string>
#include <iostream>

struct Book {
    std::string name;
    int year_of_release;
    int num_of_pages;
    bool hardcover;
};

int main(void) {
    Book My_book;
    My_book.name = "The C++ Programming Language";
    My_book.year_of_release = 2013;
    My_book.num_of_pages = 1376;
    My_book.hardcover = true;


    std::cout << "The name of my book is " << My_book.name << std::endl; 
    printf("The year of release was %i\n", My_book.year_of_release);
    printf("There are %i pages in the book\n", My_book.num_of_pages);
    if (My_book.hardcover == true) {
        printf("It comes in hardcover\n");
    }
    else {
        printf("It does not come in hardcover\n");
    }
}
