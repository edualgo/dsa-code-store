n = int(input())
arr = list(map(int,input().split()))


arr2 = [1] * n

for i in range(1,n):
    if arr[i] > arr[i-1]:
        arr2[i] = arr2[i-1]+1
arr2.sort()
print(arr2[n-1])
