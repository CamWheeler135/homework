#include <cstdio>

int main(void) {
    int my_array[] = {1, 2, 3, 4, 5};

    printf("Done using a for loop.\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", my_array[i]);
    }

    printf("Done using a range-based for-loop.\n");
    for (int x : my_array) {
        printf("%d\n", x);
    }

    printf("Program Complete.\n");
    return 0;

}