A escolha de um bom **pivô** é fundamental em algoritmos como o **Quicksort**, **Quickselect**, ou estruturas como a **árvore de busca** balanceada (em certos contextos). Um bom pivô ajuda a manter o desempenho eficiente, evitando os piores casos de complexidade. Aqui vão algumas estratégias e critérios para escolher um bom pivô:

---

### ✅ **Critérios para um bom pivô**

Um bom pivô deve:

1. **Dividir os dados de forma equilibrada**, ou seja, gerar duas partições de tamanho próximo.
2. **Evitar casos extremos**, como sempre pegar o maior ou menor valor (isso causa desequilíbrio e pode levar à complexidade quadrática O(n²)).

---

### 📌 Estratégias comuns para escolha de pivô:

#### 1. **Pivô fixo (ex: primeiro ou último elemento)**

* Simples, mas **ineficiente em dados ordenados ou quase ordenados**.
* Pode gerar pior caso (O(n²)) com facilidade.

#### 2. **Pivô aleatório (`randomized`)**

* Escolhe um índice aleatório do array como pivô.
* Evita padrões ruins.
* Complexidade esperada é **O(n log n)** mesmo em muitos casos adversos.

#### 3. **Mediana de três (`median-of-three`)**

* Compara o primeiro, o do meio e o último elemento, e escolhe a mediana entre eles.
* Estratégia eficiente contra dados ordenados.
* Exemplo de código:

  ```cpp
  int middle = (low + high) / 2;
  int pivot = median(array[low], array[middle], array[high]);
  ```
* Balanceia o custo entre eficiência e simplicidade.

#### 4. **Mediana real (ou "mediana das medianas")**

* Garante a escolha de um **pivô que divide o array em duas partes com no mínimo 30% dos elementos** em cada lado.
* Complexidade garantida **O(n)** para seleção e **O(n log n)** para ordenação, mesmo no pior caso.
* É usada no **algoritmo de seleção linear determinístico** (Blum-Floyd-Pratt-Rivest-Tarjan).
* Mais caro computacionalmente, mas com desempenho garantido.

---

### ⚠️ Quando a escolha do pivô é crítica?

* Ao trabalhar com **grandes volumes de dados**, onde a eficiência precisa ser máxima.
* Quando os dados **possuem padrão conhecido** (como quase ordenados).
* Em situações onde o **pior caso não pode ser tolerado**.

---

### ✅ Resumo prático:

| Estratégia           | Complexidade Esperada | Garantia no Pior Caso | Aplicação típica                    |
| -------------------- | --------------------- | --------------------- | ----------------------------------- |
| Primeiro/último      | O(n log n) ou O(n²)   | ❌ Não                 | Simples, mas arriscado              |
| Aleatório            | O(n log n)            | ❌ Não                 | Geralmente bom, com sort randômico  |
| Mediana de três      | O(n log n)            | ❌ Não                 | Boa escolha prática                 |
| Mediana das medianas | O(n log n)            | ✅ Sim                 | Algoritmo de seleção determinístico |

