## Description

### 🚗 The 0-1 Knapsack Problem 

<b>Problem Statement :</b> Given weights having certain value, put these weights in a knapsack with given maximum capacity (maxWeight). The goal here is to find possible maximum total value in the knapsack. Any weight can be selected for only once.

<b>The Recursive Approach:</b>

*Algorithm:*

* Basically here we have to find a subset of weights whose total weight is less than equal to the capacity of knapsack and have maximum total value.
* Recursively we will move from index 0 to n-1 and will perform two operations:
    * Add the current weight. We will only select the current weight if the total weight inside knapsack after selecting remains under the given capacity else will ignore it.
    * Don't Add the current weight.
* We will recursively call next element after performing maybe any one or both operations given above.
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

            dp[i][curWeightSum] = rec_helper(curWeightSum,i+1,n, wt,val,maxWeight,dp);

            if(curWeightSum+wt[i]<=maxWeight) {
                dp[i][curWeightSum] = max(dp[i][curWeightSum],
                                        val[i] + rec_helper(curWeightSum + wt[i], i + 1, n, wt, val, maxWeight, dp));
            }

            return dp[i][curWeightSum];
        }
        int knapsack(int n,int wt[],int val[],int maxWeight){
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
Tabulation is done using a one dimensional array in this case. Whose dimension is same as maxWeight+1(capacity of knapsack). Here we do same two operations stated in recursive approach. We check if we can add certain weight for particular j(0,1...maxWeight). And we select maximum from value till previous iteration and value after the current weight is added. 

```cpp
class dynamic_approach{
    public:
        int knapsack(int n,int wt[],int val[],int maxWeight){
            int dp[maxWeight+1];
            for(int i=0;i<maxWeight+1;i++){
                dp[i]=0;
            }
            for(int i=0;i<n;i++){
                for(int j=maxWeight;j>=wt[i];j--){
                    dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
                }
            }
            return dp[maxWeight];
        }
};
```
