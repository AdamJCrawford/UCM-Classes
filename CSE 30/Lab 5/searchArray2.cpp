#include <iostream>
#include <string>

using namespace std;

int binarySearchL(string A[], int array_size, string key, int dummyVar)
{
    int upper        = array_size;
    int lower        = 0;
    int currentValue = (upper + lower) / 2;

    while (lower + 1 != upper && upper != lower)
    {
        if (A[currentValue] == key)
        {
            return currentValue;
        }
        else if (A[currentValue] < key)
        {
            upper = currentValue;
        }
        else
        {
            lower = currentValue;
        }
        currentValue = (upper + lower) / 2;
    }
    if (A[0] == key)
    {
        return 0;
    }
    return -1;
}


int binarySearchL(string A[], int array_size, string key)
{
    int upper        = array_size;
    int lower        = 0;
    int currentValue = (upper + lower) / 2;

    while (lower + 1 != upper && upper != lower)
    {
        if (A[currentValue] == key)
        {
            return currentValue;
        }
        else if (A[currentValue] > key)
        {
            upper = currentValue;
        }
        else
        {
            lower = currentValue;
        }
        currentValue = (upper + lower) / 2;
    }
    if (A[0] == key)
    {
        return 0;
    }
    return -1;
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
        result = binarySearchL(words, 10, key);
    }
    else
    {
        cout << "Enter a key to search for: ";
        cin >> key;
        result = binarySearchL(words, 10, key, 1);
    }

    result > -1 ? cout << "Found key " << key << " at index " << result : cout << "The key " << key << " was not found in the array!" << endl;
    return 0;
}
