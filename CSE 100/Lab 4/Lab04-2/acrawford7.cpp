#include <iostream>
#include <random>
#include <ctime>
using namespace std;

random_device rd;
mt19937       rng(time(nullptr));


int partition(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];

    a[i + 1] = a[r];
    a[r]     = temp;
    return i + 1;
}


int randomized_partition(int a[], int p, int r)
{
    uniform_int_distribution<int> uni(p, r);

    int i = uni(rng);

    int temp = a[r];

    a[r] = a[i];
    a[i] = temp;

    return partition(a, p, r);
}


void randomized_quick_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = randomized_partition(a, p, r);
        randomized_quick_sort(a, p, q - 1);
        randomized_quick_sort(a, q + 1, r);
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
    randomized_quick_sort(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ";";
    }
    return 0;
}
