#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class recursive_approach
{
public:
    ll get_ways(ll n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }
        else if(n==2)
        {
            return 2;
        }
        else
        {
            return get_ways(n-3)+get_ways(n-2)+get_ways(n-1);
        }
    }
};

class dynamic_approach
{
public:
    ll get_ways(int n)
    {
        ll* array = new ll[n+1];
        for(ll i=0;i<=n;i++)
        {
            array[i] = 0;
        }
        array[1] = 1;
        array[2] = 2;
        array[3] = 4;
        for(ll i=4;i<=n;i++)
        {
            for(ll j=i-3;j<i;j++)
            {
                array[i]+=array[j];
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
    cout << "From Dynamic Approach : " << dynamic.get_ways(n) << endl;
    cout << "From Recursive Approach : " << recur.get_ways(n) << endl;
}
