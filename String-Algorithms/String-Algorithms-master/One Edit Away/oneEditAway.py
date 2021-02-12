class solution:
    def oneEditAwayInsert(self,input1,input2):
        index1 = 0
        index2 = 0
        while((index2 < len(input2)) and (index1 < len(input1))):
            if(input1[index1] != input2[index2]):
                if(index1 != index2):
                    return False
                index2+=1
            else:
                index1+=1
                index2+=1
        return True

    def oneEditAwayReplace(self,input1,input2):
        flag = False
        for i in range(len(input1)):
            if(input2[i]!=input1[i]):
                if(flag):
                    return False
                flag = True
        return True

    def oneEditAway(self,input1,input2):
        if(len(input1)==len(input2)):
            return self.oneEditAwayReplace(input1,input2)
        elif(len(input1)+1==len(input2)):
            return self.oneEditAwayInsert(input1,input2)
        elif(len(input1)-1==len(input2)):
            return self.oneEditAwayInsert(input2,input1)
        return False

input1 = input()
input2 = input()
sol = solution()
print(sol.oneEditAway(input1,input2))
