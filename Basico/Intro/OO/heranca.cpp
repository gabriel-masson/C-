#include <iostream>

class Heranca{
    public:
        int x;
        int y;

        Heranca(int a, int b) : x(a), y(b) {
            std::cout << "Construtor chamado com x = " << x << " e y = " << y << std::endl;
        }

        ~Heranca() {
            std::cout << "Destrutor da heranca"<< std::endl;
        }

        void print() const {
            std::cout << "chamada da funcao print" << std::endl;
        }

        virtual void print_sobreposto() const {
            std::cout << "Print da classe pai" << std::endl;
        }

};
class Pai: public Heranca {
    public:
        int z;

        Pai(int a, int b, int c) : Heranca(a, b), z(c) {
            std::cout << "PApai nasceu"<< std::endl;
        }

        ~Pai() {
            std::cout << "Destrutor da classe Pai chamado para objeto com z = " << z << std::endl;
        }

        void print() const {
            Heranca::print(); // Chama o método print da classe base
            std::cout << "Valor de z: " << z << std::endl;
        }
        void print_sobreposto() const override{
            std::cout << "Print diretamente do filho "<< std::endl; // Sobrescreve o método da classe base
        }
};

int main() {
    Heranca* h = new Heranca(10, 20);
    h->print();
    h->print_sobreposto();
    delete h;
    h->print(); 
    Pai p(30, 40, 50);
    p.print();
    p.print_sobreposto();

    return 0;
}