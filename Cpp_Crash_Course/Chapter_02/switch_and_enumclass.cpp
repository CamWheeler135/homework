#include <cstdio>

enum class Animals {
    Dog,
    Cat,
    Horse,
    Duck, 
};


int main(void) {
    Animals Kevin = Animals::Duck;

    switch(Kevin) {
        case Animals::Dog: {
            printf("Kevin is a Dog\n");
            break;
        }
        case Animals::Cat: {
            printf("Kevin is a Cat\n");
            break;
        }
        case Animals::Horse: {
            printf("Kevin is a Horse\n");
            break;
        }
        case Animals::Duck: {
            printf("Kevin is a Duck\n");
            break;
        }
        default: {
            printf("No animal found\n");
        }
    }
}