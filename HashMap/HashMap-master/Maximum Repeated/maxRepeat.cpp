#include<bits/stdc++.h>
using namespace std;

int find_max_rept(int* a,int n)
{
    unordered_map<int,int> mapp;
    for(int i=0;i<n;i++)
    {
        int key = a[i];
        if(mapp.count(key)==0)
        {
            mapp[key] = 1;
        }
        else
        {
            mapp[key]++;
        }
    }
    int maxim = mapp[a[0]];
    int best = a[0];
    int j=1;
    while(j<n)
    {
        if(mapp[a[j]]>maxim)
        {
            maxim = mapp[a[j]];
            best = a[j];
        }
        j++;
    }
    return best;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int l = find_max_rept(arr,n);
    cout << l << endl;
    return 0;
}
