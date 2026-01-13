n = input()

count = 0
for i in n:
    if i.isupper() is True:
        count+=1
    else:
        count-=1

print(n.upper() if count > 0 else n.lower())