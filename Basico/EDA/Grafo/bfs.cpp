#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
//BFS é um acronimo para "Breadth-First Search" (Busca em Largura), um algoritmo de busca em grafos que explora todos os vizinhos de um nó antes de passar para o próximo nível.
void bfs(const std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::string seek = "_M"; 
    std::queue<std::string> q;
    std::queue<std::string> pesquisa;

    for(const auto& pair : graph) {
        q.push(pair.first);
    }
    //Liste todos os itens em q
    std::cout << "Items in queue: ";
    while (!q.empty()) {

        std::string current = q.front();

        std::cout << q.front() << " - " << std::endl;
        if ( current.size() >= seek.size() && (current.substr(current.size() - seek.size())) == seek) {
            std::cout << q.front() << " Achou" << std::endl;
            break;
        }
        else{
            std::cout << "Nao achou" << std::endl;
            std::queue<std::string> pesquisa;
            // .at(current) retorna uma lista de vizinhos (adjacentes) do nó current.
            for(const auto& neighbor : graph.at(current)) {
                pesquisa.push(neighbor);
            }
            // Imprime os vizinhos do nó atual
            std::cout << "Vizinhos de " << current << ": ";
            while (!pesquisa.empty()) {

                std::string current = pesquisa.front();

                if ( current.size() >= seek.size() && (current.substr(current.size() - seek.size())) == seek) {
                    std::cout << q.front() << " Achou" << std::endl;
                    break;
                }

                pesquisa.pop();
            }
           
        }
        q.pop();
    }

}

int main() {
    std::cout << "Hello, Graph!" << std::endl;

    // Example graph represented as an adjacency list
    std::unordered_map<std::string, std::vector<std::string>> graph;

    graph["A"] = {"B", "C_M"};
    graph["B"] = {"A", "D", "E"};
    graph["C"] = {"A", "F"};
    graph["D"] = {"B"};
    graph["F"] = {};
    graph["E"] = {"B", "F"};

    // for (const auto& pair : graph) {
    //     std::cout << pair.first << " -> ";
    //     for (const auto& neighbor : pair.second) {
    //         std::cout << neighbor << " ";
    //     }
    //     std::cout << std::endl;
    // }
    bfs(graph);



    return 0;
}