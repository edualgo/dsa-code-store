## Explanation

### 📈 Maximum Subarray Problem and Kadane's Algorithm

<b>Problem Statement :</b> Given an integer array **nums**, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

<b>The Dynamic Approach:</b>

```cpp
class solution
{
public:
    int maxSubarray(vector<int>& nums)
    {
        int ans = INT_MIN, sum = 0;
        for(int i=0 ;i < nums.size();i++)
        {
            sum += nums[i];
            ans = max(sum,ans);
            sum = max(sum,0);
        }
        return ans;
    }
};
```
    
<b>The Python Approach</b>

```python3
class solution:
    def maxSubarray(self,nums):
        ans = float('-inf')
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            ans = max(sum,ans)
            sum = max(sum,0)
        return ans

nums = list(map(int,input().split()))
maxArr = solution()
print(maxArr.maxSubarray(nums))
```
