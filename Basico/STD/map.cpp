#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<string>
using namespace std::string_literals;

int main(){

    //map é um container associativo que armazena elementos formados por pares de chave-valor.
    //As chaves são únicas e ordenadas, e cada chave está associada a um valor.
    //A inserção de elementos em um map é feita através da chave, e se a chave já existir, o valor associado é atualizado.
    //A busca por um elemento é feita através da chave, e a complexidade de tempo é O(log n) para inserção, busca e remoção.
    //Map é implementado como uma árvore binária balanceada, garantindo que os elementos estejam sempre ordenados.
    //Map é útil quando você precisa de uma estrutura de dados que permita associar chaves a valores e realizar buscas eficientes.
    //Map é um container que permite armazenar pares de chave-valor, onde as chaves são únicas e ordenadas.
    std::map<std::string, int> myMap;
    std::vector<std::string> keys = {"banana", "yacute", "cherry", "beterraba"};
    std::vector<int> values = {1, 2, 3,4};

    // Inserting elements into the map
    for (size_t i = 0; i < keys.size(); ++i) {
        myMap[keys[i]] = values[i];
    }
    // Displaying the map contents
    std::cout << "Map contents:" << std::endl;
    //forma antiga
    for(const auto& pair: myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    //mais atual c++17+
    std::cout << "-------------------------------------------" << std::endl;
    for(auto const& [keys, value]: myMap) {
        std::cout << keys << ": " << value << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    
    std::map<std::string, int> myMap2;
    std::vector<std::string> keys2 = {"b2", "b2", "cherry", "beterraba"};
    std::vector<int> values2 = {1, 2, 2,4};

    
    // Inserting elements into the map
    for (size_t i = 0; i < keys2.size(); ++i) {
        //não inserir itens com a mesma chave
        myMap2[keys2[i]] = values2[i];
    }

    for(auto const& [key, value] : myMap2) {
        std::cout << key << ": " << value << std::endl;
    }



    return 0;
}