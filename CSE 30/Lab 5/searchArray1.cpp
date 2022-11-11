#include <iostream>
#include <string>

using namespace std;

int summation = 0;

int binarySearchR(string A[], int array_size, string key, int dummyVar)
{
    int middle = array_size / 2;

    if (A[middle] < key)
    {
        if ((array_size == 1) || (array_size == 0))
        {
            summation = -1;
            return 0;
        }
        return binarySearchR(A, array_size / 2, key, 1);
    }
    else if (A[middle] > key)
    {
        if ((array_size == 1) || (array_size == 0))
        {
            summation = -1;
            return 0;
        }
        summation += middle;

        for (int i = 0; i < array_size / 2 + 1; i++)
        {
            A[i] = A[array_size / 2 + i];
        }
        return binarySearchR(A, (array_size + 1) / 2, key, 1);
    }
    else
    {
        summation += middle;
        return 0;
    }
}


int binarySearchR(string A[], int array_size, string key)
{
    int middle = array_size / 2;

    if (A[middle] > key)
    {
        if ((array_size == 1) || (array_size == 0))
        {
            summation = -1;
            return 0;
        }
        return binarySearchR(A, middle, key);
    }
    else if (A[middle] < key)
    {
        if ((array_size == 1) || (array_size == 0))
        {
            summation = -1;
            return 0;
        }
        summation += middle;

        for (int i = 0; i < (array_size + 1) / 2; i++)
        {
            A[i] = A[array_size / 2 + i];
        }
        return binarySearchR(A, (array_size + 1) / 2, key);
    }
    else
    {
        summation += middle;
        return 0;
    }
}


int checkArraySort(string A[], int array_size)
{
    int returningValue;
    int currentValue;

    A[0] > A[1]? returningValue = -1: returningValue = 1;

    for (int i = 1; i < array_size - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            currentValue = -1;
        }
        else if (A[i] < A[i + 1])
        {
            currentValue = 1;
        }
        if (returningValue != currentValue)
        {
            return 0;
        }
    }
    return returningValue;
}


int main()
{
    string words[10] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J" };
    //string words[10] = { "J", "I", "H", "G", "F", "E", "D", "C", "B", "A" };
    string key;
    int    result;

    if (checkArraySort(words, 10) == 0)
    {
        cout << "The array is not sorted" << endl;
        return 0;
    }
    else if (checkArraySort(words, 10) == 1)
    {
        cout << "Enter a key to search for: ";
        cin >> key;
        binarySearchR(words, 10, key);
    }
    else
    {
        cout << "Enter a key to search for: ";
        cin >> key;
        binarySearchR(words, 10, key, 1);
    }
    cout << summation << endl;
    summation > -1 ? cout << "Found key " << key << " at index " << summation : cout << "The key " << key << " was not found in the array!" << endl;
    return 0;
}
