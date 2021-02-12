#include <bits/stdc++.h>
using namespace std;

vector<int>* pathBFS(int** edges,int num_nodes,int starting_vertex,int ending_vertex)
{
     queue<int> shortest_path;
     bool* visited = new bool[num_nodes];
     for(int i=0;i<num_nodes;i++)
     {
         visited[i] = false;
     }
     shortest_path.push(starting_vertex);
     visited[starting_vertex] = true;
     bool done = false;
     unordered_map<int,int> parent;
     while(!shortest_path.empty() && !done)
     {
         int front_node = shortest_path.front();
         shortest_path.pop();
         for(int i=0;i<num_nodes;i++)
         {
             if(edges[front_node][i] && !visited[i])
             {
                 parent[i] = front_node;
                 shortest_path.push(i);
                 visited[i] = true;
                 if(i == ending_vertex)
                 {
                     done = true;
                     break;
                 }
             }
         }
     }
     delete [] visited;
     if(!done)
     {
         return NULL;
     }
     else
     {
         vector<int>* output = new vector<int>();
         int current = ending_vertex;
         output -> push_back(ending_vertex);
         while(current != starting_vertex)
         {
             current = parent[current];
             output -> push_back(current);
         }
         return output;
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
    int starting_vertex, ending_vertex;
    cin >> starting_vertex >> ending_vertex;
    bool* visited = new bool[num_nodes];
    vector<int>* ans = pathBFS(edges_list,num_nodes,starting_vertex,ending_vertex);
    if(ans != NULL)
    {
        for(int i=0;i< ans -> size();i++)
    	{
       		 cout << ans -> at(i) << " ";
    	}
    }
  	return 0;
}
