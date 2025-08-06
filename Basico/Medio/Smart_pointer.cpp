#include <iostream>
#include <memory>

int main() {
    // Cria um unique_ptr para um inteiro
    // make_unique é a forma recomendada de criar unique_ptr
    //O unique_ptr possui o dominio de um unico endereço de memoria, ou seja, não pode ser copiado. A escolha dele se dá pela ciclo de vida do objeto, quue ao deixar de existir, o objeto é destruído.
    std::unique_ptr<int> ptr = std::make_unique<int>(20);

    return 0;
}