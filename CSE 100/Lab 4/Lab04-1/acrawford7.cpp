#include <iostream>

using namespace std;

void max_heapify(int a[], int size, int i)
{
    int l       = 2 * i + 1;
    int r       = 2 * i + 2;
    int largest = i;

    if ((l < size) && (a[l] > a[i]))
    {
        largest = l;
    }

    if ((r < size) && (a[r] > a[largest]))
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = a[i];
        a[i]       = a[largest];
        a[largest] = temp;

        max_heapify(a, size, largest);
    }
}


void build_max_heap(int a[], int size)
{
    for (int i = (size + 1) / 2; i > -1; i--)
    {
        max_heapify(a, size, i);
    }
}


void heap_sort(int a[], int size)
{
    build_max_heap(a, size);
    for (int i = size - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        size--;
        max_heapify(a, size, 0);
    }
}


int main()
{
    int size;

    cin >> size;
    int a[size];

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    heap_sort(a, size);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ";";
    }
    //cout << heap_sort(a);
    return 0;
}
