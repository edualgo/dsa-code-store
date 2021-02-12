#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class recursive_approach
{
public:
    ll bill_num(ll amount)
    {
        if(amount==0)
        {
            return 0;
        }
        if(amount >= 100)
        {
            amount = amount - 100;
        }
        else if(amount >= 20)
        {
            amount = amount - 20;
        }
        else if(amount >= 10)
        {
            amount = amount - 10;
        }
        else if(amount >= 5)
        {
            amount = amount - 5;
        }
        else if(amount >= 1)
        {
            amount = amount - 1;
        }
        return 1 + bill_num(amount);
    }
};

class dynamic_approach
{
public:
    ll bill_num(ll amount)
    {
        ll arr[amount+1];
        arr[0] = 0;
        for(ll i=1;i<=amount;i++)
        {
            if(i>=100)
            {
                arr[i] = i/100 + arr[i%100];
            }
            else if(i>=20)
            {
                arr[i] = i/20 + arr[i%20];
            }
            else if(i>=10)
            {
                arr[i] = i/10 + arr[i%10];
            }
            else if(i>=5)
            {
                arr[i] = i/5 + arr[i%5];
            }
            else if(i>=1)
            {
                arr[i] = i/1 + arr[i%1];
            }
        }
        return arr[amount];
    }
};

class optimized_dynamic_approach
{
public:
    ll bill_num(ll amount)
    {
        ll count = 0;
        if(amount/100)
        {
            count+=(amount/100);
            amount -= (amount/100)*100;
        }
        if(amount/20)
        {
            count+=(amount/20);
            amount -= (amount/20)*20;
        }
        if(amount/10)
        {
            count+=(amount/10);
            amount -= (amount/10)*10;
        }
        if(amount/5)
        {
            count+=(amount/5);
            amount -= (amount/5)*5;
        }
        count+=amount;
        return count;
    }
};

int main()
{
	ll amount;
	cin >> amount;
	recursive_approach recursive;
	dynamic_approach dynamic;
	optimized_dynamic_approach optimized_dynamic;
	cout << optimized_dynamic.bill_num(amount) << endl;
	cout << dynamic.bill_num(amount) << endl;
	cout << recursive.bill_num(amount) << endl;
	return 0;
}
