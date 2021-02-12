#include<iostream>
#include<cstring>
using namespace std;

class recursive_approach
{
public:
    int rec_helper(string first, string second, int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        if (first[m-1] == second[n-1])
        {
            return 1 + rec_helper(first, second, m-1, n-1);
        }
        else
        {
            return max(rec_helper(first, second, m, n-1), rec_helper(first, second, m-1, n));
        }
        return 0;
    }
    int largest_common_substring(string first, string second)
    {
        int m = first.size();
        int n = second.size();
        return rec_helper(first,second,m,n);
    }
};

class dynamic_approach
{
public:
    int largest_common_substring(string first, string second)
    {
        int m = first.size();
        int n = second.size();
        int table[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    table[i][j] = 0;
                }
                else if(first[i-1]==second[j-1])
                {
                    table[i][j] = table[i-1][j-1]+1;
                }
                else
                {
                    table[i][j] = max(table[i - 1][j], table[i][j - 1]);
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
    cout << dynamic.largest_common_substring(first,second) << endl;
    cout << recursive.largest_common_substring(first,second) << endl;
    return 0;
}
