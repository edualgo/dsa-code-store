#include<bits/stdc++.h>
using namespace std;

void FindOccurance(int arr[],int size)
{
	unordered_map<int,int> mapp;
	int even = 0,odd = 0;
	for(int i=0;i<size;i++)
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
    unordered_map<int,int>:: iterator it;
    it = mapp.begin();
    while(it != mapp.end())
    {
        if(it -> second %2==0)
        {
           even++;
        }
        else
        {
            odd++;
        }
        it++;
    }
    cout << odd << " " << even << endl;
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
    FindOccurance(arr,n);
    return 0;
}
