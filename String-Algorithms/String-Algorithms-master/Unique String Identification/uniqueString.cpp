# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    bool isUnique(string input)
    {
        map<char,int> mapp;
        for(int i=0;i<input.size();i++)
        {
            char key = input[i];
            if(mapp.count(key)==0)
            {
                mapp[key] = 1;
            }
            else
            {
                mapp[key]++;
            }
        }
        map<char,int>::iterator it = mapp.begin();
        while(it != mapp.end())
        {
            if(it -> second > 1)
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
    string input1;
    getline(cin,input1);
    solution sol;
    cout << sol.isUnique(input1)<< endl;
    return 0;
}
