#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct Connection
{
    int other_node;
    int weight;
};

struct Node
{
    int                index;
    int                key     = 2147483647;
    Node               *parent = nullptr;
    vector<Connection> pair;
};

bool compareNodesKeys(Node a, Node b)
{
    return a.key < b.key;
}


// bool compareNodesIndices(Node a, Node b)
// {
//     return a.index < b.index;
// }


vector<Node> nodes;
vector<bool> checked;
void min_span_tree(int answer[])
{
    vector<Node> q;

    for (Node node:nodes)
    {
        q.push_back(node);
        checked.push_back(0);
    }
    q[0].key = 0;
    while (q.size())
    {
        Node a = q[0];
        q.erase(q.begin());

        for (int i = 0; i < a.pair.size(); i++)
        {
            for (int j = 0; j < q.size(); j++)
            {
                if (q[j].index == a.pair[i].other_node)
                {
                    if (checked[q[j].index])
                    {
                        continue;
                    }
                    if (a.pair[i].weight < q[j].key)
                    {
                        q[j].parent = &a;
                        q[j].key    = a.pair[i].weight;
                        //nodes[q[j].index]      = q[j];
                        answer[q[j].index - 1] = q[j].parent->index;
                    }
                }
            }
        }
        sort(q.begin(), q.end(), compareNodesKeys);
    }
}


int main()
{
    int num_nodes;

    cin >> num_nodes;
    for (int i = 0; i < num_nodes; i++)
    {
        nodes.push_back(*(new Node));
        nodes[i].index = i;
    }

    int num_connections;

    cin >> num_connections;
    for (int i = 0; i < num_connections; i++)
    {
        int source;
        int destination;
        int weight;
        cin >> source >> destination >> weight;
        Connection a;
        Connection b;
        a.other_node = destination;
        a.weight     = weight;
        b.other_node = source;
        b.weight     = weight;
        nodes[source].pair.push_back(a);

        nodes[destination].pair.push_back(b);
    }

    int answer[num_nodes - 1] = { 0 };

    min_span_tree(answer);
    for (int i = 0; i < num_nodes - 1; i++)
    {
        cout << answer[i];
        cout << "\n";
    }
    return 0;
}
