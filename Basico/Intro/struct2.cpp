#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

struct Data{
    int idade;
    char nome[50];
    int *ponteiro;
    int *p = new int; 
};

int main() {
    Data pessoa;
    pessoa.idade = 30;
    strcpy(pessoa.nome, "Iris");
    pessoa.ponteiro = new int; // Ante de inciar um ponteiro em uma estrutura, é necessário alocar memória dinamicamente.
    *(pessoa.ponteiro) = 100; // Atribuindo um valor
    *(pessoa.p) = 200; // Atribuindo um valor ao ponteiro p, que é inicializado como nullptr


    std::cout << "Nome: " << pessoa.nome << std::endl;
    std::cout << "Idade: " << pessoa.idade << std::endl;
    std::cout << "Valor do ponteiro: " << *(pessoa.ponteiro) << std::endl;
    std::cout << "Valor do ponteiro p: " << *(pessoa.p) << std::endl; 


    return 0;
}