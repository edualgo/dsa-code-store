#include <bits/stdc++.h>
using namespace std;

void print_graph(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes)
{
    cout << starting_vertex << endl;
    visited_nodes[starting_vertex] = true;
    for(int i=0;i<num_nodes;i++)
    {
        if(i==starting_vertex)
        {
            continue;
        }
        if(edges_list[starting_vertex][i]==1)
        {
            if(visited_nodes[i])
            {
                continue;
            }
            print_graph(edges_list,num_nodes,i,visited_nodes);
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
    print_graph(edges_list,num_nodes,0,visited_nodes);
}
