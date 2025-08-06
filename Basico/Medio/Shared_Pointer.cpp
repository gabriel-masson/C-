#include <iostream>
#include <memory>
#include <map>
#include <string>

class Texture {
public:
    int id = 0;
    Texture(const std::string& filename) {
        std::cout << "Carregando textura de: " << filename << std::endl;
        id++;
    }
    ~Texture() {
        std::cout << "Textura liberada da memoria." << std::endl;
    }
    void bind() {
        std::cout << "Meu id: " << id << std::endl;
    }
};

std::map<std::string, std::shared_ptr<Texture>> textureCache;

std::shared_ptr<Texture> getTexture(const std::string& filename) {
    if (textureCache.find(filename) == textureCache.end()) {
        textureCache[filename] = std::make_shared<Texture>(filename);
    }
    return textureCache[filename];
}

int main() {
    // Scene 1 precisa da textura
    std::shared_ptr<Texture> scene1_texture = getTexture("montanha.png");
    std::cout << "Endereco de memoria: " << &scene1_texture << std::endl;
    // Scene 2 também precisa da mesma textura
    std::shared_ptr<Texture> scene2_texture = getTexture("montanha.png");  
    std::cout << "Endereco de memoria: " << &scene2_texture << std::endl;
    
    std::shared_ptr<Texture> scene3_texture = getTexture("carro.png");
    std::cout << "Endereco de memoria: " << &scene3_texture << std::endl;
    
    // Quando 'scene1_texture' sai do escopo, a contagem de referências diminui,
    // mas a memória não é liberada porque 'scene2_texture' ainda a está usando.
    // A memória será liberada quando 'scene2_texture' também sair do escopo.
    return 0;
}