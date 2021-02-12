## Description

### 🚗 The edit Distance Problem 

<b>Problem Statement :</b> Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

<b>The Recursive Approach:</b>

*Algorithm:*

* Base case - If one string is empty, return the length of the other
* If the last character is same, call recursively in the rest of the strings excluding the last character.
* If the last character is not same, call recursively to three different subproblems namely insert, remove, replace:
    Considering m and n as the length of the S1 and S2 string respectively,
    * Insert - Insert the last character of S2 in S1, now last character equal and S1 is of length m+1, hence we will call the recursive function on the rest of the string excluding the last character of **size (m,n-1)**.
    * Remove - Removing the last character of S1, we have the string S1 and S2 of length m-1 and n respectively. Hence a recursive call will be made on the **size (m-1,n)**.
    * Replace - Replacing the last character of the strings will make the last character same, hence a recursive call will be made on the **size (m-1,n-1)**.
    
        ```cpp
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

                return 1 + min(rec_helper(first,second,m,n-1),
                               rec_helper(first,second,m-1,n),
                               rec_helper(first,second,m-1,n-1));
            }
            int editDistance(string first, string second)
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
```
