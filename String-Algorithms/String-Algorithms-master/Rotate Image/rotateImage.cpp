# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    void rotate_image(int** img_arr,int n)
    {
        for(int layer = 0;layer < n/2;layer++)
        {
            int first = layer;
            int last = n - 1 - layer;
            for(int i=first;i<last;i++)
            {
                int offset = i - first;
                int top = img_arr[first][i];
                img_arr[first][i] = img_arr[last - offset][first];
                img_arr[last - offset][first] = img_arr[last][last - offset];
                img_arr[last][last - offset] = img_arr[i][last];
                img_arr[i][last] = top;
            }
        }
    }
};

int main()
{
    solution sol;
    int** img_arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        img_arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin >> img_arr[i][j];
        }
    }
    sol.rotate_image(img_arr,n);
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout << img_arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
