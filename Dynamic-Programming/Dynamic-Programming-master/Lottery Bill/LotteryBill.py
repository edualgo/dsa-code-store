amount = int(input())
count = 0

if int(amount/100):
    count+=int(amount/100)
    amount -= int(amount/100)*100
if int(amount/20):
    count+=int(amount/20)
    amount -= int(amount/20)*20
if int(amount/10):
    count+=int(amount/10)
    amount -= int(amount/10)*10
if int(amount/5):
    count+=int(amount/5)
    amount -= int(amount/5)*5
count+=amount
print(count)
