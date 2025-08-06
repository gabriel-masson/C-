-----

### Smart Pointers em C++: Uma Introdução

**Smart pointers** (ponteiros inteligentes) são objetos que agem como ponteiros, mas com uma grande diferença: eles gerenciam a memória de forma automática. Eles são uma ferramenta fundamental em C++ moderno para prevenir vazamentos de memória e outros problemas relacionados ao gerenciamento manual de recursos.

Imagine que você tem um `int*` que aponta para um `int` alocado dinamicamente com `new`. Se você esquecer de chamar `delete` no final, a memória alocada para esse `int` nunca será liberada. É aqui que os smart pointers entram. Eles garantem que, quando o objeto smart pointer sai do escopo, a memória para a qual ele aponta é automaticamente liberada, chamando o `delete` por você.

Existem três tipos principais de smart pointers na biblioteca padrão de C++ (`<memory>`):

-----

### 1\. `std::unique_ptr`

O `std::unique_ptr` é um ponteiro que **detém a propriedade exclusiva** do objeto para o qual aponta. Isso significa que apenas um `unique_ptr` pode apontar para um objeto específico em um determinado momento. Se você tentar copiar um `unique_ptr`, o compilador irá gerar um erro.

**Principais características:**

  * **Propriedade exclusiva:** Apenas um `unique_ptr` pode ser o "dono" do objeto.
  * **Sem custo de tempo de execução:** Ele é tão eficiente quanto um ponteiro bruto (`raw pointer`).
  * **Sintaxe:** Use `std::make_unique` para criar um `unique_ptr` de forma segura e eficiente.

**Exemplo de uso:**

```cpp
#include <iostream>
#include <memory> // Inclua esta biblioteca

int main() {
    // Cria um unique_ptr para um inteiro
    // make_unique é a forma recomendada de criar unique_ptr
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    
    // Podemos acessar o valor do mesmo jeito que um ponteiro comum
    std::cout << "Valor: " << *ptr << std::endl;

    // A memória para o inteiro '10' é liberada automaticamente 
    // quando 'ptr' sai do escopo (final da função main)
    return 0;
} 
```

**Quando usar:** Use `std::unique_ptr` sempre que você precisar de um ponteiro que seja o único responsável por gerenciar a vida útil do objeto. Ele é a escolha mais comum para a maioria das situações.

-----

### 2\. `std::shared_ptr`

O `std::shared_ptr` é um ponteiro que **compartilha a propriedade** do objeto. Vários `shared_ptr` podem apontar para o mesmo objeto. Ele mantém uma contagem de referências (`reference count`) para saber quantos `shared_ptr` estão apontando para o objeto. A memória do objeto é liberada apenas quando a contagem de referências chega a zero.

**Principais características:**

  * **Propriedade compartilhada:** Múltiplos `shared_ptr` podem "ser donos" do mesmo objeto.
  * **Contagem de referências:** A memória é liberada quando a contagem chega a zero.
  * **Custo de tempo de execução:** Há uma pequena sobrecarga para manter a contagem de referências.
  * **Sintaxe:** Use `std::make_shared` para criar um `shared_ptr`.

**Exemplo de uso:**

```cpp
#include <iostream>
#include <memory>

int main() {
    // Cria um shared_ptr para um inteiro
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
    
    // Cria outro shared_ptr que aponta para o mesmo objeto
    std::shared_ptr<int> ptr2 = ptr1;
    
    // A contagem de referências é 2 neste momento
    std::cout << "Contagem de referências: " << ptr1.use_count() << std::endl;

    // Quando 'ptr2' sai do escopo, a contagem diminui para 1.
    // Quando 'ptr1' sai do escopo, a contagem chega a 0 e a memória é liberada.
    return 0;
}
```

**Quando usar:** Use `std::shared_ptr` quando você precisa que a vida útil de um objeto seja gerenciada por múltiplos "donos" em diferentes partes do seu código.

-----

### 3\. `std::weak_ptr`

O `std::weak_ptr` é um ponteiro que **observa** um objeto gerenciado por um `std::shared_ptr`, mas **não compartilha a propriedade**. Ele não aumenta a contagem de referências. Ele é usado principalmente para evitar ciclos de referência circulares, que podem causar vazamentos de memória quando se usa `shared_ptr`.

**Principais características:**

  * **Não detém a propriedade:** Não afeta a contagem de referências do `shared_ptr`.
  * **Não pode ser acessado diretamente:** Você precisa "promovê-lo" para um `shared_ptr` temporário para poder acessar o objeto. Isso é feito usando o método `lock()`.
  * **Segurança:** O método `lock()` retorna um `shared_ptr` válido se o objeto ainda existir, ou um `nullptr` se o objeto já tiver sido liberado.

