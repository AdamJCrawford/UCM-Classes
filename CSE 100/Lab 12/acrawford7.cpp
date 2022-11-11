#include <iostream>
#include <vector>
using namespace std;

struct Connection
{
    int other_node;
    int weight;
};

struct Node
{
    int                index;
    int                distance = 1073741823;
    Node               *parent  = nullptr;
    vector<Connection> pair;
};

vector<Node> nodes;

void relax(Node u, Node v)
{
    int  weight = 0;
    bool found  = false;

    for (Connection conn:u.pair)
    {
        if (conn.other_node == v.index)
        {
            weight = conn.weight;
            found  = true;
            break;
        }
    }
    if (found)
    {
        if (v.distance > u.distance + weight)
        {
            nodes[v.index].distance = u.distance + weight;
            nodes[v.index].parent   = &u;
        }
    }
}


bool bellman_ford()
{
    nodes[0].distance = 0;
    for (int i = 0; i < nodes.size() + 1; i++)
    {
        for (Node node: nodes)
        {
            for (Connection conn: node.pair)
            {
                relax(node, nodes[conn.other_node]);
            }
        }
    }
    for (Node node: nodes)
    {
        for (Connection conn: node.pair)
        {
            if (nodes[conn.other_node].distance > node.distance + conn.weight)
            {
                return false;
            }
        }
    }
    return true;
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
        a.other_node = destination;
        a.weight     = weight;
        nodes[source].pair.push_back(a);
    }
    if (bellman_ford())
    {
        cout << "TRUE" << "\n";
        for (Node node: nodes)
        {
            if (node.distance != 1073741823)
            {
                cout << node.distance << "\n";
            }
            else
            {
                cout << "INFINITY" << "\n";
            }
        }
    }

    else
    {
        cout << "FALSE" << "\n";
    }
    return 0;
}
