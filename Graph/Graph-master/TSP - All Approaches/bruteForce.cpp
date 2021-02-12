#include <bits/stdc++.h>
using namespace std;

class brute_force
{
public:

    int shortest_path_sum(int** edges_list, int num_nodes)
    {
        int source = 0;
        vector<int> nodes;
        for(int i=0;i<num_nodes;i++)
        {
            if(i != source)
            {
                nodes.push_back(i);
            }
        }
        int n = nodes.size();
        int shortest_path = INT_MAX;
        while(next_permutation(nodes.begin(),nodes.end()))
        {
            int path_weight = 0;

            int j = source;
            for (int i = 0; i < n; i++)
            {
                path_weight += edges_list[j][nodes[i]];
                j = nodes[i];
            }
            path_weight += edges_list[j][source];

            shortest_path = min(shortest_path, path_weight);
        }
        return shortest_path;
    }
};

int main()
{
  	/// Getting the number of nodes and number of edges as input
    int num_nodes,num_edges;
    cin >> num_nodes >> num_edges;

    /// creating a multi-dimensional array
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
        int first_node,second_node,weight;
        cin >> first_node >> second_node >> weight;
        edges_list[first_node][second_node] = weight;
        edges_list[second_node][first_node] = weight;
    }
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << edges_list[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    brute_force approach1;
    cout << approach1.shortest_path_sum(edges_list,num_nodes) << endl;
  	return 0;
}
