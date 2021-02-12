#include <bits/stdc++.h>
using namespace std;


vector<int>* pathDFS(int** edges_list,int num_nodes,int starting_vertex,int ending_vertex, bool* visited)
{
    if(starting_vertex == ending_vertex)
    {
        vector<int>* path_nodes = new vector<int>();
        path_nodes -> push_back(ending_vertex);
        return path_nodes;
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
                vector<int>* small_ans = pathDFS(edges_list,num_nodes,i,ending_vertex,visited);
                if(small_ans != NULL)
                {
                    small_ans -> push_back(starting_vertex);
                    return small_ans;
                }
            }
        }
    }
    return NULL;
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
    int starting_vertex, ending_vertex;
    cin >> starting_vertex >> ending_vertex;
    bool* visited = new bool[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        visited[i]=false;
    }
    vector<int>* ans = pathDFS(edges_list,num_nodes,starting_vertex,ending_vertex,visited);
    if(ans != NULL)
    {
        for(int i=0;i< ans -> size();i++)
    	{
       		 cout << ans -> at(i) << " ";
    	}
    }
  	return 0;
}
