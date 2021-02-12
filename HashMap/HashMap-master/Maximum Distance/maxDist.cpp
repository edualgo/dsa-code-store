#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> a)
{
    unordered_map<int,int> mapp;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]==a[j])
            {
                int key = a[i];
                int m = j-i;
                if(m>mapp[key])
                    mapp[key] = m;
            }
        }
    }
    int maxim = mapp[a[0]];
    int best = a[0];
    int j=1;
    while(j<a.size())
    {
        if(mapp[a[j]]>maxim)
        {
            maxim = mapp[a[j]];
            best = a[j];
        }
        j++;
    }
    return maxim;
}
int main()
{
    vector<int> input;
    int n,data;
    cin >> n;
    while(n--)
    {
        cin >> data;
        input.push_back(data);
    }
    int l = maxDistance(input);
    cout << l << endl;
}
