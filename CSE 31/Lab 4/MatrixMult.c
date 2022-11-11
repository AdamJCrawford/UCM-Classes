#include <stdio.h>
#include <malloc.h>


void printArray(int **arr, int n)
{
    // (5) Implement your printArr here:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}


int **matMult(int **a, int **b, int size)
{
    // (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
    int **matResult = (int **)malloc(size * sizeof(int *));

    for (int l = 0; l < size; l++)
    {
        *(matResult + l) = (int *)malloc(size * sizeof(int));
    }
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum = 0;
            for (int k = 0; k < size; k++)
            {
                sum += *(*(a + i) + k) * *(*(b + k) + j);
                // same as sum += a[i][k] * b[k][j];
            }
            *(*(matResult + i) + j) = sum;
        }
    }
    return matResult;
}


int main()
{
    int n = 5;
    int **matA, **matB, **matC;

    // (1) Define 2 (n x n) arrays (matrices).
    matA = (int **)malloc(n * sizeof(int *));
    matB = (int **)malloc(n * sizeof(int *));

    // (3) Add your code to complete allocating and initializing the 2-D array here. The content should be all 0.
    for (int k = 0; k < n; k++)
    {
        *(matA + k) = (int *)malloc(n * sizeof(int));
        *(matB + k) = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(*(matA + i) + j) = ((i == j) ? i + 1 : 0);
            *(*(matB + i) + j) = ((i == j) ? i + 1 : 0);
        }
    }

    // (3) Call printArray to print out the 2 arrays here.
    printArray(matA, n);
    printArray(matB, n);

    // (5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n);

    // (6) Call printArray to print out resulting array here.
    printArray(matC, n);

    return 0;
}
