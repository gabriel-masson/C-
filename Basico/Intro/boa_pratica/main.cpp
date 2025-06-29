#include <iostream>
#include "a.hpp"
int main() {
    // Declaração de variáveis
    int a = 5;
    int b = 10;

    // Atribuição de valores
    int resultado = soma(a, b);

    // Impressão do resultado
    std::cout << "A soma de " << a << " e " << b << " eh: " << resultado << std::endl;

    return 0;
}