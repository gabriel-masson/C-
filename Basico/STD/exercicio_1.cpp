#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>

#include <string>
#include <unordered_set>
#include <set>
using namespace std::string_literals;

int main() {
    std::unordered_map<std::string, std::map<std::string, int>> storage;
    std::map<std::string, int> item;

    std::vector<std::string> items = {"Book", "Smatphone", "Computer"};

    std::vector<std::string> brands_book = {"Martin Claret", "editora 34", "Peguin"};
    std::vector<std::string> brands_smartphone = {"Iphone", "Xiaomi", "Motorola"};
    std::vector<std::string> brands_computer = {"Acer", "Dell"};

    std::vector<std::vector<std::string>> brands = {brands_book, brands_smartphone, brands_computer};

    for(int i = 0; i < items.size(); ++i) {
        for(const auto& brand : brands[i]) {
            storage[items[i]][brand] = 0; // Initialize quantity to 0
        }
    }

   //showing the storage
    for(const auto& [item_name, brands_map] : storage) {
        std::cout << "Item: " << item_name << std::endl;
        for(const auto& [brand_name, quantity] : brands_map) {
            std::cout << "  Brand: " << brand_name << ", Quantity: " << quantity << std::endl;
        }
    }
    return 0;
}