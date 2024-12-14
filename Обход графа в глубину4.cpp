#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 5 

// Функция для вывода матрицы смежности
void print_adjacency_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void DFS_non_recursive(int matrix[N][N], int start_vertex) {
    int visited[N] = { 0 };  
    int stack[N];         
    int top = -1;        

    stack[++top] = start_vertex;

    while (top != -1) {

        int vertex = stack[top--];

        if (!visited[vertex]) {
            visited[vertex] = 1;
            printf("Вершина %d\n", vertex);

            for (int i = N - 1; i >= 0; i--) {
                if (matrix[vertex][i] == 1 && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, ""); 

    int matrix[N][N] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Матрица смежности графа:\n");
    print_adjacency_matrix(matrix);

    // Выполнение нерекурсивного обхода в глубину
    printf("\nНерекурсивный обход в глубину (DFS) начиная с вершины 0:\n");
    DFS_non_recursive(matrix, 0);

    return 0;
}
