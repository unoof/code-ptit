def prepare():
    save = [[0]*1001 for _ in range(1001)]
    for i in range(1001):
        save[i][0] = save[i][i] = 1
        for j in range(1, i):
            save[i][j] = (save[i-1][j]+save[i-1][j-1])%MOD
    return save

def submit():
    n, k = map(int, input().split())

    print(save[n][k]%MOD)

test = int(input())
MOD = 10**9 +7
save = prepare()
for _ in range(test):
    submit()
