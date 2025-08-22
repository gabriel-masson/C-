#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

std::string min_node(const std::unordered_map<std::string, int>& cost,
    const std::vector<std::string>& visited) {
    
    std::string min_node;
    int min_cost = INT_MAX;

    for (const auto& pair : cost) {
        if(min_cost > pair.second && std::find(visited.begin(), visited.end(), pair.first) == visited.end()) {
            min_cost = pair.second;
            min_node = pair.first;
        }
    }
    // std::cout << "Min Node: " << min_node << ", Min Cost: " << min_cost << std::endl;
    return min_node;
}
void dijkstra(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& graph,
    std::unordered_map<std::string, int>& cost,
    std::unordered_map<std::string, std::string>& father) {


    std::cout << "Dijkstra Algorithm" << std::endl;
    std::vector<std::string> visited;
    
    std::string node = min_node(cost, visited);
    while (!node.empty()) {
        int node_cost = cost[node];
        const auto& neighbors = graph.at(node);

        for(const auto& k : neighbors) {
            // std::cout << "Neighbor: " << k.first << ", Edge Cost: " << k.second << std::endl;
            int new_cost = node_cost + k.second;
            if(new_cost < cost[k.first]) {
                cost[k.first] = new_cost;
                father[k.first] = node;
            }
        }
        visited.push_back(node);
        node = min_node(cost, visited);
    }

    for(const auto& pair : cost) {
        std::cout << "Cost to " << pair.first << ": " << pair.second << std::endl;
        
    }

    for(const auto& pair : father) {
        std::cout << "Father of " << pair.first << ": " << pair.second << std::endl;
    }

}

int main() {
    std::cout << "Hello, Graph!" << std::endl;

    // Example graph represented as an adjacency list
    std::unordered_map<std::string, std::unordered_map<std::string, int>> graph;
    std::unordered_map<std::string, int> cost;
    std::unordered_map<std::string, std::string> father;


    graph["inicio"] = { { "A", 6 }, { "B", 2 }  };
    graph["A"] = { { "fim", 1 } };
    graph["B"] = { { "A", 3 }, { "fim", 5 } };
    graph["fim"] = {};

    cost["A"] = 6;
    cost["B"] = 2;
    cost["fim"] = INT_MAX;

    father["A"] = "inicio";
    father["B"] = "inicio";
    father["fim"] = "";

    dijkstra(graph, cost, father);

    return 0;
}