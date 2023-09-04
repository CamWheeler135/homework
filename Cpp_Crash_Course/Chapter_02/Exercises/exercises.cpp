#include <cstdio>

// Create an enum class Operation that has a values Add, Subtract, Divide and Multiply

enum class Operation {
    Add,
    Subtract, 
    Multiply, 
    Divide,
};

// Create a calculator class. It should have a single constructor that takes an Operation as an argument.
// Create a method on Calculator called int calculate(int a, int b). When invoked this method should perform the
// appropriate operation and return the value

class Calculator {
public:

    Operation operation_to_do;

    // Constructor.
    Calculator(Operation operation) {
        operation_to_do = operation;
    }

    // Calculate method.
    int calculate(int a, int b) {
        if (operation_to_do == Operation::Add){
            return a + b;
        }
        else if (operation_to_do == Operation::Subtract) {
            return a - b;
        }
        else if (operation_to_do == Operation::Multiply) {
            return a * b;
        }
        else {
            return a / b;
        }
    }
};


int main(void) {
    Operation my_operation = Operation::Add;
    Calculator my_calculator{my_operation};

    int returned_value = my_calculator.calculate(10, 2);
    printf("%d\n", returned_value);
}
