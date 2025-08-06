#include <iostream>
#include <memory>

class Node {
public:
    int value;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    
    ~Node() {
        std::cout << "Nó deletado! (value: " << value << ")" << std::endl;
    }
};

int main() {
    auto node1 = std::make_shared<Node>();
    node1->value = 10;
    auto node2 = std::make_shared<Node>();
    node2->value = 20;

    node1->next = node2;
    node2->prev = node1;

    // Acessando o nó anterior de 'node2' de forma segura
    if (auto prev_node_ptr = node2->prev.lock()) {
        std::cout << "O valor do nó anterior é: " << prev_node_ptr->value << std::endl;
    }
    
    // node1 sai do escopo, o objeto é deletado.
    node1 = nullptr; 

    // Tentando acessar o nó anterior de 'node2' novamente.
    // 'lock()' irá retornar um nullptr porque o objeto foi deletado.
    if (auto prev_node_ptr = node2->prev.lock()) {
        std::cout << "O valor do nó anterior é: " << prev_node_ptr->value << std::endl;
    } else {
        std::cout << "O nó anterior foi deletado." << std::endl;
    }
    
    return 0;
}

//Neste exemplo, o weak_ptr permite que node2 referencie node1 sem impedi-lo de ser desalocado. A chamada a lock() garante que o acesso ao objeto só ocorra se ele ainda existir na memória, evitando o problema de ponteiros inválidos (dangling pointers).