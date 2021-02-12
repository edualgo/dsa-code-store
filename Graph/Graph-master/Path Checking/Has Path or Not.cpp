#include <bits/stdc++.h>
using namespace std;

bool has_path_helper(int** edges_list,int num_nodes,int starting_vertex,int ending_vertex,bool* visited)
{
    if(edges_list[starting_vertex][ending_vertex]==1)
    {
        return true;
    }
    visited[starting_vertex] = true;
    for(int i=0;i<num_nodes;i++)
    {
        if(i==starting_vertex)
        {
            continue;
        }
        if(edges_list[starting_vertex][i]==1)
        {
            if(!visited[i])
        	{
            	visited[i] = true;
                bool ans = has_path_helper(edges_list,num_nodes,i,ending_vertex,visited);
                if(ans)
                {
                    return true;
                }
            } 
        }
    }
    return false;
}

bool has_path(int** edges_list,int num_nodes,int starting_vertex,int ending_vertex)
{
    bool* visited = new bool[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        visited[i] = false;
    }
    return has_path_helper(edges_list,num_nodes,starting_vertex,ending_vertex,visited);
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

    int vertex1,vertex2;
    cin >> vertex1 >> vertex2;
    if(has_path(edges_list,num_nodes,vertex1,vertex2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
