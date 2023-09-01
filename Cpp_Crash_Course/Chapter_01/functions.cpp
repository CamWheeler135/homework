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