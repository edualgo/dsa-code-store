## Description

### 🚗 The Unbounded Knapsack Problem 

<b>Problem Statement :</b> Given weights having certain value, put these weights in a knapsack with given maximum capacity (maxWeight). The goal here is to find possible maximum total value in the knapsack. Any weight can be selected for multiple times.

<b>The Recursive Approach:</b>

*Algorithm:*
* This problem is an extension of classic 1-0 knapsack problem. The only variation here is that the weights can be selected for multiple times.
* Basically here we have to find a subset of weights whose total weight is less than equal to the capacity of knapsack and have maximum total value. This subset my contain weights more than once.
* Recursively we will move from index 0 to n-1 and will perform two operations:
    * Add the current weight. We will only select the current weight if the total weight inside knapsack after selecting remains under the given capacity else will ignore it. If selected, we will call for same index again because we can select weight for more than once.
    * Don't Add the current weight. Here we will move to next index (i.e i+1)
* We will return the maximum of both operations as we have to maximize the total value.
* Base Case - here we will stop at index==n because there's no weight to add in the knapsack.
* Memoization - Here we have use 2d array - dp to store the recursion calls to avoid repeating calls and use the value stored in dp instead. This is useful for reducing time complexity.
    
```cpp
class recursive_approach{
    public:
        int rec_helper(int curWeightSum,int i,int n,int wt[],int val[],int maxWeight,int **dp){
            if(i==n){
                return 0;
            }
            if(dp[i][curWeightSum]!=-1){
                return dp[i][curWeightSum];
            }

            dp[i][curWeightSum] = rec_helper(curWeightSum,i+1,n,wt,val,maxWeight,dp);

            if(curWeightSum+wt[i]<=maxWeight) {
                dp[i][curWeightSum] = max(dp[i][curWeightSum],
                                          val[i] + rec_helper(curWeightSum + wt[i], i, n, wt, val, maxWeight, dp));
            }

            return dp[i][curWeightSum];
        }
        int unbounded_knapsack(int n,int wt[],int val[],int maxWeight){
            int** dp=new int*[n];
            for(int i=0;i<n;i++){
                dp[i]=new int[maxWeight+1];

                for(int j=0;j<maxWeight+1;j++){
                    dp[i][j]=-1;
                }
            }
            return rec_helper(0,0,n,wt,val,maxWeight,dp);
        }
};
```

<b>The Dynamic Approach:</b>
Tabulation is done using a one dimensional array in this case, Whose dimension is same as maxWeight+1(capacity of knapsack). Here we do same two operations stated in recursive approach. We check if we can add certain weight for particular j(0,1...maxWeight). And we select maximum from value till previous iteration (i.e. dp array) and value after the current weight is added. If current required j is 5 and current weight in consideration is 3 then we have to add value of weight=3 and maximum value for forming knapsack of total weight 2 which we can obtain from same dp. This dp will contain the maximum values for knapsack from size 0 to maxWeight. So we can compute for every weight and at last return for maxWeight from same dp. 

```cpp
class dynamic_approach{
    public:
        int unbounded_knapsack(int n,int wt[],int val[],int maxWeight){
            int dp[maxWeight+1];
            for(int i=0;i<maxWeight+1;i++){
                dp[i]=0;
            }
            for(int i=0;i<n;i++){
                for(int j=wt[i];j<maxWeight+1;j++){
                    dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
                }
            }
            return dp[maxWeight];
        }

};
```
