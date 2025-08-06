#include <iostream>
#include <array>
#include <string>

void insert(std::string str,  std::array<std::string, 5> &arr) {

    int size_string = str.size();
    std::cout << "Inserting: " << str << " at index " << size_string << std::endl;
    arr[size_string] = str; 

}

int main() {
    std::array<std::string, 5> arr;
    std::string str = "";
    std::string str1 = "A";
    std::string str2 = "AB";
    std::string str3 = "ABC";
    std::string str4 = "ABCD";

    insert(str, arr);
    insert(str1, arr);
    insert(str2, arr);
    insert(str3, arr);
    insert(str4, arr);




    // Iterating through the array
    std::cout << "Array elements: ";
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}