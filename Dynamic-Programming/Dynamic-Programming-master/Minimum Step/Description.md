## Description

### 🚶‍ The Minimum Step Problem 

<b>Problem Statement :</b> Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

<b>The Recursive Approach:</b>

```cpp
class recursive_approach
{
public:
    int countStepsTo1(int n)
    {
        int small_ans;
        if(n==1)
        {
            return 0;
        }
        small_ans = countStepsTo1(n-1);
        if(n%3==0)
        {
            n = n/3;
            small_ans = min(small_ans,countStepsTo1(n));
        }
        else if(n%2==0)
        {
            n = n/2;
            small_ans = min(small_ans,countStepsTo1(n));
        }
        return small_ans+1;
    }
};
```

<b>The Dynamic Programming Approach:</b>

```cpp
class dynamic_approach
{
public:
    int countStepsTo1(int n)
    {
        int* array = new int[n+1];
        for(int i=0;i<=n;i++)
        {
            array[i] = 0;
        }
        array[1] = 0;
        array[2] = 1;
        array[3] = 1;
        for(int i=4;i<=n;i++)
        {
            if(i%3==0)
            {
                array[i] = min(array[i/3],array[i-1])+1;
            }
            else if(i%2==0)
            {
                array[i] = min(array[i/2],array[i-1])+1;
            }
            else
            {
                array[i] = array[i-1]+1;
            }
        }
        return array[n];
    }
};
```
