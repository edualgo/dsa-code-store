# include<bits/stdc++.h>
using namespace std;

bool check_digits(int n)
{
    int p = n;
    while(p!=0)
    {
        if(p%10==2 || p%10==5)
        {
            p = p/10;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}
void printSequence(int n)
{
    if(n==0)
    {
        return;
    }
    bool small_ans = check_digits(n-1);
    if(small_ans == true && n!=1)
    {
        cout << n-1 << endl;
    }
    printSequence(n-1);
}

int main()
{
    int n;
    cin >> n;
    printSequence(n);
    return 0;
}
