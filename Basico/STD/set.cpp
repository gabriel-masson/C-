#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<string>
#include<set>
using namespace std::string_literals;
//a principal diferença entre set e unordered_set é que o set é ordenado, enquanto o unordered_set não é.
// a diferença entre set e map é que o set armazena apenas valores únicos, enquanto o map armazena pares de chave-valor.
//a diferença entre set e vector é que o set não permite elementos duplicados e é ordenado, enquanto o vector permite duplicatas e mantém a ordem de inserção.
//a diferença entre set e array é que o set é dinâmico e não permite duplicatas, enquanto o array tem tamanho fixo e pode conter duplicatas.
int main(){
    std::set<std::string> mySet;
    std::vector<std::string> elements = {"apple", "banana", "cherry", "apple"};

    // Inserting elements into the set
    for (const auto& elem : elements) {
        mySet.insert(elem);
    }

    // Displaying the set contents
    std::cout << "Set contents:" << std::endl;
    for (const auto& elem : mySet) {
        std::cout << elem << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    mySet.insert("kiwi");
    mySet.insert("orange");
    mySet.insert("banana"); // Duplicate, will not be added
        for (const auto& elem : mySet) {
        std::cout << elem << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    // Checking if an element exists in the set
    std::string searchElement = "banana";


    if (mySet.find(searchElement) != mySet.end()) {
        std::cout << searchElement << " is in the set." << std::endl;
    } else {
        std::cout << searchElement << " is not in the set." << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}