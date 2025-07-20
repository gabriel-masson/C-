#include <iostream>
#include "Classe.hpp"
// Lembre se de compilar os dois arquivos juntos, por exemplo:
// g++ Classe.cpp POO.cpp -o POO
int main() {
    Classe c(5, 15);
    c.setA(200);
    c.print(); // Call the print method to display the private attribute

    // Demonstrating the use of public members
    std::cout << "Public member x: " << c.x << std::endl;
    std::cout << "Public member y: " << c.y << std::endl;

    return 0;
}