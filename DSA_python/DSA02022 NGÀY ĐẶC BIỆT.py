def submit():
    d = ""

    def out(d, y):
        if d == "00":
            return
        
        print(d+"/02/"+y)

    def year(d, y):
        if len(y) == 4:
            out(d, y)
            return
        
        for i in range(3):
            if i == 1:
                continue
            
            y += str(i)
            year(d, y)
            y = y[:-1]

    def days(d):
        if len(d) == 2:
            y = "2"
            year(d, y)
            return
        
        for i in range(3):
            if i == 1:
                continue
            
            d += str(i)
            days(d)
            d = d[:-1]
    days(d)


submit()