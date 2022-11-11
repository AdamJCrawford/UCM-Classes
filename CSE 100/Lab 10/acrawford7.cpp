#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Node
{
    int         name;
    int         start_time;
    int         end_time;
    int         scc_comp;
    string      color = "White";
    vector<int> connections;
};

bool sort_nodes(Node a, Node b)
{
    //cout << a.end_time << " " << b.end_time << "\n";
    return a.end_time > b.end_time;
}


vector<Node> nodes;
vector<Node> nodes_reversed;
vector<Node> nodes_reversed_temp;
int          current_time = -1;

//I know my code is a mess.... but it appears to work.
void dfs_visit2(Node u, int index, int current)
{
    current_time = current_time + 1;
    nodes_reversed_temp[index].start_time = current_time;
    nodes_reversed_temp[index].color      = "Gray";
    for (int connection: u.connections)
    {
        if (nodes_reversed_temp[connection].color == "White")
        {
            current = connection < current? connection:current;
            dfs_visit2(nodes_reversed_temp[connection], connection, current);
        }
    }
    nodes_reversed_temp[index].color = "Black";
    current_time = current_time + 1;
    nodes_reversed_temp[index].end_time = current_time;
    nodes_reversed_temp[index].scc_comp = current;
}


void dfs2()
{
    for (int i = 0; i < nodes_reversed.size(); i++)
    {
        for (Node node: nodes_reversed_temp)
        {
            if (node.name == nodes_reversed[i].name)
            {
                if (node.color == "White")
                {
                    dfs_visit2(node, node.name, node.name);
                }
            }
        }
    }
}


void dfs_visit1(Node u, int index)
{
    current_time            = current_time + 1;
    nodes[index].start_time = current_time;
    nodes[index].color      = "Gray";
    for (int connection: u.connections)
    {
        if (nodes[connection].color == "White")
        {
            dfs_visit1(nodes[connection], connection);
        }
    }
    nodes[index].color    = "Black";
    current_time          = current_time + 1;
    nodes[index].end_time = current_time;
}


void dfs1()
{
    for (Node node:nodes)
    {
        if (node.color == "White")
        {
            dfs_visit1(node, node.name);
        }
    }
}


int main()
{
    int num_nodes;
    int num_connections;

    cin >> num_nodes;
    for (int i = 0; i < num_nodes; i++)
    {
        Node node = *(new Node);
        node.name = i;
        nodes.push_back(node);

        Node node_b = *(new Node);
        node_b.name = i;
        nodes_reversed_temp.push_back(node_b);
    }
    cin >> num_connections;
    for (int i = 0; i < num_connections; i++)
    {
        int j;
        int k;
        cin >> j >> k;
        nodes[j].connections.push_back(k);
        nodes_reversed_temp[k].connections.push_back(j);
    }
    dfs1();

    current_time = -1;

    sort(nodes.begin(), nodes.end(), sort_nodes);

    for (Node node: nodes)
    {
        nodes_reversed.push_back(nodes_reversed_temp[node.name]);
    }

    dfs2();

    for (Node node:nodes_reversed_temp)
    {
        cout << node.scc_comp << "\n";
    }

    return 0;
}
