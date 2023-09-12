#include <iostream>
#include <string>


class Node {
public:
    Node* next_node_loc = nullptr;
    std::string nodes_name;

    void add_node_after(Node* node_to_add) {
        node_to_add->next_node_loc = next_node_loc;
        next_node_loc = node_to_add;
    }
};

int main(void) {
    
    // Create the linked list nodes.
    Node node_1;
    node_1.nodes_name = "Node 1";

    Node node_2;
    node_2.nodes_name = "Node 2";

    Node node_3;
    node_3.nodes_name = "Node 3";

    // Setting the start of the linked list. 
    Node* linked_list = &node_1;

    // Add node 2 to node 1.
    Node* n = &node_2;
    node_1.add_node_after(n);

    // Add node 3 to node 2.
    n = &node_3;
    node_2.add_node_after(n);

    for (Node* cursor = linked_list; cursor; cursor = cursor->next_node_loc) {
        std::cout << cursor->nodes_name << std::endl;
    }
}