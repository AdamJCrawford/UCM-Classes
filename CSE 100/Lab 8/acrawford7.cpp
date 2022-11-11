#include <iostream>

using namespace std;
int m_size;
void printOptimalParens(int s[], int i, int j)
{
    int converted[m_size + 2][m_size + 2] = { 0 };
    int counter = 0;

    for (int k = 1; k < m_size + 1; k++)
    {
        for (int l = k + 1; l < m_size + 1; l++)
        {
            converted[k][l] = s[counter];
            counter++;
        }
    }
    //cout << i << " " << j << "\n";
    if (i == j)
    {
        cout << "A" << i - 1;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, converted[i][j]);
        printOptimalParens(s, converted[i][j] + 1, j);
        cout << ")";
    }
}


int main()
{
    cin >> m_size;
    int inputs[m_size];

    for (int i = 0; i < m_size + 1; i++)
    {
        cin >> inputs[i];
    }
    int real_m[m_size][m_size] = { 0 };
    int real_s[m_size][m_size] = { 0 };

    int m[m_size + 4][m_size + 4] = { 0 };
    int s[m_size + 4][m_size + 4] = { 0 };

    for (int l = 2; l < m_size + 1; l++)
    {
        for (int i = 1; i < m_size - l + 2; i++)
        {
            int j = i + l - 1;
            m[i][j] = 2147483647;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + inputs[i - 1] * inputs[k] * inputs[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 0; i < m_size - 1; i++)
    {
        for (int j = 0; j < m_size - 1; j++)
        {
            real_s[i][j] = s[i + 1][j + 2];
        }
    }
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            real_m[i][j] = m[i + 1][j + 1];
        }
    }
    int one_dim[m_size * m_size];
    int counter = 0;

    for (int i = 0; i < m_size - 1; i++)
    {
        for (int j = i; j < m_size - 1; j++)
        {
            one_dim[counter] = real_s[i][j];
            counter++;
        }
    }
    cout << real_m[0][m_size - 1] << "\n";
    printOptimalParens(one_dim, 1, m_size);
    cout << endl;
    return 0;
}
