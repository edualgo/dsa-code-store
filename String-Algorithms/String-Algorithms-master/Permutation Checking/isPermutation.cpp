# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    bool isPermutation(string input1,string input2)
    {
        if(input1.size() != input2.size())
        {
            return false;
        }
        map<char,int> mapp1;
        map<char,int> mapp2;
        for(int i=0;i<input1.size();i++)
        {
            char key = input1[i];
            if(mapp1.count(key) == 0)
            {
                mapp1[key] = 1;
            }
            else
            {
                mapp1[key]++;
            }
        }
        for(int j=0;j<input2.size();j++)
        {
            char key = input2[j];
            if(mapp2.count(key) == 0)
            {
                mapp2[key] = 1;
            }
            else
            {
                mapp2[key]++;
            }
        }
        map<char,int>::iterator it = mapp1.begin();
        while(it != mapp1.end())
        {
            if(mapp1[it->first] != mapp2[it->first])
            {
                return false;
            }
            it++;
        }
        return true;
    }
};

int main()
{
    string input1,input2;
    getline(cin,input1);
    getline(cin,input2);
    solution sol;
    cout << sol.isPermutation(input1,input2)<< endl;
    return 0;
}
