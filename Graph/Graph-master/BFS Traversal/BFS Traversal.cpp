#include <bits/stdc++.h>
using namespace std;

void printBFS(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes)
{
    /// Creating a queue with the STL
    queue<int> pending_nodes;
    pending_nodes.push(starting_vertex);
    
    /// running the loop till the queue is empty
    while(!pending_nodes.empty())
    {
        int front_node = pending_nodes.front();
        cout << front_node << " ";
        visited_nodes[front_node]=true;
        pending_nodes.pop();
        for(int i=0;i<num_nodes;i++)
        {
            if(i==front_node)
            {
                continue;
            }
            if(edges_list[front_node][i]==1)
            {
                if(visited_nodes[i])
                {
                    continue;
                }
                pending_nodes.push(i);
                visited_nodes[i]=true;
            }
        }
    }
}

int main()
{
    /// Getting the number of nodes and number of edges as input
    int num_nodes,num_edges;
    cin >> num_nodes >> num_edges;

    /// creating a multi-dimensional array to know
    /// which node has an edge with another node
    int** edges_list = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        edges_list[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            edges_list[i][j] = 0;
        }
    }

    /// adjacent matrix filling mechanism
    for(int i=0;i<num_edges;i++)
    {
        int first_node,second_node;
        cin >> first_node >> second_node;
        edges_list[first_node][second_node] = 1;
        edges_list[second_node][first_node] = 1;
    }

    /// creating a boolean array to have a track of visited nodes
    bool* visited_nodes = new bool[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        visited_nodes[i] = false;
    }

    /// printing the entire graph
    printBFS(edges_list,num_nodes,0,visited_nodes);
    return 0;
}
