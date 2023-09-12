# Chapter 3 Notes: Reference Types

Reference types store memory addresses of objects. These types enable us to be really efficient with our programming and allow us to create complex data structures. In this chapter we are going to discuss pointers and references. We are also going to see `this`, `const` and `auto` along the way. 

## Table of Contents
1. [Pointers](#pointers)
2. [Addressing Variables](#addressing-variables)
3. [Dereferencing Pointers](#dereferencing-pointers)
4. [Member-of-Pointer Operator](#member-of-pointer-operator)
5. [Pointers and Arrays](#pointers-and-arrays)
6. [Pointers are Dangerous](#pointers-are-dangerous)
7. [References](#references)
8. [Usage of Pointers and References](#usage-of-pointers-and-references)
9. [this Pointers](#this-pointers)
10. [const Correctness](#const-correctness)
11. [auto Type Deduction](#auto-type-deduction)

## Pointers

Pointers are variables that store the memory address of another object in our program, we declare a pointer using the `*` operator. For example if we were declaring a pointer to an integer, it would look like:

    int* my_ptr;

The format specifier for a pointer is %p:

    printf("The pointer value is %p\n", my_ptr)

Pointers are very low level and allow us to do really cool things, C++ also has some higher-level constructs that will help remove the need to manipulate memory directly.

## Addressing Variables

We can get the address of a variable by using the `&` operator, we might want to use this to initialize a pointer so it points to a corresponding variable memory address

    #include <cstdio>

    int main(void) {
        int my_int{};
        printf("My int is %d\n", my_int);
        int* my_int_ptr = &my_int;
        printf("The address it is stored at is %p\n", my_int_ptr);
    }

## Dereferencing Pointers

The dereference operator rather confusingly is also a `*`,  it is used to access the actual value that lives at the memory address a pointer is pointing to. So if `&` gives us the address then `*` does the exact opposite. Many operating systems APIs will return pointers, and if we want to access the value, we need to use the dereference operator. 

To declare a pointer, we place the * next the type, when we dereference a pointer we place the * next to the pointer itself. The compiler doesn't care, but it is good to have some difference.

After accessing the value of an object using the dereference operator, we can treat it like any other object:

    *my_int_ptr = 42; // Setting the value that the pointer points to = 42.

A nice way to think about it is that if we have a `*some_ptr` ANYWHERE in our code except the left side of an equal sign, we are getting the value at the address (we are *reading* from the address). Once we have dereferenced, we treat it like a value, consider my_int.

    int main(void) {
        int my_int{};
        printf("My int is %d\n", my_int);
        int* my_int_ptr = &my_int;
        printf("The address it is stored at is %p\n", my_int_ptr);
        printf("My dereferenced pointer %d\n", *my_int_ptr);
    }

## Member-of-Pointer Operator

The member of pointer operator (aka the arrow operator) `->` performs two simultaneous operations, 1. it dereferences the pointer and 2. it accesses a member of the pointed to object. We use this operator to reduce the code that we have to write, making it much cleaner. We will need to handle pointers to classes in a variety of situations so using the arrow operator makes life a bit easier. If we want to use a function that takes a member of a class, using the arrow operator is perfect here.

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

We declare a class1 and then store its address in a pointer. We then use the arrow operator to access the setter function and set the value of x to 5. We then use the arrow operator again to access the getter function and print the value of x.

We could have achieved the same result using the dereference operator and dot notation. 

    (*my_class_ptr).set_x(5); // Not as clean as my_class_ptr->set_x(5);

## Pointers and Arrays

Pointers share several characteristics with arrays. Pointers encode the memory address of an object, Arrays encode the location in memory and a length of contiguous memory. It is really easy for arrays to *decay* into pointers, this is where an array will loose its length information and simply just become a pointer. This is called **array decay**.

    int key_to_the_univserse[2] = {4, 2};
    int* key_ptr = &key_to_the_universe; // Points to 4

First we have initialized an array of len 2, we then create a pointer that points to that array but this only points to the first element in the array, not the whole array (this is decay).

The code below initializes an array containing `college` objects and then passes the array to a function as a pointer.

    #include <cstdio>

    struct College {
        char name[256];
    };

    void print_names(College* college_ptr) {
        printf("The name of the college is %s\n", college_ptr->name);
    }

    int main(void) {
        College colleges[] = {"Cambridge", "Oxford", "Edinburgh"};
        print_names(colleges);
    }

The print name function takes a pointer to a college object, so the `colleges` array decays into a pointer to just the first element, there is also another array decay when we use the point-to-member operator to access the name member of the college object.

**How Do We Handle Decay?**

If we are passing pointers to arrays, we pass two arguments to the function. 

1. The pointer to the array. 
2. The length of the array.

We use it as follows:

    #include <cstdio>

    struct College {
        char name[256];
    };

    void print_names(College* college_ptr, size_t length) {
        for (size_t i = 0; i < length; i++) {
            printf("The name of the college is %s\n", college_ptr[i].name);
        }
    }

    int main(void) {
        College colleges[] = {"Cambridge", "Oxford", "Edinburgh"};
        print_names(colleges, sizeof(colleges) / sizeof(College));
    }

Here, we pass the length of the array as well as the pointer to the first element of the array to the function. We then use the size to iterate over the array and print the na,es of the college objects inside of the array with the index brackets.

Note: `size_t` is a data type that is used to represent the size of an object in bytes, it is different to an `int`. 

See this answer from stack overflow. 

size_t is the data type used to represent sizes (as its name implies) and is platform (and even potentially implementation) dependent, so it should be used only for representing sizes.

Representing a size, size_t is naturally unsigned (can you have a box that is negative 3 meters wide?). Many stdlib functions, including malloc, sizeof, and various string operation functions use size_t as a datatype.

An int is signed by default, and even though its size is also platform dependent, it will be a fixed 32bits on most modern machine (and though size_t is 64 bits on any 64-bit architecture, int remains 32 bits long on those same 64-bit architectures).

Summary: Use size_t to represent the size of an object and int (or long) in other cases. Be aware that size_t is unsigned while both int and long are signed by default (unless prepended with unsigned , or modified to uint or ulong).

**Pointer Arithmetic**

We can also use pointer arithmetic to access the $n$th element in an array.

    #include <cstdio>

    struct Unis {
        char name[256];
    };

    void print_names(Unis* uni_ptr, size_t length) {
        for (size_t i = 0; i < length; i++) {
            printf("The name of the uni is %s\n", (uni_ptr + i)->name);
        }
    }

    int main(void) {
        Unis unis[] = {"Cambridge", "Oxford", "Edinburgh"};
        print_names(unis, sizeof(unis) / sizeof(Unis));
    }

Pointer arithmetic is a set of rules for addition and subtraction on pointers, it is a way of incrementing a pointer to the next element in the array, and the compiler will work out how many bytes it needs to move depending on the data type. For example 8 for an `uint_64` when we add 1. We could also jump up by 2 for example and the compiler would move the pointer by 16 bytes.

## Pointers are Dangerous

There are several things that we can do with pointers that the compiler cannot save us from when we go to compile our program. 

**Buffer Overflows**

When using an array, we can access an unlimited number of elements using `[]` or pointer notation, if we go over the length of the array, we can get some catastrophic results or just weird ones depending on what is in the memory we are accessing. 

    #include <cstdio>

    int main(void) {
        int my_array[5] = {1, 2, 3, 4, 5};
        int* my_ptr = my_array;
        printf("The value of the first element is %d\n", *my_ptr);
        printf("The value of the second element is %d\n", *(my_ptr + 1));
        printf("The value of the third element is %d\n", *(my_ptr + 2));
        printf("The value of the fourth element is %d\n", *(my_ptr + 3));
        printf("The value of the fifth element is %d\n", *(my_ptr + 4)); 
        printf("The value of the sixth element is %d\n", *(my_ptr + 5)); // This is BAD don't do this. 
    }

This can also be done using the bracket notation, think of the bracket notation as just pointer arithmetic with a different syntax.

**nullptr and Boolean Expressions**

Pointers can have a special value `nullptr`. As standard, a pointer must point to something, but sometimes we want to declare a pointer but not have it point to anything yet, for that, we assign it a value of `nullptr`. 

    int* my_ptr = nullptr;

Pointers also have an implicit conversion to a `bool` if the pointer has a value that is NOT `nullptr` it is true, if it is `nullptr` it is false. 

    #include <cstdio>

    int main(void) {
        int* my_ptr = nullptr;
        if (my_ptr) { // Checks that we are pointing to something if not, do something. 
            printf("The pointer is not null\n");
        } else {
            printf("The pointer is null\n");
        }
    }

It is common that a function will return `nullptr` if something fails, a good example of this is memory allocation. In CS50 we always had to check if `malloc()` gave us a memory or not. 

## References

References are safer than pointers, and they do not have all of the complex syntax that comes along with using pointers. References cannot be reassigned or assigned to null, which reduces the chances that bugs appear in our program. When we pass objects by reference into a function, we just treat it as it is, we don't need to use the dereference operator or the arrow operator. 

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

## Usage of Pointers and References

Pointers and references are largely interchangeable, but there are some situations where we need to use one or the other. If you sometimes change the reference types value (change what the reference type refers to) we must use a pointer. Many data structures like linked lists require that we use pointers as we need to change our pointer values. Because references cannot be reassigned, we cannot use them in these situations.

**Forward Linked Lists**

Forward liked lists are a simple data structure made up of a series of elements. Each element contains a value, and a pointer to the next element. The last element in the linked list contains a pointer with a `nullptr` value. Inserting elements into a linked list is really efficient O(1) I think, but accessing elements is O(n) as we need to iterate over the list to find the element we want. 

    #include <cstdio>

    class Node {
    public:
        Node* next = nullptr;

        void insert_after(Node* new_element) {
            new_element->next = next;
            next = new_element;
        }
        int value;
    };
    int main(void) {

        Node element_1, element_2, element_3;
        element_1.value = 1;
        element_2.value = 2;
        element_3.value = 3;

        Node* n = &element_2; 
        element_1.insert_after(n);

        n = &element_3;
        element_2.insert_after(n);

        for (Node* cursor= &element_1; cursor; cursor = cursor->next) {
            printf("The current element is %d\n", cursor->value);
        }
    }


Here what we do is create a linked in node class, this contains a pointer to the next element in a list (defaulted to `nullptr`) and a value. We then create three instances of the node class and assign them values. Using a variable `n` we get the memory location of the next element in the list and pass it to the `insert_after` function. We then set `n` to the next element in the list and pass it to the `insert_after` function again. We then iterate over the list and print the values of each element. 

The loop works by getting a pointer to the first element in the list, and iterating over the list until the pointer is null pointer. This works by checking if the cursor is true, if it is not, it is a null pointer and the loop will exit. This loop it literally just using pointers. 


••Employing References**

Pointers provide a lot of flexibility but at the expense of safety. If we do not need the flexibility of reseatability and `nullptr` then references are the reference type to use. The program below drives home that references cannot be reseated.

    #include <iostream>

    int main(void) {
        int number_1 = 42;
        int number_2 = 4242;

        int& reference = number_1;
        std::cout << "Number 1 " << number_1 << std::endl;
        std::cout << "Number 1 reference " << reference << std::endl;

        reference = number_2;

        std::cout << "Number 1 " << number_1 << std::endl;
        std::cout << "Number 1 reference " << reference << std::endl;
        std::cout << "Number  2 " << number_2 << std::endl;
    }

This program initializes two ints and then sets a reference to the first number, this reference will now continue to reference the first number no matter what, when we change the value of reference at `reference = number_2;` what we are doing is just changing the value at the memory address that the reference is addressing.


See this [stack overflow](https://stackoverflow.com/questions/334856/are-there-benefits-of-passing-by-pointer-over-passing-by-reference-in-c) explanation about references and pointers and being passed into functions.

Question:

"Lately, I have seen a number of examples that chose passing function arguments by pointers instead of passing by reference. Are there benefits to doing this?"

Example:

    func(SPRITE *x);
with a call of

    func(&mySprite);
vs.

    func(SPRITE &x);
with a call of

    func(mySprite);

Answer:

Passing by pointer

- Caller has to take the address -> not transparent
- A 0 value can be provided to mean nothing. This can be used to provide optional arguments.

Pass by reference

- Caller just passes the object -> transparent. Has to be used for operator overloading, since overloading for pointer types is not possible (pointers are builtin types). So you can't do string s = &str1 + &str2; using pointers.
- No 0 values possible -> Called function doesn't have to check for them
- Reference to const also accepts temporaries: void f(const T& t); ... f(T(a, b, c));, pointers cannot be used like that since you cannot take the address of a temporary.
- Last but not least, references are easier to use -> less chance for bugs.

Back to Cameron:

The syntax is different when passing pointer vs reference, when we pass with pointer, we use the memory address. When we pass with reference, we use the object itself, this is because referencing and dereferencing is done implicitly on references. The C++ faqs says that references are the same as the object itself, just with a different name. 

"Even though a reference is often implemented using an address in the underlying assembly language, please do not think of a reference as a funny looking pointer to an object. A reference is the object, just with another name. It is neither a pointer to the object, nor a copy of the object. It is the object. There is no C++ syntax that lets you operate on the reference itself separate from the object to which it refers"

## this Pointers

Methods are associated with classes, when we program a method, sometimes we need to access the current object that is running the method. We can access the current object using the `this` pointer. This is the equivalent of `self` in python. We can write the linked lists using the `this` keyword.

    #include <iostream>
    #include <string>

    class Node {

    public:
        Node* next;
        std::string name;

        void insert_after(Node* new_node) {
            new_node->next = this->next;
            this->next = new_node;
        }
    };

We can also use this to resolve ambiguity between members and arguments. 

    #include <iostream>
    #include <string>

    class Class1 {

    public:
        int year;

        bool set_year(int year) {
            this->year = year;
        }
    };

The year argument has the same name as the year member. Method arguments will always mask members, this means that when we are type `year` in the method, it will always reference the argument, not the year member. Using `this` allows us to access the member.

## const Correctness

The `const` keyword means that we are promising not to change the value of this variable. It is a safety method that prevents unintended modification to member variables. We will use cost in function and class definitions to specify that a variable (usually a reference or a pointer) wont be modified by that function or class.

If our code attempts to modify a const variable, the compiler will throw an error. Lets look at a few common usages of `const`.

** const Arguments**

Marking an argument as `const` prevents a function from modifying the argument. A `const` reference or pointer provides us with an efficient mechanic to pass an object into a function for *read* use only. The code below takes a `const` pointer.

    #include <iostream>
    #include <string> 

    void print_message(const std::string message) {
        std::cout << message << std::endl;
        message[0] = "E"; // Throws an error.
    }

**const methods**

Marking a method `const` means that we promise to not modify current objects state within the const method. This means that we are only reading information, not changing it. We mark a method as constant by placing the `const` keyword after the argument list, but before the method body

    class Class1 {
    private:
        int year;

    public:
        void set_year(int new_year) {
            this->year = new_year;
        }

        int get_year() const {
            return this->year;
        }
    };

When we have `const` references and pointers they cannot invoke methods that are not `const` because methods that are not `const` might modify an objects state.

    bool is_leap_year(const ClockofTheLongNow& clock) {
        if (clock.get_year() % 4 > 0) return false;
        if (clock.get_year() % 100 > 0) return true;
        if (clock.get_year() % 400 > 0) return false;
        return true;
    }

If we had not marked `get_year()` as `const` we would not be able to call it from the `is_leap_year` function.

**const Member Variables**

We can mark member variables with `const` by adding it before the members type. This means they cannot be modified after they have been initialized. 

    class Class1 {
    private:
        const int year = 2020;
    };

**Member Initializer Lists**

Member initializer lists are the primary mechanism or initing class members. To declare an initializer list, we place a colon after the argument list in a constructor then insert one or more comma-separated member initializations (a member name and a { }). These also allow us to set the values of `const` members at runtime. 

    #include <iostream>
    #include <string>

    class Class1 {
    public:
        Class1(int num, std::string name)
            : number{ num }, name{ name } {}

        void print_info() {
            std::cout << "The number of this class " << this->number << std::endl;
            std::cout << "The name of this class " << this->name << std::endl; 
        }

        const int number; // Member init lists needed here. 
        std::string name; // Not needed here but works :
    };

    int main(void) {
        Class1 this_class{ 12, "Instance 1"};
        this_class.print_info();
    }

Member init lists execute before the body of the constructor, this has 2 main advantages. 

1. It ensures validity of all members before the constructor executes, this means that we can focus on init logic instead of checking for member errors. 

2. The members init once, if we reassign members in the constructor body, we are actually assigning to the member twice.

## auto Type Deduction

C++ is a strongly typed language, this means that we are handing the complier a lot of information. The complier can also infer tpye information from context. The `auto` keyword tells the complers to infer the variable type for us.

••Initializing with auto**

    auto my_int = 42; // int
    auto my_string = "Hello"; // const char*
    auto my_string_2 = std::string("Hello"); // std::string

**auto and Reference types**

We also add `&, *, const` to auto, and their intended meanings will be fulfilled.

    auto& my_int_ref = my_int; // int&
    auto* my_int_ptr = &my_int; // int*
    const auto my_int_const = my_int; // const int

Auto makes code simpler to refactor, consider the following example. 

class Employee {
    ...
};

Employee employees[10];

class Contract {
    void add(const Employee&);
};

void form_company(Contract &contract) {
    for (const auto& employee : employees) {
        contract.add(employee);
    }
}

Whenever the type of employee changes, the for loop will work as expected. 
