#include <iostream>
#include "Classe.hpp"
// Nesse arquivo fazemo a implementação da classe
class Classe{
    private:
        int atributo_privado;
        void metodo_privado() const {
            std::cout << "Value of a: " << atributo_privado << std::endl;
        }
    public:
    int x;
    int y;
        Classe(int a, int b) : x(a), y(b) {
            std::cout << "Constructor called with x = " << x << ", y = " << y << std::endl;
        }
        ~Classe(){
            std::cout << "Destructor called for object with x = " << x << " and y = " << y << std::endl;
        }
        void setA(int value) {
            atributo_privado = value;
        }
        void print() const {
            metodo_privado(); // Call the private method to print 'a'
        }
};
