#include <iostream>
using namespace std;
#define MAX_INT    2147483647

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1 + 1; i++)
    {
        L[i] = A[p + i - 1];
    }
    for (int j = 0; j < n2 + 1; j++)
    {
        R[j] = A[q + j];
    }
    L[n1 + 1] = MAX_INT;
    R[n2 + 1] = MAX_INT;
    int n = 1;
    int m = 1;

    for (int k = p; k < r + 1; k++)
    {
        if (L[n] <= R[m])
        {
            A[k] = L[n];
            n++;
        }
        else
        {
            A[k] = R[m];
            m++;
        }
    }
}


void mergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}


int main()
{
    int num_numbers;

    cin >> num_numbers;

    int nums[num_numbers];

    for (int i = 0; i < num_numbers; i++)
    {
        cin >> nums[i];
    }

    mergeSort(nums, 0, num_numbers - 1);
    for (int i = 0; i < num_numbers; i++)
    {
        cout << nums[i] << ";";
    }
    return 0;
}
