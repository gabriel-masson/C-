#include <iostream>
#include<vector>

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Sobrecarga do operador +
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Método para imprimir
    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

class Vector1 {
    private:
        float x, y,z;
    public:
        Vector1(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

        // Sobrecarga do operador +
        Vector1 operator + (const Vector1& v) {
            return Vector1(x + v.x, y + v.y, z + v.z);
        }
};
class Vector2 {
    
    public:
    std::vector<int> x;
        Vector2(std::vector<int> x) : x(x) {}

        // Sobrecarga do operador +
        Vector2 operator + (const Vector2& v) {
            if (x.size() != v.x.size()) {
                throw std::invalid_argument("Vectors must be of the same size");
            }else {
                std::vector<int> result;
                for (size_t i = 0; i < x.size(); ++i) {
                    result.push_back(x[i] + v.x[i]);
                }
                return Vector2(result);
            }
        }
};

int main() {
    Complex c1(2, 3), c2(1, 4);
    Complex c3 = c1 + c2;
    c3.print();  // Saída: 3 + 7i

    Vector2 v1({1, 2, 3}), v2({4, 5, 6});
    Vector2 v3 = v1 + v2;
    std::cout << "Vector addition result: ";
    for (const auto& elem : v3.x) {
        std::cout << elem << " ";
    }
}
