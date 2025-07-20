#include <iostream>
class Teste {
    public:
        int x;
        int y;
        Teste(int a, int b) : x(a), y(b){};

        void print() const {
            std::cout << "Ola mundo" << y << std::endl;
        }
};

void funcao(Teste t) {
    t.x = 99; 
    t.y = 88;
    std::cout << "Valor de x dentro da funcao: " << t.x << std::endl;
    std::cout << "Valor de y dentro da funcao: " << t.y << std::endl;
};
void funcao2(Teste* t) {
    t->x = 99; 
    t->y = 88;
    std::cout << "Valor de x dentro da funcao: " << t->x << std::endl;
    std::cout << "Valor de y dentro da funcao: " << t->y << std::endl;
};

int main() {
    Teste* t = new Teste(10, 20); //
    Teste t2(10, 20);
    std::cout << "<Memory Stack> Objeto criado com x = " << t2 .x << " e y = " << t2.y << std::endl;
    funcao(t2);
    std::cout << "Pos funcao:" << t2.y << std::endl;
    std::cout << "Valor de x: " << t2.x << std::endl;
    std::cout << "Valor de y: " << t2.y << std::endl;
    
    std::cout << "<Memory Heap> Objeto criado com x = " << t->x << " e y = " << t->y << std::endl;
    funcao2(t);
    std::cout << "Pos funcao2:" << std::endl;
    std::cout << "Valor de x: " << t->x << std::endl;
    std::cout << "Valor de y: " << t->y << std::endl;

    // t->print(); // Chamada do método print

    return 0;
}