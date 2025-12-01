def post_order(inL, inR, preL, preR, In, pre, pos):
    if inL > inR or preL > preR:
        return
    
    root = pre[preL]
    k = pos[root]
    left_size = k-inL

    post_order(inL, k-1, preL+1, preL+left_size, In, pre, pos)
    post_order(k+1, inR, preL+left_size+1, preR, In, pre, pos)
    print(In[k], end=" ")

def submit():
    n = int(input())
    In = list(map(int, input().split()))
    Pre = list(map(int, input().split()))

    pos = dict()
    for i in range(n):
        pos[In[i]] = i
    
    post_order(0, n-1, 0, n-1, In, Pre, pos)
    print()





test = int(input())
for i in range(test):
    submit()