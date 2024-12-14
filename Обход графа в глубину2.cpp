#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

#define MAX_VERTICES 10 

// Функция для генерации матрицы смежности неориентированного графа
void generate_adjacency_matrix(int n, int matrix[MAX_VERTICES][MAX_VERTICES])
{
    srand(time(NULL)); 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0; 
            }
            else if (i < j)
            {
                matrix[i][j] = rand() % 2;
                matrix[j][i] = matrix[i][j]; 
            }
        }
    }
}

// Функция для печати матрицы смежности
void print_matrix(int n, int matrix[MAX_VERTICES][MAX_VERTICES])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(int v, int n, int matrix[MAX_VERTICES][MAX_VERTICES], bool visited[MAX_VERTICES])
{
    visited[v] = true; 
    printf("%d ", v + 1); 

    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1 && !visited[i])
        {
            DFS(i, n, matrix, visited); 
        }
    }
}

// Функция для обхода графа 
void depth_first_search(int n, int matrix[MAX_VERTICES][MAX_VERTICES])
{
    bool visited[MAX_VERTICES] = { false }; 

    printf("Порядок обхода графа:\n");
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            DFS(i, n, matrix, visited); 
        }
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n; 
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

    printf("Введите количество вершин графа (не больше %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n > MAX_VERTICES || n <= 0)
    {
        printf("Некорректное количество вершин.\n");
        return 1;
    }

    // Генерация и вывод матрицы смежности
    generate_adjacency_matrix(n, adjacency_matrix);
    printf("\nМатрица смежности графа:\n");
    print_matrix(n, adjacency_matrix);

    depth_first_search(n, adjacency_matrix);

    return 0;
}
