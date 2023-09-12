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

