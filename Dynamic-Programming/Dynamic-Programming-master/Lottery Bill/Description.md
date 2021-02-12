## Description

### 🎟 The Lottery Bill Problem 

<b>Problem Statement :</b> Allen has a LOT of money. He has n dollars in the bank. For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here). The denominations for dollar bills are 1, 5, 10, 20, 100. What is the minimum number of bills Allen could receive after withdrawing his entire balance?

<b>The Recursive Approach:</b>

```cpp
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
```

<b>The Dynamic Approach:</b>

```cpp
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
```

<b>The Optimized Dynamic Approach:</b>

```cpp
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
```
    
<b>The Python Approach</b>

```python3
amount = int(input())
count = 0

if int(amount/100):
    count+=int(amount/100)
    amount -= int(amount/100)*100
if int(amount/20):
    count+=int(amount/20)
    amount -= int(amount/20)*20
if int(amount/10):
    count+=int(amount/10)
    amount -= int(amount/10)*10
if int(amount/5):
    count+=int(amount/5)
    amount -= int(amount/5)*5
count+=amount
print(count)
```
