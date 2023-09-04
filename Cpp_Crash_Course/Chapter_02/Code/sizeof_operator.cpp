#include <cstdio>
#include <iterator>

int main(void) {
    int my_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int num_of_values_size_of = sizeof(my_array) / sizeof(my_array[0]); // Access the first element in the array. 
    printf("%d\n", num_of_values_size_of);

    int num_of_values_size = std::size(my_array);
    printf("%d\n", num_of_values_size);



}