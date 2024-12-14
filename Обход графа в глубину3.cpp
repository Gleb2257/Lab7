#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_VERTICES 10 

// Структура для списка смежности
typedef struct Node {
    int vertex;        
    struct Node* next;  
} Node;

// Функция для создания нового узла списка
Node* create_node(int vertex) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Функция для добавления ребра в список смежности
void add_edge(Node* adjacency_list[], int src, int dest) {
 
    Node* new_node = create_node(dest);
    new_node->next = adjacency_list[src];
    adjacency_list[src] = new_node;

    new_node = create_node(src);
    new_node->next = adjacency_list[dest];
    adjacency_list[dest] = new_node;
}

// Функция для печати списка смежности
void print_adjacency_list(Node* adjacency_list[], int n) {
    printf("Список смежности графа:\n");
    for (int i = 0; i < n; i++) {
        printf("Вершина %d:", i + 1);
        Node* temp = adjacency_list[i];
        while (temp) {
            printf(" -> %d", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(Node* adjacency_list[], bool visited[], int v) {
    visited[v] = true;
    printf("%d ", v + 1); 

    Node* temp = adjacency_list[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(adjacency_list, visited, temp->vertex);
        }
        temp = temp->next;
    }
}

// Функция для обхода связности графа
void depth_first_search(Node* adjacency_list[], int n) {
    bool visited[MAX_VERTICES] = { false }; 

    printf("Порядок обхода графа:\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { 
            DFS(adjacency_list, visited, i);
        }
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, e; 
    Node* adjacency_list[MAX_VERTICES] = { NULL }; 

    printf("Введите количество вершин графа (не больше %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n > MAX_VERTICES || n <= 0) {
        printf("Некорректное количество вершин.\n");
        return 1;
    }

    printf("Введите количество ребер: ");
    scanf("%d", &e);

    printf("Введите ребра (начальная и конечная вершины):\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(adjacency_list, src - 1, dest - 1); 
    }

    // Вывод списка смежности
    print_adjacency_list(adjacency_list, n);

    // Выполнение обхода графа в глубину
    depth_first_search(adjacency_list, n);

    for (int i = 0; i < n; i++) {
        Node* temp = adjacency_list[i];
        while (temp) {
            Node* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }

    return 0;
}
