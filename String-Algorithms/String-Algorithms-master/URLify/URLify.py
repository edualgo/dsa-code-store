class solution:
    def URLify(self,input_str,key):
        input2 = ""
        for i in range(len(input_str)):
            if(input_str[i] != ' '):
                input2+=input_str[i]
            elif((input_str[i]==' ') and (input_str[i+1] == ' ')):
                return input2
            elif((input_str[i]==' ') and (input_str[i+1] != ' ')):
                input2 += key
        return input2

input1 = str(input())
key = str(input())
sol = solution()
print(sol.URLify(input1,key))
