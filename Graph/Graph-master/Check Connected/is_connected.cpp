#include <iostream>
using namespace std;

void check_connection(int** edges_list, int num_nodes, int starting_vertex,bool* visited_nodes)
{
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
        	check_connection(edges_list,num_nodes,i,visited_nodes);
        }
    }
}

bool is_connected(int** edges_list, int num_nodes, int starting_vertex)
{
    bool* visited = new bool[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        visited[i] = false;
    }
    check_connection(edges_list, num_nodes, starting_vertex, visited);
    int flag=0;
    for(int i=0;i<num_nodes;i++)
    {
        if(visited[i]==false)
        {
            flag++;
        }
    }
    return (flag==0);
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
    bool output = is_connected(edges_list,num_nodes,0);
    if(output==true)
    {
        cout << "true" << endl;
    }
    else    
    {
        cout << "false" << endl;
    }
  	return 0;
}
