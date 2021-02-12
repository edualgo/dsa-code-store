class solution:
    def isPalindromicPermutation(self,input1):
        mapp = {}
        for i in range(len(input1)):
            key = input1[i]
            if(key in mapp.keys()):
                mapp[key] += 1
            else:
                mapp.update({key:1})
        flag = 0
        for i in mapp.keys():
            if(mapp[i] %2 == 1):
                flag+=1
        return flag<=1


sol = solution()
input1 = str(input())
print(sol.isPalindromicPermutation(input1))
