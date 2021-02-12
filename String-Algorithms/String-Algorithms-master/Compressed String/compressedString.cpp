# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    string compressedString(string input)
    {
        map<char,int> mapp;
        string output = "";
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
            output = output + it -> first + to_string(it -> second);
            it++;
        }
        if(output.size() <= input.size())
        {
            return output;
        }
        else
        {
            return input;
        }
    }
};

int main()
{
    string input1;
    getline(cin,input1);
    solution sol;
    print(sol.compressedString(input1));
    return 0;
}
