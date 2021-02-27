#include<bits/stdc++.h>
using namespace std;

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
    cout<<dynamic.unbounded_knapsack(n,wt,val,maxWeight);
}