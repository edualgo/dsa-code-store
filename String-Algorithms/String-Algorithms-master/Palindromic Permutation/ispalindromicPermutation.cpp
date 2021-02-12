# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    bool isPalindromicPermutation(string input)
    {
        map<char,int> mapp;
        for(int i=0;i<input.size();i++)
        {
            char key = input[i];
            if(mapp.count(key)==0 && key != ' ')
            {
                mapp[key] = 1;
            }
            else
            {
                mapp[key]++;
            }
        }
        int flag = 0;
        map<char,int>::iterator it = mapp.begin();
        while(it != mapp.end())
        {
            if((it-> second)%2==1)
            {
                flag++;
            }
            it++;
        }
        return flag<=1;
    }
};

int main()
{
    string input1;
    getline(cin,input1);
    solution sol;
    cout << sol.isPalindromicPermutation(input1)<< endl;
    return 0;
}
