#include <cstdio>

class Class1 {
private:
    int x = 0;

public:

    int get_x() {
        return x;
    }

    void set_x(int new_x) {
        x = new_x;
    }

};

int main(void) {
    Class1 my_class;

     printf("The value of x is %d\n", my_class.get_x());

    // Create a pointer to our instance.
    Class1* my_class_ptr = &my_class;
    // Using the member of operator to dereference our pointer, then access a member, in this case a method. 
    my_class_ptr->set_x(5);

    printf("The address of the my_class instance %p\n", my_class_ptr);
    printf("The value of x is %d\n", my_class_ptr->get_x());
}