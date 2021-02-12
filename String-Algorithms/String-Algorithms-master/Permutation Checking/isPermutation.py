class solution:
    def isPermutation(self,input1,input2):
        mapp1 = []
        mapp2 = []
        for i in input1:
            if i not in mapp1:
                mapp1.append(i)
        for j in input2:
            if j not in mapp2:
                mapp2.append(j)
        mapp1.sort()
        mapp2.sort()
        return mapp1==mapp2

input1 = str(input())
input2 = str(input())
sol = solution()
print(sol.isPermutation(input1,input2)))
