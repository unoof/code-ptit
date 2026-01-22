def count_digits(n):
    if n == 0:
        return [0] * 10
    s = str(n)
    length = len(s)
    count = [0] * 10
    for i in range(length):
        left = int(s[:i]) if i > 0 else 0
        curr = int(s[i])
        right = int(s[i + 1:]) if i < length - 1 else 0
        power = 10 ** (length - i - 1)
        for d in range(10):
            if d < curr:
                count[d] += (left + 1) * power
            elif d == curr:
                count[d] += left * power + right + 1
            else:
                count[d] += left * power
        count[0] -= power
    return count

def submit():
    a, b = map(int, input().split())
    
    count_a = count_digits(a-1) if a > 1 else [0]*10
    count_b = count_digits(b)
    res = [b - a for a, b in zip(count_a, count_b)]
    print(*res)








test = int(input())
for i in range(test):
    submit()