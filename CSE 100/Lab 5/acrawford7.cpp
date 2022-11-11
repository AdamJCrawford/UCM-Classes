#include <iostream>
using namespace std;

void countingSort(int nums1[][10], int nums2[][10], int length, int index)
{
    int storage[4];

    for (int i = 0; i < 4; i++)
    {
        storage[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        storage[nums1[i][index]]++;
    }
    for (int i = 1; i < 4; i++)
    {
        storage[i] += storage[i - 1];
    }
    for (int i = length - 1; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            int ith = storage[nums1[i][index]] - 1;
            nums2[ith][j] = nums1[i][j];
        }
        storage[nums1[i][index]]--;
    }
}


void radix(int nums1[][10], int nums2[][10], int length)
{
    for (int i = 9; i > -1; i--)
    {
        if (i % 2 == 1)
        {
            countingSort(nums1, nums2, length, i);
        }
        else
        {
            countingSort(nums2, nums1, length, i);
        }
    }
    countingSort(nums1, nums2, length, 0);
}


int main()
{
    int size;

    cin >> size;
    int nums1[size][10];
    int nums2[size][10];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> nums1[i][j];
        }
    }

    radix(nums1, nums2, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << nums2[i][j] << ";";
        }
        cout << "\n";
    }
    return 0;
}
