## Description

### Print Path - Printing the path between two given nodes, Using BFS

<b>Main Code in C++</b>

```cpp
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
```
