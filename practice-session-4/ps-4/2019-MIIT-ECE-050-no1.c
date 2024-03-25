#include <stdio.h>
#include <stdlib.h>

#define V 5

void createAdjMatrix(int arr[V][V]);
void addEdge(int arr[V][V], int src, int dest);
void displayAdjMatrix(int arr[V][V]);

int main()
{
    int adjMatrix[V][V];

    createAdjMatrix(adjMatrix);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 3, 3);
    addEdge(adjMatrix, 4, 1);

    displayAdjMatrix(adjMatrix);
    printf("\n");

    return 0;
}

void createAdjMatrix(int arr[V][V])
{
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[V][V], int src, int dest)
{
    arr[src][dest] = 1;
}

void displayAdjMatrix(int arr[V][V])
{
    printf("Adjacency Matrix is \n\n");
    printf("    ");

    for (int j = 0; j < V; j++)
    {
        printf("%d ", j + 1);
    }

    printf("\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d [ ", i + 1);
        for (int j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("]");
        printf("\n");
    }
}