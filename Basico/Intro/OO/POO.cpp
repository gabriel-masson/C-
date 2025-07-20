#include <iostream>
#include "Classe.hpp"
class Teste{
    private:
        int a;
        void print_interno() const {
            std::cout << "Value of a: " << a << std::endl;
        }
    public:
        int x;
        int y;
        Teste(int a, int b) : x(a), y(b) {
            printf("Constructor called with x = %d, y = %d\n", x, y);
        }
        ~Teste(){
            std::cout << "Destructor called for object with x = " << x << " and y = " << y << std::endl;
        }

        void setA(int value) {
            a = value;
        }
        int getA() const {
            return a;
        }
        void print() const {
            print_interno(); // Call the private method to print 'a'
        }


};

int main() {
    Teste t(10, 20); 
    std::cout << "<Memory Stack> Object created with x = " << t.x << " and y = " << t.y << std::endl;

    Teste* p = new Teste(30, 40);
    std::cout << "<Memory Heap> Object created with x = " << p->x << " and y = " << p->y << std::endl;

    delete p; // Free the memory allocated on the heap
    std::cout << "<Memory Heap> Object deleted." << std::endl;

    // Demonstrating the use of setA and getA methods
    t.setA(100);
    t.x = 50; // Directly accessing public member x
    std::cout << "Value of a in object t: " << t.getA() << std::endl;
    std::cout << "Value of x in object t: " << t.x << std::endl;

    t.print(); 

    Classe c(5, 15);
    c.setA(200);
    c.print(); 


    return 0;
}