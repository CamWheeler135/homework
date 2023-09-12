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

