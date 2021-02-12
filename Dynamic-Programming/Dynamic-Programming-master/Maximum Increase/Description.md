## Description

### 📈 Maximum Increase Problem

<b>Problem Statement :</b> You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

<b>The Dynamic Approach:</b>

```cpp
typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    ll* arr2 = new ll[n];
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    arr2[0] = 1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i] > arr[i-1])
        {
            arr2[i] = arr2[i-1]+1;
        }
        else
        {
            arr2[i] = 1;
        }
    }
    sort(arr2,arr2+n);
    cout << arr2[n-1] << endl;
    return 0;
}
```
    
<b>The Python Approach</b>

```python3
n = int(input())
arr = list(map(int,input().split()))


arr2 = [1] * n

for i in range(1,n):
    if arr[i] > arr[i-1]:
        arr2[i] = arr2[i-1]+1
arr2.sort()
print(arr2[n-1])
```
