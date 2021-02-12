## Description

### Adjacent Matrix Creation and Edge List Marking

Creating an adjacent matrix is necessary. Suppose we have a graph like below,
![graph image](https://github.com/Abhijit2505/Graph/blob/master/Image%20Assets/graph.png)

The adjacent matrix can be represented as,
![adjacent matrix](https://github.com/Abhijit2505/Graph/blob/master/Image%20Assets/adjacent%20matrix.png)

### Bredth First Search (BFS) - Graph Traversal Technique

<b>PseudoCode:</b>

    build a queue
    add starting_vertex to the queue
    while(queue is not empty)
    {
       front_node = queue.front()
       pop the front node
       print(front_node)
       for(i=0 to num_edges)
       {
            if(i==front_node)
            {
                DO NOTHING, CONTINUE
            }
            if(edge between front_node and i)
            {
                if(visited_node[i]==1) 
                {
                    DO NOTHING, CONTINUE
                }
                push i to ther queue
                visited_node[i] = true
            }
        }
    }
    
<b>Original Code in C++:</b>    
    
```cpp
void printBFS(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes)
{
    queue<int> pending_nodes;
    pending_nodes.push(starting_vertex);
    while(!pending_nodes.empty())
    {
        int front_node = pending_nodes.front();
        cout << front_node << " ";
        visited_nodes[front_node]=true;
        pending_nodes.pop();
        for(int i=0;i<num_nodes;i++)
        {
            if(i==front_node)
            {
                continue;
            }
            if(edges_list[front_node][i]==1)
            {
                if(visited_nodes[i])
                {
                    continue;
                }
                pending_nodes.push(i);
                visited_nodes[i]=true;
            }
        }
    }
}
```
