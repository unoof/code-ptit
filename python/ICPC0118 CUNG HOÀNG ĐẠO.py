temp = ["Ma Ket", "Bao Binh", "Song Ngu", "Bach Duong", "Kim Nguu", "Song Tu", "Cu Giai", "Su Tu", "Xu Nu", "Thien Binh", "Thien Yet", "Nhan Ma"]

A = [
    19,
    18,
    20,
    19,
    20,
    20,
    22,
    22,
    22,
    22,
    22,
    21,
]

def submit():
    d, m = map(int, input().split())
    
    day= A[m-1]

    if day >= d:
        print(temp[m-1])
    else:
        print(temp[m%12])



test = int(input())
for i in range(test):
    submit()