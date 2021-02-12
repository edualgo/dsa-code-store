## Description

### Is Connected - Check if the graph is totally connected ?

<b>Main Code in C++:</b>

```cpp
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
```
