## Description

### 🏟 The Staircase Problem 

<b>Problem Statement :</b> A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

<b>The Recursive Approach:</b>

```cpp
class recursive_approach
{
public:
    int get_ways(int n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        else if(n==2)
        {
            return 2;
        }
        else
        {
            return get_ways(n-3)+get_ways(n-2)+get_ways(n-1);
        }
    }
};
```
    
<b>The Dynamic Programming Approach:</b>

```cpp
class dynamic_approach
{
public:
    int get_ways(int n)
    {
        int* array = new int[n+1];
        for(int i=0;i<=n;i++)
        {
            array[i] = 0;
        }
        array[1] = 1;
        array[2] = 2;
        array[3] = 4;
        for(int i=4;i<=n;i++)
        {
            for(int j=i-3;j<i;j++)
            {
                array[i]+=array[j];
            }
        }
        return array[n];
    }
};
```
