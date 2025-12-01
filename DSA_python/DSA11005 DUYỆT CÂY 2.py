def post_order(InL, InR, In, lvl, pos):
    if InL > InR or not lvl: return

    index = pos[lvl[0]]
    k = In[index]

    lvlL = list()
    lvlR = list()

    for i in lvl:
        if i in In[InL:index]:
            lvlL.append(i)
        elif i in In[index+1:InR]:
            lvlR.append(i)
    
    post_order(InL, index, In, lvlL, pos)
    post_order(index+1, InR, In, lvlR, pos)

    print(k, end=" ")

def submit():
    n = int(input())
    In = list(map(int, input().split()))
    lvl = list(map(int, input().split()))

    pos = dict()
    for i in range(n):
        pos[In[i]] = i
    
    post_order(0, n, In, lvl, pos)
    print()








test = int(input())
for i in range(test):
    submit()