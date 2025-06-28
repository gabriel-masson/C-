# 📚 Trilha de Estudos em C++ (Prática Semanal)

**Foco:** Prática aos sábados e domingos, revisão/refatoração às quartas-feiras  
**Pré-requisito:** Fundamentos teóricos já concluídos  
**Duração:** 8 semanas  
**Objetivo:** Consolidar domínio de C++ moderno com foco em boas práticas, STL, concorrência, ferramentas e testes

---

## ✅ Estrutura Semanal

- **Sábado:** Implementação prática (conceito em ação)
- **Domingo:** Continuação + desafio extra
- **Quarta-feira:** Revisão, refatoração, testes ou leitura complementar

---

## 🔷 Semana 1 — STL + Containers

**Sábado**
- Pratique `vector`, `list`, `map`, `set`, `unordered_map`
- Projeto: Cadastro de produtos (nome, ID, preço) com `map` e `set`

**Domingo**
- Desafio: Contador de palavras com `unordered_map`
- Outros: ordenação simples, frequência de elementos

**Quarta-feira**
- Refatorar com `auto`, lambdas, `range-based for`

---

## 🔷 Semana 2 — Algoritmos STL + Lambdas

**Sábado**
- Usar: `std::sort`, `std::find_if`, `std::accumulate`, `std::transform`

**Domingo**
- Projeto: Ranking de jogadores com `vector` + `sort` com lambdas

**Quarta-feira**
- Revisar uso de iteradores e clareza nas lambdas

---

## 🔷 Semana 3 — Smart Pointers + RAII

**Sábado**
- Reescrever código com `unique_ptr`, `shared_ptr`

**Domingo**
- Criar estrutura que aloca e libera memória com RAII

**Quarta-feira**
- Teste com Valgrind/ASan, revisão do uso correto de ponteiros

---

## 🔷 Semana 4 — Templates e Programação Genérica

**Sábado**
- Funções e classes genéricas com `template<typename T>`

**Domingo**
- Implementar `Stack<T>` genérica

**Quarta-feira**
- Testar com diferentes tipos, revisão de especializações

---

## 🔷 Semana 5 — Múltiplos Arquivos, CMake e Modularização

**Sábado**
- Separar código em `.cpp` e `.h`
- Criar `CMakeLists.txt`

**Domingo**
- Projeto modularizado: exemplo de sistema bancário simples

**Quarta-feira**
- Revisar interfaces, encapsulamento e organização de pastas

---

## 🔷 Semana 6 — Concorrência com `std::thread` e `std::mutex`

**Sábado**
- Criar contador paralelo com `std::thread`

**Domingo**
- Adicionar `std::mutex` para controle de acesso

**Quarta-feira**
- Testar condições de corrida, introdução a `std::atomic`

---

## 🔷 Semana 7 — Testes + Logging

**Sábado**
- Adicionar testes unitários com `Catch2` ou `GoogleTest`

**Domingo**
- Adicionar `spdlog` para logging

**Quarta-feira**
- Refatoração com foco em testabilidade, estrutura de pastas

---

## 🔷 Semana 8 — Projeto Final: Integração

**Sábado**
- Iniciar projeto completo: gerenciador de tarefas com persistência, logs e threads

**Domingo**
- Continuar projeto com testes e modularização

**Quarta-feira**
- Revisar, otimizar, documentar (`README.md`)

---

## 🧩 Sugestões Futuras

- Estudo de bibliotecas como `Boost`, `Qt` ou `Eigen`
- Metaprogramação com `constexpr` e `concepts`
- Integração com C/C++ híbrido, compilação cruzada
