#include <iostream>
#include <string>
#include <string>

using namespace std;

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
    string words[10] = { "AB", "AB", "EF", "HI", "JK", "LM", "NO", "PQ", "RS", "TU" };
    string reversedWords[10];

    for (int i = 0; i < 10; i++)
    {
        reversedWords[i] = words[10 - i - 1];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << reversedWords[i] << " ";
    }


    cout << endl;
    cout << checkArraySort(reversedWords, 10) << endl;
    return 0;
}
