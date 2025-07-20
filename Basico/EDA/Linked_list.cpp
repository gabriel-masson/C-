#include <iostream>

class Node {
    public:
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int val) : value(val) {
            // std::cout << "Node created with value: " << value << std::endl;
        }
        ~Node() {
            std::cout << "Node with value " << value << " destroyed." << std::endl;
        }
};

class Linked_list{
    Node* first;
    Node* last;
    // Node* current;
    
public:
    Linked_list(): first(nullptr), last(nullptr){}
    ~Linked_list(){}

    void insert(int value){
        std::cout << "Inserting value: " << value << std::endl;
        Node* newNode = new Node(value);
        if(first == nullptr){
            first = newNode;
            last = newNode;
            // current = newNode;
            // std::cout << "First node created." << std::endl;
        } else{
            last->next = newNode;
            newNode->prev = last; 
            last = newNode;
            // current = newNode;
            // std::cout << "New node added to the end of the list." << std::endl;
        }
    }

    void print_decrescente() const {
        Node* current = last;
        while(current != nullptr) {
            std::cout << current->value << " -> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
    void print_crecente() const {
        Node* current = first;
        while(current != nullptr) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};


int main() {
    std::cout << "Linked List Example" << std::endl;
    Linked_list myList;
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    myList.print_decrescente();
    myList.print_crecente();

    return 0;
}