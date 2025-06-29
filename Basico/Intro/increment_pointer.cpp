#include <iostream>

int main() {
    
    int* array = new int[5];
    std::cout << "Value at incremented pointer: " << &array << std::endl;
    ++array;
    // Incrementing the pointer to point to the next integer in the array
    std::cout << "Value at incremented pointer: " << &array << std::endl;


    return 0;
}