# include<iostream>
# include<cstdlib>
# include<string>
# include<map>

using namespace std;

class solution
{
public:
    string URLify(string input,string key)
    {
        string input2;
        int size_string = input.size();
        for(int i=0;i<size_string;i++)
        {
            if(input[i]!=' ')
            {
                input2+=input[i];
            }
            else if((input[i]==' ') && (input[i+1]==' '))
            {
               return input2;
            }
            else if((input[i]==' ') && (input[i+1]!=' '))
            {
                input2 = input2 + key;
            }
        }
        return input2;
    }
};

int main()
{
    string input1,key;
    getline(cin,input1);
    cin >> key;
    solution sol;
    cout << sol.URLify(input1,key)<< endl;
    return 0;
}
