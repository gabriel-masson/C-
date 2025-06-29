#include <iostream>

struct D_interna{
    int x;

};
struct D_externa{
    int y;
    D_interna d_interna; // Struct dentro de struct
};

int main() {
    D_interna d_interna;
    d_interna.x = 10;

    D_externa d_externa;
    d_externa.y = 20;
    d_externa.d_interna = d_interna; // Atribuindo a struct D1 dentro de D2

    std::cout << "d_interna.x: " << d_interna.x << std::endl; // Imprime o valor de x da struct d_interna
    std::cout << "d_externa.y: " << d_externa.y << std::endl; // Imprime o valor de y da struct d_externa
    std::cout << "d_externa.d_interna.x: " << d_externa.d_interna.x << std::endl; // Imprime o valor de x da struct D1 dentro de D2

    return 0;
}