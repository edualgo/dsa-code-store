class solution:
    def isUnique(self,input_string):
        mapp = []
        for i in input_string:
            if i not in mapp:
                mapp.append(i)
        return len(mapp) == len(input_string)

input1 = str(input())
sol = solution()
print(sol.isUnique(input1))
