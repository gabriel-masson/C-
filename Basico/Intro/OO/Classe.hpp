#ifndef CLASSE_HPP
#define CLASSE_HPP
// Aqui fazemos apenas a delcaração da função, ou seja, não implementamos o código dela.

class Classe{
    private:
        int atributo_privado;
        void metodo_privado() const;
    public:
    int x;
    int y;
        Classe(int a, int b);
        ~Classe();
        void setA(int value);
        void print() const;
};

#endif
