#include <cstdio>

int absolute(int x) {
    if (x > 0) {
        return x;
    }
    else if (x < 0)
    {
        return x * -1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int y = -20;
    int z = 1;
    int c = 30;

    y = absolute(y);
    z = absolute(z);
    c = absolute(c);

    printf("The value of y --> %d\n", y);
    printf("The value of z --> %d\n", z);
    printf("The value of c --> %d\n", c);
}