#include<bits/stdc++.h>
using namespace std;


struct Item{
    int weight,value;

};

class greedy_approach{

    static bool compare(Item a,Item b){
        return (double)a.value/a.weight>(double)b.value/b.weight;
    }

    public:
    double fractional_knapsack(int maxWeight,int n,Item weights[]){
        sort(weights,weights+n,compare);
        double ans = 0 ;
        for(int i=0;i<n;i++){
            if(maxWeight>=weights[i].weight){
                maxWeight-=weights[i].weight;
                ans+=weights[i].value;
            }else{
                ans+=maxWeight*(double)weights[i].value/weights[i].weight;
                break;
            }
        }
        return ans;
    }
};

int main(){
    int n = 3;
    int maxWeight = 60;
    Item weights[] = {{10,50},{20,40},{30,90}};
    greedy_approach greedy = greedy_approach();
    cout<<greedy.fractional_knapsack(maxWeight,n,weights);
}