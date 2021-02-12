#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/// utility function to get the 
void print_transitive_closure(int** output, int num_nodes)
{
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

/// utility function to get back the transitive closure matrix
void transitive_closure(int** edges_list, int num_nodes)
{
    /// creating a new 2D array
    /// copying the elements from the edges_list array
    cout << "Output Transitive Closure Graph:" << endl;
    int** output = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        output[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            output[i][j] = edges_list[i][j];
        }
    }
    
    /*
        i = starting node
        j = ending node
        k = intermediate node, to check if there 
            is any path from i to j through intermediate nodes
    */
    for(int k=0;k<num_nodes;k++)
    {
        for(int i=0;i<num_nodes;i++)
        {
            for(int j=0;j<num_nodes;j++)
            {
                /*
                    output[i][j] = checks if there is direct edge between 
                                   the starting vertex and the ending vertex
                    (output[i][k] && output[k][j]) = if both true then there is 
                                    a connected graph, else it's disconnected for certain k in loop
                */
                
                output[i][j] = output[i][j] || (output[i][k] && output[k][j]);
            }
        }
    }
    
    /// function call to print out the transitive closure graph
    print_transitive_closure(output,num_nodes);
}

int main()
{
    /*
        num_nodes = number of vertex in the graph
        num_edges = number of edges in the graph
    */
    int num_nodes,num_edges;
    cin >> num_nodes >> num_edges;

    
    /// edges_list = adjacent matrix for Directed Graph
    int** edges_list = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        edges_list[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            edges_list[i][j] = 0;
        }
    }

    /// filling up the adjacent matrix using input from the user
    for(int i=0;i<num_edges;i++)
    {
        int first_node,second_node;
        cin >> first_node >> second_node;
        edges_list[first_node][second_node] = 1;
        if(i<num_nodes)
            edges_list[i][i]=1;
    }

    cout << "Input Adjacent Matrix Graph:" << endl;
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << edges_list[i][j] << " ";
        }
        cout << endl;
    }
    
    /// function call to the main algorithm
    transitive_closure(edges_list,num_nodes);
    return 0;
}
