class solution:
    def setZeros(self,matrix,row,column):
        row_arr = [False] * row
        col_arr = [False] * column
        for i in range(row):
            for j in range(column):
                if(matrix[i][j] == 0):
                    row_arr[i] = True
                    col_arr[j] = True

        for i in range(row):
            if(row_arr[i]):
                for j in range(column):
                    matrix[i][j] = 0

        for i in range(column):
            if(row_arr[i]):
                for j in range(row):
                    matrix[j][i] = 0

row = int(input())
column = int(input())
matrix = []
for i in range(row):
    a =[]
    for j in range(column):
         a.append(int(input()))
    matrix.append(a)

sol = solution()
sol.setZeros(matrix,row,column)

for i in range(row):
    for j in range(column):
        print(matrix[i][j], end = " ")
    print()
