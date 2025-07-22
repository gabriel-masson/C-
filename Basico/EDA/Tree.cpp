#include <iostream>

class Node{
public:
    int value;
    Node* left;
    Node* right;
    int n;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}

};

class BST{
    public:
        Node* root;
        BST() : root(nullptr) {}

        int size() const {
            return size(root);
        }
    private:
        int size(Node* node) const {
            if (node == nullptr) {
                return 0;
            }
            return node->n;
        }

};
int main(){
    std::cout << "Começando uma arvore." << std::endl;
}