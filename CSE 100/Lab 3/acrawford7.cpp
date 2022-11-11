#include <iostream>

using namespace std;
#define MIN_INT    -2147483647


int Max_Crossing_subarray(int a[], int i, int mid, int j)
{
    int leftsum = MIN_INT, rightsum = MIN_INT;
    int sum = 0;

    for (int k = mid; k > i - 1; k--)
    {
        sum += a[k];
        if (sum > leftsum)
        {
            leftsum = sum;
        }
    }

    sum = 0;
    for (int l = mid + 1; l < j + 1; l++)
    {
        sum += a[l];
        if (sum > rightsum)
        {
            rightsum = sum;
        }
    }
    return(leftsum + rightsum);
}


int Find_Maximum_Subarray(int a[], int i, int j)
{
    if (i == j)
    {
        return a[i];
    }
    //The sudo code in the book has the chance to overflow. With this method of calculating the middle there is no chance of an overflow.
    int mid      = (i + j) / 2;
    int leftsum  = Find_Maximum_Subarray(a, i, mid);
    int rightsum = Find_Maximum_Subarray(a, mid + 1, j);
    int midsum   = Max_Crossing_subarray(a, i, mid, j);

    if ((leftsum > rightsum) && (leftsum > midsum))
    {
        return leftsum;
    }
    else if ((rightsum > leftsum) && (rightsum > midsum))
    {
        return rightsum;
    }
    else
    {
        return midsum;
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

    cout << Find_Maximum_Subarray(a, 0, size - 1);
    return 0;
}
