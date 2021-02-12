#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    ll* arr2 = new ll[n];
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    arr2[0] = 1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i] > arr[i-1])
        {
            arr2[i] = arr2[i-1]+1;
        }
        else
        {
            arr2[i] = 1;
        }
    }
    sort(arr2,arr2+n);
    cout << arr2[n-1] << endl;
    return 0;
}
