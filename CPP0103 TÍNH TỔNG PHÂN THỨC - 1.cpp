#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long double num, total {0};
    cin >> num;
    

    for (long double i = 1; i <= num; i++)
    {
        total += 1/i;
    }
    
    cout << setprecision(4) << fixed << total;

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);

    submit();

    return 0;
}