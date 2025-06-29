# Guia: Por que evitar implementações em arquivos header (.hpp)?

✅ Introdução

Neste guia, explicamos por que é recomendada a separação entre declarações e implementações em projetos C++ usando arquivos .hpp e .cpp, respectivamente.

📆 O que acontece com #include?

Ao incluir um arquivo .hpp com #include, o compilador literalmente copia o conteúdo do header para o arquivo .cpp durante a fase de pré-processamento.

Exemplo:

// main.cpp
#include "funcoes.hpp"

Durante a compilação, isso se torna:

// main.cpp (expandido)
int soma(int a, int b) { return a + b; }

Se o corpo da função estiver no .hpp, cada .cpp que inclui esse header recompilará toda a implementação.

🐼 Impacto na Compilação

1. Repetição desnecessária

Cada .cpp que inclui o .hpp replica a análise sintática, semântica e a geração de código para as mesmas funções.

2. Rebuild global

Modificou um .hpp? Todos os arquivos que o incluem serão recompilados, mesmo que a mudança não afete nada diretamente.

🚀 Benefícios de separar .hpp e .cpp

Performance de build: compila apenas o que foi alterado

Evita recompilações globais

Isola implementações: menos dependências cruzadas

Facilita leitura e manutenção

❓ Por que templates são exceção?

Templates só podem ser instanciados se o compilador tiver acesso à implementação durante a compilação. Por isso, devem estar inteiros no .hpp.

// correto
template <typename T>
T soma(T a, T b) { return a + b; }

🔄 Resumo

Tipo de Código

Local Recomendado

Funções normais

Declaração em .hpp, implementação em .cpp

Templates

Inteiros no .hpp

constexpr

Pode estar no .hpp

Macros ou inline simples

.hpp

# 🔧 Boas Práticas

Nunca coloque implementações longas em headers.

Use #pragma once ou include guards para evitar duplicação.

Use constexpr com cuidado: é inline e visível globalmente.

Mantenha seus headers limpos. Use .cpp para compilar rápido ✨

No final compile os dois cpp