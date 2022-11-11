#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct node
{
    char   letter;
    int    value;
    node   *left  = nullptr;
    node   *right = nullptr;
    string path;
};

node a;
node b;
node c;
node d;
node e;
node f;

bool compare_nodes(node a, node b)
{
    return a.value < b.value;
}


void path_finder(node *n, string current)
{
    if (n->left || n->right)
    {
        if (n->left)
        {
            path_finder(n->left, current + '0');
        }
        if (n->right)
        {
            path_finder(n->right, current + '1');
        }
        n = nullptr;
        delete n;
    }
    else
    {
        if (n->letter == 'A')
        {
            a.path = current;
        }
        else if (n->letter == 'B')
        {
            b.path = current;
        }
        else if (n->letter == 'C')
        {
            c.path = current;
        }
        else if (n->letter == 'D')
        {
            d.path = current;
        }
        else if (n->letter == 'E')
        {
            e.path = current;
        }
        else
        {
            f.path = current;
        }
        delete n;
    }
}


void huffman(node C[], int length)
{
    node D[length];

    for (int i = 0; i < length; i++)
    {
        D[i] = C[i];
    }
    for (int i = 0; i < length - 1; i++)
    {
        node *z = new node;
        node *a = new node;
        node *b = new node;
        *a       = D[i];
        *b       = D[i + 1];
        z->left  = a;
        z->right = b;
        z->value = z->left->value + z->right->value;
        D[i + 1] = *z;
        sort(D + i + 1, D + 6, compare_nodes);
    }
    node val = D[length - 1];

    path_finder(&val, "");
}


int main()
{
    a.letter = 'A';
    b.letter = 'B';
    c.letter = 'C';
    d.letter = 'D';
    e.letter = 'E';
    f.letter = 'F';
    node group[6] = { a, b, c, d, e, f };


    for (int i = 0; i < 6; i++)
    {
        cin >> group[i].value;
    }
    sort(group, group + 6, compare_nodes);
    huffman(group, 6);
    cout << 'A' << ':' << a.path << "\n";
    cout << 'B' << ':' << b.path << "\n";
    cout << 'C' << ':' << c.path << "\n";
    cout << 'D' << ':' << d.path << "\n";
    cout << 'E' << ':' << e.path << "\n";
    cout << 'F' << ':' << f.path << "\n";
    return 0;
}
