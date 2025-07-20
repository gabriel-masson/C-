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

class Queue{
    Node* first;
    Node* last;
    // Node* current;
    
    public:
        Queue(): first(nullptr), last(nullptr){}
        ~Queue(){}

        void insert(int value){
            std::cout << "Inserting value: " << value << std::endl;
            Node* newNode = new Node(value);
            if(first == nullptr){
                first = newNode;
                last = newNode;
            } else{
                last->next = newNode;
                newNode->prev = last; 
                last = newNode;

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

    void dequeue(){

        if(first != nullptr) {
            //pegar o primeiro elemento
            Node* temp = first;
            first = first->next;
            delete temp;
            temp = nullptr;
            first->prev = nullptr; // Update the new first node's prev pointer
        }else{
            std::cout << "Queue is empty, nothing to dequeue." << std::endl;
        }

        

    }
};


int main() {
    std::cout << "Linked List Example" << std::endl;
    Queue myList;
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    myList.print_decrescente();
    myList.print_crecente();

    myList.dequeue();
    myList.print_crecente();

    return 0;
}