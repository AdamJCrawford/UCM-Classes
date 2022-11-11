#include <iostream>
using namespace std;


void cutRod(int p[], int n, int s[])
{
    int r[n] = { 0 };

    for (int j = 0; j < n; j++)
    {
        int q = -2147483648;
        for (int i = 0; i <= j; i++)
        {
            if (j == i)
            {
                if (q < p[i])
                {
                    q    = p[i];
                    s[j] = i + 1;
                }
            }
            else if (q < p[i] + r[j - i - 1])
            {
                q    = p[i] + r[j - i - 1];
                s[j] = i? i + 1:1;
            }
        }
        r[j] = q;
    }
    int max = r[0];

    for (int i = 0; i < n; i++)
    {
        if (r[i] > max)
        {
            max = r[i];
        }
    }
    cout << max << "\n";
}


void printCutRodSolution(int p[], int n, int s[])
{
    cutRod(p, n, s);
    n--;
    if (!n)
    {
        cout << "1 ";
    }
    while (n > 0)
    {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << "-1" << endl;
}


int main()
{
    int nums;

    cin >> nums;
    int prices[nums];

    for (int i = 0; i < nums; i++)
    {
        cin >> prices[i];
    }
    int s[nums] = { 0 };

    printCutRodSolution(prices, nums, s);
    return 0;
}
