#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, s, m;
    cin >> n >> s >> m;

    if (n < m || (n-m)*6 < m)
    {
        cout << -1;
    }
    else
    {
        cout << ceil((float)m*s/n);
    }


    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}