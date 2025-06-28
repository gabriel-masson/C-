#include <iostream>
// #include "function.h" // Assuming functions.h is in the same directory

namespace A {
    struct X {};   
    void myFunction(X) {
        std::cout << "This is a function from namespace A." << std::endl;
    }
}
enum class Color { 
    Red = 1, 
    Green = 2, 
    Blue = 3
}; // Enum class for colors
int main() {
    // A::X a;
    // myFunction(a); // Call the function from namespace A
    // Color x = Color::Red; // Using the enum class
    // std::cout << "Color value: " << static_cast<int>(x) << std::endl; // Output the enum value
    char name[50]; // Declare a character array to hold the name
    std::cout << "Say your name: " << std::endl; // Print a message to the console
  
    std::cin.getline(name, 50); // Read a line of input into the character array
    std::cout << "Hello, " << name << "!" << std::endl; // Greet the user with their name


    return 0;
}

