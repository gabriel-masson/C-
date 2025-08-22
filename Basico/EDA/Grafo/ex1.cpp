#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

void bfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, std::vector<std::string>& rotina) {
   
    std::queue<std::string> pesquisa;
    std::vector<std::string> visited;

    for(const auto& key : rotina) {

        auto it = graph.find(key);
        std::cout << "Meu no " << key << std::endl;
        std::cout << "Visitados ";
        for(const auto& v : visited) {
            std::cout << v << " ";
        }
        std::cout << "\n--------------------------------" << std::endl;
        

        if (it != graph.end()) {
            for (const auto& neighbor : it->second) {
                // std::cout << neighbor << " ";
                if(visited.empty()){
                    std::cout << "Adicionando: "<< key << std::endl;
                    visited.push_back(key);

                } else if (std::find(visited.begin(), visited.end(), neighbor) == visited.end()) {

                    std::cout << neighbor << " Nao foi realizado" << std::endl;
                    std::cout << " Falha" << std::endl;
                    return;
                    

                } else {
                    std::cout << neighbor << " Valido" << std::endl;
                    visited.push_back(key);
                }
            }
        }
     }
     
}


int main(){
    std::unordered_map<std::string, std::vector<std::string>> graph;

    graph["acordar"] = {"acordar"};
    graph["tomar_banho"] = {"acordar"};
    graph["escovar_dentes"] = {"acordar"};
    graph["tomar_cafe"] = {"escovar_dentes"};

    std::vector<std::string> rotina1 = {"acordar", "tomar_banho", "escovar_dentes", "tomar_cafe"};//ok
    std::vector<std::string> rotina2 = {"tomar_banho", "escovar_dentes"};

    bfs(graph, rotina1);


    return 0;
}