#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX_VERTICES 10

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

int main()
{
    setlocale(LC_ALL, "Russian");

    int n; // Количество вершин графа
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
    printf("\nМатрица смежности для графа G:\n");
    print_matrix(n, adjacency_matrix);

    return 0;
}
