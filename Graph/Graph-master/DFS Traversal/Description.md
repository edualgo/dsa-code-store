## Description

### Adjacent Matrix Creation and Edge List Marking

Creating an adjacent matrix is necessary. Suppose we have a graph like below,
![graph image](https://github.com/Treasure-Code-Algorithm/Graph/blob/master/graph.PNG)

The adjacent matrix can be represented as,
![adjacent matrix](https://github.com/Treasure-Code-Algorithm/Graph/blob/master/adjacent%20matrix.PNG)

### Depth First Search (DFS) - Graph Traversal Technique

<b>PseudoCode:</b>

    print(strating_vertex)
    visited[starting_vertex] = true
    for(i to num_edges)
        if(i == staring_vertex)
            DO NOTHING, CONTINUE 
        if edge beteween starting_vertex & i:
              if(i is visited): 
                  DO NOTHING, CONTINUE    
               recursive call <- starting_vertex will be i
               
<b>Original Code in C++:</b>

```cpp
void printDFS(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes)
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
            printDFS(edges_list,num_nodes,i,visited_nodes);
        }
    }
}
```
