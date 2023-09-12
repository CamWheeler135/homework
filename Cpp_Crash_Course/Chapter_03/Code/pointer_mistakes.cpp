    #include <cstdio>

    int main(void) {
        int my_array[5] = {1, 2, 3, 4, 5};
        int* my_ptr = my_array;
        printf("The value of the first element is %d\n", *my_ptr);
        printf("The value of the second element is %d\n", *(my_ptr + 1));
        printf("The value of the third element is %d\n", *(my_ptr + 2));
        printf("The value of the fourth element is %d\n", *(my_ptr + 3));
        printf("The value of the fifth element is %d\n", *(my_ptr + 4)); 
        printf("The value of the sixth element is %d\n", *(my_ptr + 5)); // This is BAD dont do this. 
    }