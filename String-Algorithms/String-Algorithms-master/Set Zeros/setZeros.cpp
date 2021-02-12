# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
  void setZeroes(int** matrix,int ROW, int COL)
    {
        bool* row_arr = new bool[ROW];
        bool* col_arr = new bool[COL];
        for(int i=0;i<ROW;i++)
        {
            row_arr[i] = false;
        }
        for(int j=0;j<COL;j++)
        {
            col_arr[j] = false;
        }

        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<COL;j++)
            {
                if(matrix[i][j] == 0)
                {
                    row_arr[i] = true;
                    col_arr[j] = true;
                }
            }
        }
        for(int i=0;i<ROW;i++)
        {
            if(row_arr[i])
            {
                for(int j=0;j<COL;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=0;i<COL;i++)
        {
           if(col_arr[i])
           {
                for(int j=0;j<ROW;j++)
                {
                    matrix[j][i] = 0;
                }
           }
        }
    }
};

int main()
{
    solution sol;
    int row,column;
    cin >> row >> column;
    int** matrix = new int*[row];
    for(int i=0;i<row;i++)
    {
        matrix[i] = new int[column];
        for(int j=0;j<column;j++)
        {
            cin >> matrix[i][j];
        }
    }
    sol.setZeroes(matrix,row,column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
