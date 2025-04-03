#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura para representar um nó na lista de adjacência
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Estrutura para representar um grafo
typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

// Estrutura para representar uma fila (usada no BFS)
typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Função para criar um novo nó
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo com vértices numerados de 1 até n
Graph* createGraph(int vertices) {
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("\n🚨 Erro: O número de vértices deve estar entre 1 e %d!\n\n", MAX_VERTICES);
        return NULL;
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc((vertices + 1) * sizeof(Node*));

    for (int i = 1; i <= vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest) {
    if (src < 1 || src > graph->numVertices || dest < 1 || dest > graph->numVertices) {
        printf("\n⚠️ Aresta inválida: (%d, %d) está fora dos limites do grafo!\n", src, dest);
        return;
    }

    // Adiciona a aresta src -> dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Adiciona a aresta dest -> src (grafo não direcionado)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Função para criar uma fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Função para enfileirar um elemento
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

// Função para desenfileirar um elemento
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    } else {
        int item = q->items[q->front++];
        if (q->front > q->rear)
            q->front = q->rear = -1;
        return item;
    }
}

// Função para encontrar um caminho entre dois vértices usando BFS
void bfs(Graph* graph, int startVertex, int endVertex) {
    int* visited = (int*)malloc((graph->numVertices + 1) * sizeof(int));
    int* parent = (int*)malloc((graph->numVertices + 1) * sizeof(int));
    Queue* q = createQueue();

    // Inicializa os arrays
    for (int i = 1; i <= graph->numVertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                parent[adjVertex] = currentVertex;
                enqueue(q, adjVertex);

                // Se chegarmos ao destino, podemos parar a busca
                if (adjVertex == endVertex) {
                    break;
                }
            }
            temp = temp->next;
        }
    }

    // Reconstruindo o caminho
    if (parent[endVertex] == -1) {
        printf("\n❌ Nenhum caminho encontrado entre %d e %d!\n", startVertex, endVertex);
    } else {
        printf("\n🚀 Caminho encontrado: ");
        int path[MAX_VERTICES];
        int count = 0;
        for (int v = endVertex; v != -1; v = parent[v])
            path[count++] = v;

        // Imprimir o caminho no formato correto
        for (int i = count - 1; i > 0; i--)
            printf("%d -> ", path[i]);
        printf("%d 🎯\n", path[0]);
    }

    free(visited);
    free(parent);
    free(q);
}

// Função principal
int main() {
    int vertices, edges, src, dest;

    printf("🕸️  Bem-vindo ao Construtor de Grafos Interativo! 🎯\n");
    printf("------------------------------------------------------\n");

    printf("\nDigite o número de vértices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);
    if (!graph)
        return -1;

    printf("Digite o número de arestas: ");
    scanf("%d", &edges);

    if (edges < 0) {
        printf("\n⚠️ Número de arestas inválido!\n");
        free(graph);
        return -1;
    }

    printf("\n🛠️  Defina as conexões entre os vértices (ex: 1 2 para conectar 1 e 2):\n");
    for (int i = 0; i < edges; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        if (v1 < 1 || v1 > vertices || v2 < 1 || v2 > vertices) {
            printf("\n❌ Erro! Vértices %d e %d estão fora do intervalo permitido (1 a %d)\n", v1, v2, vertices);
            free(graph);
            return -1;
        }

        addEdge(graph, v1, v2);
    }

    printf("\n🎯 Agora, escolha os vértices para buscar um caminho!\n");
    printf("\nDigite o vértice de origem: ");
    scanf("%d", &src);
    printf("Digite o vértice de destino: ");
    scanf("%d", &dest);

    if (src < 1 || src > vertices || dest < 1 || dest > vertices) {
        printf("\n⚠️ Erro! Vértices de origem ou destino inválidos!\n");
        free(graph);
        return -1;
    }

    bfs(graph, src, dest);

    printf("\n🌟 Obrigado por usar o Construtor de Grafos! 🚀\n\n");

    free(graph);
    return 0;
}
