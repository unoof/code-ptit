#include <bits/stdc++.h>
using namespace std;

long long count(int a)
{
    long long total {1};
    while (a > 0)
    {
        total *= a;
        a--;
    }
    return total;
}

void submit()
{
    int a;
    long long total {0};
    cin >> a;
    
    for (int i = 1; i <= a; i++)
    {
        total += count(i);
    }
    
    cout << total << endl;

}

int main()
{
    ios::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);

    submit();

    return 0;
}