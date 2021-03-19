#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n = 2;
    int maxWeight = 3;
    int wt[2]={2,1};
    int val[2]={1,1};
    dynamic_approach dynamic;
    recursive_approach recursive;
    cout<<dynamic.unbounded_knapsack(n,wt,val,maxWeight)<<endl;
    cout<<recursive.unbounded_knapsack(n,wt,val,maxWeight);
}