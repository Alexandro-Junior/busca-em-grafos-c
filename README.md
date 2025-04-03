# Construtor de Grafos em C

Este repositório contém uma implementação simples de um construtor de grafos utilizando a linguagem C. O código foi desenvolvido durante a faculdade para reforçar conceitos de estrutura de dados, como listas de adjacência, filas e busca em largura (BFS).

## Funcionalidades
- Permite a criação de um grafo com um número personalizado de vértices.
- Adiciona arestas entre os vértices.
- Utiliza a busca em largura (BFS) para encontrar um caminho entre dois vértices.
- Exibe mensagens informativas sobre a estrutura do grafo e o caminho encontrado.

## Como Utilizar
1. Compile o programa utilizando um compilador C (como GCC):
   ```sh
   gcc grafo.c -o grafo
   ```
2. Execute o programa:
   ```sh
   ./grafo
   ```
3. Insira o número de vértices do grafo.
4. Informe o número de arestas e as conexões entre os vértices.
5. Escolha dois vértices para encontrar um caminho entre eles.

## Exemplo de Execução
```
🕸️  Bem-vindo ao Construtor de Grafos Interativo! 🎯
------------------------------------------------------

Digite o número de vértices: 5
Digite o número de arestas: 4

🛠️  Defina as conexões entre os vértices:
1 2
2 3
3 4
4 5

🎯 Agora, escolha os vértices para buscar um caminho!
Digite o vértice de origem: 1
Digite o vértice de destino: 5

🚀 Caminho encontrado: 1 -> 2 -> 3 -> 4 -> 5 🎯

🌟 Obrigado por usar o Construtor de Grafos! 🚀
```

## Tecnologias Utilizadas
- Linguagem C
- Estruturas de dados (listas encadeadas, filas)
- Algoritmo de busca em largura (BFS)


