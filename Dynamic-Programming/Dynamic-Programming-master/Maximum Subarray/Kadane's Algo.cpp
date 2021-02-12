#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<int> nums;
    solution maxArr;
    int n;
    cin >> n;
    int key;
    while(n--)
    {
        cin >> key;
        nums.push_back(key);
    }
    cout << maxArr.maxSubarray(nums) << endl;
    return 0;
}
