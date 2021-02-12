## Description

### Print Path - Printing the path between two given nodes, Using DFS

<b>PseudoCode:</b>

    if(starting_vertex==ending_vertex)
    {
        vector.push_back(ending_vertex)
        return vector
    }
    visited[starting_vertex] = true
    for(i = 0 to num_nodes)
    {
        if(i equals starting_vertex)
        {
            DO NOTHING, CONTINUE
        }
        if(edge between starting_vertex and i)
        {
            if(not visited[i])
            {
                small_ans = recrsive call: starting_vertex = i
                if(small_ans is not NULL)
                {
                    small_ans add starting_vertex
                    return small_ans
                }
            }
        }
    }
    return NULL

<b>Original Code in C++:</b>    

```cpp
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
```
