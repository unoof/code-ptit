from sys import stdin

def char_handler(A):
    if A[0].islower():
        A[0] = A[0].upper()
    
    check_new_line = False
    check_space = False
    uppercase = False
    for i in A:
        if i.isspace():
            if check_space is True:
                continue
            else:
                check_space = True
        else:
            check_space = False
            if check_new_line is True:
                print()
                check_new_line = False
            if uppercase is True:
                i = i.upper()
                uppercase = False
            if i == "." or i == "!" or i == "?":
                check_new_line = True
                uppercase = True
                continue
        
        print(i, end = "")



def submit():
    s = ""
    for line in stdin:
        line.strip()
        s += line
    A = list(s.lower())
    char_handler(A)


submit()