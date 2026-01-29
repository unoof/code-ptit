from datetime import datetime

class human:
    def __init__(self, name, phone, date):
        self.name = name
        self.phone = phone
        self.date = date
    
    def __str__(self):
        return f"{self.name}: {self.phone} {self.date.day}/{self.date.month}/{self.date.year}"

def submit():
    A = []
    try:
        date_now = datetime.strptime(st.readline().strip(), "Ngay %d/%m/%Y")
        while True:
            temp = st.readline().strip()
            if temp[0].isalpha() and temp[-1].isdigit():
                date_now = datetime.strptime(temp, "Ngay %d/%m/%Y")
                temp = st.readline().strip()
            name = temp
            phone = st.readline().strip()

            A.append(human(name, phone, date_now))
    except:
        pass

    dt.write("\n".join(map(str, A)))


with open("SOTAY.txt", 'r') as st, open("DIENTHOAI.txt", 'w') as dt:
    submit()