**Exemplo de uso:**

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared = std::make_shared<int>(30);
    std::weak_ptr<int> weak = shared; // weak agora observa o 'shared'

    if (auto temp_shared = weak.lock()) { // Tenta obter um shared_ptr
        std::cout << "Objeto ainda existe. Valor: " << *temp_shared << std::endl;
    } else {
        std::cout << "Objeto foi liberado." << std::endl;
    }

    shared.reset(); // Libera o objeto apontado por 'shared'

    if (auto temp_shared = weak.lock()) {
        std::cout << "Objeto ainda existe." << std::endl;
    } else {
        std::cout << "Objeto foi liberado." << std::endl; // Esta linha será impressa
    }
    
    return 0;
}
```

**Quando usar:** Use `std::weak_ptr` para quebrar ciclos de referência em estruturas de dados (como listas duplamente encadeadas ou árvores) que usam `std::shared_ptr`.

-----

### Resumo e Boas Práticas

| Tipo | Uso principal | Contagem de referências | Custo de tempo de execução |
| :--- | :--- | :--- | :--- |
| `std::unique_ptr` | Propriedade exclusiva | Não possui | Quase zero |
| `std::shared_ptr` | Propriedade compartilhada | Sim | Pequena sobrecarga |
| `std::weak_ptr` | Observar, evitar ciclos | Não afeta | Pequena sobrecarga |

**Sempre use smart pointers no lugar de ponteiros brutos (`new` e `delete`) para evitar problemas de gerenciamento de memória.** A maioria dos códigos modernos em C++ usa `std::unique_ptr` como padrão, e só recorre a `std::shared_ptr` quando a propriedade do objeto precisa ser explicitamente compartilhada.

Um `std::shared_ptr` é útil quando a propriedade de um objeto precisa ser compartilhada e não é claro qual parte do código será a última a usar o objeto. Aqui estão alguns exemplos comuns:

### 1\. Cache de Recursos

Imagine que você tem um cache que armazena objetos caros de serem criados, como texturas de jogos ou dados de arquivos. Várias partes do seu programa podem precisar acessar a mesma textura.

  * **Problema:** Se você usar `unique_ptr`, cada parte teria sua própria cópia da textura, o que desperdiçaria memória. Se você usar ponteiros brutos, seria difícil saber quando a última parte parou de usar a textura e a memória pode ser liberada.
  * **Solução:** Use `std::shared_ptr`. Quando a primeira parte do código solicita a textura, um `shared_ptr` é criado e a textura é carregada na memória. A contagem de referências é 1. Quando outra parte do código solicita a mesma textura, o cache retorna uma cópia do `shared_ptr`, e a contagem de referências aumenta para 2. A memória da textura só será liberada quando ambas as partes pararem de usá-la, ou seja, quando a contagem de referências voltar a zero.

<!-- end list -->

```cpp
#include <iostream>
#include <memory>
#include <map>
#include <string>

class Texture {
public:
    Texture(const std::string& filename) {
        std::cout << "Carregando textura de: " << filename << std::endl;
    }
    ~Texture() {
        std::cout << "Textura liberada da memória." << std::endl;
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
    std::cout << "Contagem de referências para a textura da montanha: " << scene1_texture.use_count() << std::endl;

    // Scene 2 também precisa da mesma textura
    std::shared_ptr<Texture> scene2_texture = getTexture("montanha.png");
    std::cout << "Contagem de referências para a textura da montanha: " << scene1_texture.use_count() << std::endl;
    
    // Quando 'scene1_texture' sai do escopo, a contagem de referências diminui,
    // mas a memória não é liberada porque 'scene2_texture' ainda a está usando.
    // A memória será liberada quando 'scene2_texture' também sair do escopo.
    return 0;
}
```

### 2\. Padrão de Projeto "Observer" (Observador)

No padrão "Observer", um objeto (`Subject`) notifica outros objetos (`Observers`) sobre mudanças de estado. Os observadores precisam de uma forma de acessar o `Subject`.

  * **Problema:** Se o `Subject` for deletado enquanto os `Observers` ainda o estiverem referenciando, os `Observers` terão ponteiros inválidos (`dangling pointers`), o que pode levar a falhas no programa.
  * **Solução:** O `Subject` pode ser mantido por um `shared_ptr`. Os `Observers` podem armazenar um `weak_ptr` para o `Subject`. O `weak_ptr` permite que eles verifiquem se o `Subject` ainda existe sem impedir que ele seja deletado. Se o `Subject` for destruído, os `weak_ptr`s se tornarão inválidos, e os `Observers` poderão saber que não podem mais acessá-lo.

### 3\. Factory de Objetos

Uma `factory` é uma função ou classe que cria e retorna objetos. Se a fábrica precisa garantir que múltiplos componentes possam usar um objeto recém-criado, mas o último componente que o usar será o responsável por liberar a memória, `shared_ptr` é uma excelente escolha.

  * **Problema:** A `factory` pode não saber quem vai usar o objeto por último.
  * **Solução:** A `factory` retorna um `shared_ptr` para o novo objeto. Qualquer parte do código que receba esse ponteiro se torna um "dono" do objeto. Quando todos os "donos" terminarem de usá-lo e o `shared_ptr` sair do escopo, o objeto será automaticamente deletado.

Em todos esses casos, a principal característica é que não há um único "dono" claro para o objeto. A responsabilidade de gerenciamento de memória é compartilhada, e o `std::shared_ptr` lida com isso de forma segura e automática.