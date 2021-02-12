# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    bool oneEditAwayInsert(string input1,string input2)
    {
        int index1 = 0,index2 = 0;
        while(index1<input1.size() && index2<input2.size())
        {
            if(input1[index1] != input2[index2])
            {
                if(index1 != index2)
                {
                    return false;
                }
                index2++;
            }
            else
            {
                index1++;
                index2++;
            }
        }
        return true;
    }
    bool oneEditAwayReplace(string input1,string input2)
    {
        bool flag = false;
        for(int i=0;i<input1.size();i++)
        {
            if(input1[i]!=input2[i])
            {
                if(flag)
                {
                    return false;
                }
                flag = true;
            }
        }
        return true;
    }
    bool oneEditAway(string input1,string input2)
    {
        if(input1.size()==input2.size())
        {
            return oneEditAwayReplace(input1,input2);
        }
        if(input1.size()+1 == input2.size())
        {
            return oneEditAwayInsert(input1,input2);
        }
        if(input1.size()-1 == input2.size())
        {
            return oneEditAwayInsert(input2,input1);
        }
        return false;
    }
};

int main()
{
    string input1,input2;
    getline(cin,input1);
    getline(cin,input2);
    solution sol;
    if(sol.oneEditAway(input1,input2))
    {
        cout << "One Edit Away" << endl;
    }
    else
    {
        cout << "No Edit Away" << endl;
    }
    return 0;
}
