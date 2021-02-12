## Description

### Has Path - Checking if there is a path from one node to the other

<b>PseudoCode:</b>

    is there a direct path ? true:false
    for(i=0 to num_nodes)
    {
        if(edge between starting vertex and i)
        {
            if(not visited[i])
            {
                bool ans = recursive call:staring vertex = i this time
                if(ans) return true
            }
        }
    }
    
<b>Original Code in C++:</b>    
    
```cpp
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
```
