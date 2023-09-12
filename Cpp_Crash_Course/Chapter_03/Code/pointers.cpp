#include <cstdio>

int main(void) {
    int my_int = 3;
    int* my_int_ptr = &my_int;
    printf("My integer is %d\n", my_int);
    printf("My intergers memory address is %p\n", my_int_ptr); // Note that this could change each run.
    printf("My dereferenced pointer %d\n", *my_int_ptr);
}