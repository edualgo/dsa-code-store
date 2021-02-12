## Description

### Transitive Closure Of A Graph Using Floyd Warshall Algorithm

<b>Main Code in C++:</b>

```cpp
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
```

### Transitive Closure Of A Graph Using Powering

<b>Main Code in C++:</b>

```cpp
/// utility function to print the transitive closure matrix
void print_transitive_closure(int** output, int num_nodes)
{
    cout << endl;
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

/// utility function to convert powering matrix to transitive closure matrix
void transitive_closure(int** matrix, int num_nodes)
{
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            if(matrix[i][j]>0)
            {
                matrix[i][j] = 1;
            }
        }
    }
    print_transitive_closure(matrix,num_nodes);
}

/// utility function to power the matrix
void matrix_powering(int** edges_list,int num_nodes)
{
    int result[num_nodes][num_nodes];
    int** matrix = new int*[num_nodes];
    for(int i=0;i<num_nodes;i++)
    {
        matrix[i] = new int[num_nodes];
        for(int j=0;j<num_nodes;j++)
        {
            matrix[i][j] = edges_list[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < num_nodes; i++)
    {
        for ( int c = 0 ; c < num_nodes ; c++ )
        {
            for (int d = 0 ; d < num_nodes ; d++ )
            {
                for (int k = 0 ; k < num_nodes ; k++ )
                {
                    sum += matrix[c][k]*matrix[k][d];
                }
                result[c][d] = sum;
                sum = 0;
            }
         }

        for ( int c = 0 ; c < num_nodes ; c++ ) {
            for ( int d = 0 ; d < num_nodes ; d++ ) {
                matrix[c][d] = result[c][d];
                result[c][d] = 0;
            }
        }
    }
    transitive_closure(matrix,num_nodes);
}
```

### Transitive Closure Of A Graph Using Powering (Improved)

<b>Main Code in C++:</b>

```cpp
/// utility function to print the transitive closure matrix
void print_transitive_closure(int** output, int num_nodes)
{
    cout << endl;
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

/// utility function to convert powering matrix to transitive closure matrix
void transitive_closure(int** matrix, int num_nodes)
{
    for(int i=0;i<num_nodes;i++)
    {
        for(int j=0;j<num_nodes;j++)
        {
            if(matrix[i][j]>0)
            {
                matrix[i][j] = 1;
            }
        }
    }
    print_transitive_closure(matrix,num_nodes);
}

/// utility function to get the identity matrix
void identity_matrix(int** a, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = (i == j);
}

//matrix_multiplication method
void matrix_multiplication(int** a, int** b,int SIZE)
{
    int** res = new int*[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        res[i] = new int[SIZE];
        for(int j=0;j<SIZE;j++)
        {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            a[i][j] = res[i][j];
}

// matrix powering to nth power
void matrix_powering(int** a, int n, int** res,int num_nodes)
{
    identity_matrix(res,num_nodes);

    while (n > 0) {
        if (n % 2 == 0)
        {
            matrix_multiplication(a, a,num_nodes);
            n /= 2;
        }
        else {
            matrix_multiplication(res, a,num_nodes);
            n--;
        }
    }
    transitive_closure(res,num_nodes);
}
```
