#include<iostream>
#include<vector>
#include<array>
#include<map>
#include<string>
#include<set>
using namespace std::string_literals;

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