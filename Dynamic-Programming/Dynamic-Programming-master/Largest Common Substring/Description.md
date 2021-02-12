## Description

### 🔠 The Largest Common Substring Problem 

<b>Problem Statement :</b>Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.

<b>The Recursive Approach:</b>

*Algorithm:*
 * Check if the last character is same, if yes then call recursively in the rest of the string excluding the last character. If No, proceed to the next step.
 * Return the maximum of the two subproblems, one of which includes last character of the first string and excludes the last character second one, another one is just the opposite of the first one.
    For Example - "AXYB" and "AXBY" has last character not equal. Hence we find the **max(LCS("AXY","AXBY"),LCS("AXYB","AXB"))** , where LCS is the recursive function for Lowest Common Substring.
    
```cpp
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
```

<b>The Dynamic Approach:</b>

Tabulation is done using a two dimensional array in this case. Whose dimensions are same as that of the length of the strings + 1 .

```cpp
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
```
