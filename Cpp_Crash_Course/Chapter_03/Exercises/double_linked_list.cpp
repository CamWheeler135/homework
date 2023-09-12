/*Create a doubly linked list, traverse the list forwards and backwards using two separate for loops.
  Print the name of each node.
*/


#include <iostream>
#include <string>

class Node {
public:
    Node* forward_ptr = nullptr;
    Node* backward_ptr = nullptr;
    std::string name;

    void insert_after(Node* node_ptr, std::string node_name) {
        // Dealing with the node being added.
        node_ptr->forward_ptr = this->forward_ptr; // Sets to null
        node_ptr->backward_ptr = this; // Sets the backward ptr on the next node to point at the current node.
        node_ptr->name = node_name; // Sets the name of the node.

        // Dealing with the previous node in the list
        this->forward_ptr = node_ptr; // Points at the new node that has just been added.
    }

    // We have to do this smartly to avoid losing the list.
    void insert_before(Node* node_ptr, std::string node_name) {
        // Dealing with the node being added
        node_ptr->backward_ptr = this->backward_ptr;
        node_ptr->forward_ptr = this;
        node_ptr->name = node_name;

        // Updating the values of the node already in the list.
        this->backward_ptr = node_ptr;
    }
};


int main(void) {
    Node node_1;
    Node node_2;
    Node node_3;

    Node* linked_list_start = &node_1;
    Node* linked_list_end = &node_3;

    node_1.name = "Node 1";

    Node* n = &node_2;
    node_1.insert_after(n, "Node 2");

    n = &node_3;
    node_2.insert_after(n, "Node 3");

    std::cout << "Going forward" << std::endl;

    for (Node* cursor = linked_list_start; cursor; cursor = cursor->forward_ptr) {
        std::cout << cursor->name << std::endl;
    }

    std::cout << "Going Backwards" << std::endl;

    for (Node* cursor = linked_list_end; cursor; cursor = cursor->backward_ptr) {
        std::cout << cursor->name << std::endl;
    }

    std::cout << "Inserting Node at start of Linked List" << std::endl;

    // Adding a new node at the front of the list.2
    Node node_4;
    n = &node_4;
    node_1.insert_before(n, "Node 4");
    linked_list_start = n;

    std::cout << "Going forward" << std::endl;

    for (Node* cursor = linked_list_start; cursor; cursor = cursor->forward_ptr) {
        std::cout << cursor->name << std::endl;
    }

    std::cout << "Going Backwards" << std::endl;

    for (Node* cursor = linked_list_end; cursor; cursor = cursor->backward_ptr) {
        std::cout << cursor->name << std::endl;
    }



    
}


