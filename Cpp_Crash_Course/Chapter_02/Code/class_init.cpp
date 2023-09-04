#include <cstdio>

class Class1 {
public:
    Class1() {
        printf("No Argument\n");
    }
    Class1(int x) {
        printf("Argument: %d\n", x);
    }
    Class1(char x) {
        printf("Argument: %c\n", x);
    }
    Class1(float x) {
        printf("Argument: %f\n", x);
    }
};

int main(void) {
    Class1 no_args{};
    Class1 float_args{2.33e23f}; // If this is not big enough of a float it will throw an error because the compiler might confuse it with the int.
    Class1 int_args{1};
    Class1 char_args{'c'};

    // () also works, but we get some odd behavior
    Class1 parenth_no_args(); // This does not show up because the compiler gets confused with a function declaration, so it is best to use {}
    Class1 parenth_float_args(2.33e23f); 
    Class1 parenth_int_args(1);
    Class1 parenth_char_args('c'); 
}