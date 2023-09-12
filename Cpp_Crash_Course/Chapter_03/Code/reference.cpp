#include <cstdio>

class MyClass {
public:
    char name[265] = {"Cameron"};
};

void print_class_name(MyClass& my_class) {
    printf("The classes name is %s\n", my_class.name);
}

int main(void) {
    MyClass camerons_class;
    print_class_name(camerons_class);
}