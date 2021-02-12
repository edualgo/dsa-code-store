#include<iostream>
#include<cstring>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

class recursive_approach
{
public:
    int rec_helper(string first, string second, int m, int n)
    {
        if(m==0)
        {
            return n;
        }
        if(n==0)
        {
            return m;
        }
        if(first[m-1]==second[n-1])
        {
            return rec_helper(first,second,m-1,n-1);
        }

       return 1 + min(rec_helper(first,second,m,n-1),rec_helper(first,second,m-1,n),rec_helper(first,second,m-1,n-1));

    }
    int editDistance(string first, string second)
    {
        int m = first.size();
        int n = second.size();

        return rec_helper(first,second,m,n);
    }
};

class dynamic_approach
{
public:
    int editDistance(string first, string second)
    {
        int m = first.size();
        int n = second.size();

        int table[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0)
                {
                    table[i][j] = j;
                }
                else if(j==0)
                {
                    table[i][j] = i;
                }
                else if(first[i-1]==second[j-1])
                {
                    table[i][j] = table[i-1][j-1];
                }
                else
                {
                    table[i][j] = 1 + min(table[i][j-1],table[i-1][j],table[i-1][j-1]);
                }
            }
        }
        return table[m][n];
    }
};

int main()
{
    dynamic_approach dynamic;
    recursive_approach recursive;
    string first,second;
    cin >> first >> second;
    cout << dynamic.editDistance(first,second) << endl;
    cout << recursive.editDistance(first,second) << endl;
    return 0;
}
