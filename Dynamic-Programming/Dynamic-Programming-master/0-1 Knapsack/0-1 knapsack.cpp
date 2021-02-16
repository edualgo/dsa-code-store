#include<bits/stdc++.h>
using namespace std;

class dynamic_approach{
    public:
        int knapsack(int n,int wt[],int val[],int reqWeight){
            int dp[reqWeight+1];
            for(int i=0;i<reqWeight+1;i++){
                dp[i]=0;
            }
            for(int i=0;i<n;i++){
                for(int j=reqWeight;j>=wt[i];j--){
                    dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
                }
            }
            return dp[reqWeight];
        }
}