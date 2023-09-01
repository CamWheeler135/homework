#include <cstdio>

int sum(int x, int y) {
    return x + y;
}

int main(void) {
    int x = 34;
    int y = 6;

    int total = sum(x, y);

    printf("The sum of %d and %d ----> %d\n", x, y, total);
}