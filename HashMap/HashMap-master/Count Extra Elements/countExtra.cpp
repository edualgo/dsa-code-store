#include<bits/stdc++.h>
using namespace std;

int CountExtraElements(int arr[], int n)
{
	unordered_map<int,int> mapp;
	for(int i=0;i<n;i++)
    {
        int key = arr[i];
        if(mapp.count(key)==0)
        {
            mapp[key] = 1;
        }
        else
        {
            mapp[key]++;
        }
    }
    int sum = 0;
    unordered_map<int,int>::iterator it = mapp.begin();
    while(it != mapp.end())
    {
        sum+= it -> second - 1;
        it ++;
    }
    return sum;
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
    int l = CountExtraElements(arr,n);
    cout << l << endl;
    return 0;
}



