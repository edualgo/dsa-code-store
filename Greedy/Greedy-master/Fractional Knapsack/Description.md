## Description

### 🚗 The Fractional Knapsack Problem 

<b>Problem Statement :</b> Given items having certain value and weight, put these items in a knapsack with given maximum capacity (maxWeight). The goal here is to find possible maximum total value in the knapsack. Here fraction of items can be used i.e we can break a item.

*Algorithm:*

* As we can break the item into any fraction and use it, we need to normalize it.
* Suppose we have item of weight = a and value = b, we can break that item into 'a' number of items each of value (b/a).
* For eg. if we have item of weight = 30 and value  = 120, we can break that item into 30 items, each having value (120/30)=4 i.e. we have 30 items having weight = 1 and value = 4.
* To maximize the total value inside the knapsack, we will sort the items with reference to (value/weight) ratio using custom compare function in Sort().
* One by one we will check for a item and as per the current total weight inside knapsack we will use the current weight.
* case 1 : if our current item is having weight less than or equal to left weight space inside the knapsack, we didn't need to break the item as whole item can be accommodated inside, so we will add that item fully.
* case 2 : if our current item is having weight more than left weight space inside the knapsack, we will break the item and use only fraction that is required. For eg. if we have capacity(maxWeight) of knapsack = 10 and current total weight of knapsack = 8. Current item is having weight = 30 and value = 120. In order to fill 10-8 = 2 weight space in knapsack we will use only (1/15)th of item i.e weight = (30/15) = 2 having value (120/30)*2 = 8.

```cpp
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
```
