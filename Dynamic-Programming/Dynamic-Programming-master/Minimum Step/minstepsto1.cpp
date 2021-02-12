#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class recursive_approach
{
public:
    ll countStepsTo1(ll n)
    {
        ll small_ans;
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

class dynamic_approach
{
public:
    ll countStepsTo1(ll n)
    {
        ll* array = new ll[n+1];
        for(ll i=0;i<=n;i++)
        {
            array[i] = 0;
        }
        array[1] = 0;
        array[2] = 1;
        array[3] = 1;
        for(ll i=4;i<=n;i++)
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
int main()
{
    recursive_approach recur;
    dynamic_approach dynamic;
    ll n;
    cin >> n;
    cout << "From Dynamic Approach : " << dynamic.countStepsTo1(n) << endl;
    cout << "From Recursive Approach : " << recur.countStepsTo1(n) << endl;
}
