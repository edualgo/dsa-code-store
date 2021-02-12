#include<bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> input)
{
    map<int,int> mapp;
    int p = input.size();
    for(int i=0;i<p;i++)
    {
        int key = input[i];
        if(mapp.count(key)==0)
        {
            mapp[key] = 1;
        }
        else
        {
            mapp[key]++;
        }
    }
    vector<int> l;
    map<int,int>::iterator it;
    it = mapp.begin();
    while(it!=mapp.end())
    {
        l.push_back(it -> first);
        it++;
    }
    /*for(auto element:mapp)
    {
        l.push_back(element.first);
    }*/
    return l;
}

int main()
{
    vector<int> input;
    vector<int> output;
    int n;
    cin >> n;
    int data;
    while(n--)
    {
        cin >> data;
        input.push_back(data);
    }
    output = removeDuplicates(input);
    for(int i=0;i<output.size();i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}

