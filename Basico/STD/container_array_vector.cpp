#include<iostream>
#include<vector>
#include<array>

int main(){
    std::array<int,3> arr = {1, 2, 3};
    arr[0] = 10; // Modifying the first element
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Array element at index " << i << ": " << arr[i] << std::endl;
    }
    std::array<int, 3> arr2;
    arr2.fill(0); // Filling the array with zeros
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << "Array element at index " << i << ": " << arr2[i] << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::vector<int> vec;

    for(int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }
    std::cout << "Vector elements: ";
    for(const auto& elem : vec) {
        std::cout << elem << " ";
    }


    return 0;
}