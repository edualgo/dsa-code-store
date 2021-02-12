class solution:
    def rotateImage(self,img_arr,n):
        for layer in range(int(n/2)):
            first = layer
            last = n-1-layer
            for i in range(first,last):
                offset = i - first
                top = img_arr[first][i]
                img_arr[first][i] = img_arr[last - offset][first]
                img_arr[last - offset][first] = img_arr[last][last - offset]
                img_arr[last][last - offset] = img_arr[i][last]
                img_arr[i][last] = top

n = int(input())
matrix = []
for i in range(n):          # A for loop for row entries
    a =[]
    for j in range(n):      # A for loop for column entries
         a.append(int(input()))
    matrix.append(a)

sol = solution()
sol.rotateImage(matrix,n)
for i in range(n):
    for j in range(n):
        print(matrix[i][j], end = " ")
    print()
