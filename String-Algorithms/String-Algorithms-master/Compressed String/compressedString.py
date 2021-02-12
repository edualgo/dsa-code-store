class solution:
    def compressedString(self,input1):
        mapp = {}
        output = ""
        for i in range(len(input1)):
            key = input1[i]
            if(key in mapp.keys()):
                mapp[key]+=1
            else:
                mapp.update({key:1})
        for key in mapp.keys():
            output = output + key + str(mapp[key])
        if(len(output) <= len(input1)):
            return output
        else:
            return input1

input1 = input()
sol = solution()
print(sol.compressedString(input1))
