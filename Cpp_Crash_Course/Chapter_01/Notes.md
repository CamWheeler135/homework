# Chapter 1 Notes

## Table of Contents
1. [Basic Structure of a C++ Program](#basic-structure-of-a-c-program)
2. [Compiler Tool Chain](#compiler-tool-chain)
3. [Bootstrapping C++](#bootstrapping-c)

## Basic Structure of a C++ Program

Here we are going to write a basic C++ program then compile and run it. We write C++ source code into *source files*. We then use the complier to convert the source code into machine code that the computer can directly work with.

**Creating Our First Program**

    #include <iostream>

    int main()
    {
        std::cout << "Hello World!\n";
        return 0;
    }


**Main: C++ Starting Point**

C++ programs have a single entry point, an entry point is a function that executes when a user runs a program. Functions as we already know are blocks of code that take an input and return some form of output.

Within main, we call the `printf` function this prints the string to the terminal. The program exits by returning 0 meaning that the program has run successfully. These are called *exit codes* and they are used by the operating system to determine how well the program has run. 

**Libraries: Pulling in External Code**

Much like Python, many smart people have written very good code that we can use in our own C++ programs. In python we have `import` statements, in C++ we have `#include` statements. 


## Compiler Tool Chain

After we have written some code the next step is to use a complier to turn our source code into machine code. The *compiler tool chain* is the tool that we use to do that. It is a series of 3 steps.

1. The **preprocessor** performs basic source code manipulation, this includes information about the code that is included in the `#include` statements. When this is complete, the source file then becomes a **single translation unit** the preprocessor will hand this code to the compiler for further processing. 

2. The **compiler** reads the translation unit and creates an **object file**. These files an intermediate format that most humans wont understand. For each translation unit, we get *one* object file.

3. The **linker** takes the object files and first finds the library code using the information that the preprocessor has include. So when compiling `our first program` the linker will go and find the `cstdio` library. **NOTE** The header at the top of the file and the library are NOT the same thing. The header contains information on how to use the library, the library contains the actual code. 

## Bootstrapping C++

**C++ Types**

CPP is an OOP. Objects are just abstractions with a state and a behavior. The state is represented by variables and the behavior is represented by functions. C++ is a *strongly* typed language, this means that each object must have a predefined data type.


**Declaring Variables**

We can declare variables in C++ using the following syntax:

    int x;

Here we are declaring that the variable `x` is of type `int`. We can also initialize the variable at the same time:

    int x = 5;

**Conditional Statements**

Conditional statements allow us to control the flow of our program. We can use comparison operators to compare two values 
`==, !=, <, >, <=, >=`. We can also use logical operators to combine multiple comparisons `&&, ||, !`.

If statements allow us to run blocks of code if a condition is true or not. The syntax of a if statement is:

    if (condition){
        // code to run if condition is true
    }
    else{
        // code to run if condition is false
    }

There are also `else if` this allows us to check multiple conditions. Running the program will result in X is zero being output to the terminal. **Note** main does not always need to return anything, return statements are optional for main functions, but it is better to include them.

    #include <cstdio>

    int main(void){
        int x = 0;

        if (x > 0) {
            printf("X is positive.\n");
        }
        else if (x < 0) {
            printf("X is negative.\n");
        }
        else {
            printf("X is zero.\n");
        }

        return 0;
    }

**Functions**

Functions are blocks of code that accept a number of inputs called parameters (or arguments, depending on when we are talking about them) and return an output. In C++ they are structured as so:

    return_type function_name(param_1_type param_1, param_2_type param_2, ...) {
        // function body
        return return_value; 
    }

The first part of the function is the dtype of the return value. We then declare the functions name, followed by the parameters that the function accepts. The function body is the code that will be executed when the function is called. The return value is the value that the function will return when it is called.

Parameters represent objects that are passed into the function that we can use. Lets make a program.

    #include <cstdio>

    int step(int x) {
        int result = 0;

        if (x > 0) {
            result --;    
        }
        else if (x < 0)
        {
            result ++;
        }
        return result;
        
        
    }

    int main(void) {
        int value_1 = 0;
        int value_2 = 10;
        int value_3 = -10;

        value_1 = step(value_1);
        value_2 = step(value_2);
        value_3 = step(value_3);

        printf("Value 1 = %d\n", value_1);
        printf("Value 2 = %d\n", value_2);
        printf("Value 3 = %d\n", value_3);
}

**printf Format Specifiers**

To include dtypes other than strings in printf, we need to include placeholders, these are called format specifiers. The format specifiers are:

    %c - Character
    %d - Signed integer
    %e - Scientific notation of floats
    %f - Float values
    %i - Integer
    %o - Octal number
    %s - String
    %u - Unsigned integer
    %x - Hexadecimal number
    %p - Pointer address

There are really strong opinions when it comes to printing to the terminal, using prinf or cout. I will be using printf for now, but I will switch to cout later on. This is because cout involves a lot of C++ concepts that we have not covered yet.

**Comments**

Comments are human readable annotations for code, we can use inline comments with `//` or block comments with `/* */`. 

## Summary

In this chapter we have gotten up and running with C++, we have learned about the structure of a simple program, how the complier tool chain works. We have also looked at how to declare variables, use conditional statements, functions and comments.


## Exercises

1. Create a function called absolute value tha returns the absolute value of a single argument.
2. Create a function called sum that returns the sum of two arguments.


