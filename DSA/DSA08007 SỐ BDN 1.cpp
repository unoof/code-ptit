#include <bits/stdc++.h>
using namespace std;

int to_int(string s)
{
    int n = 0;
    for (auto &&i : s)
    {
        n = n*2;
        if (i == '1')
        {
            n++;
        }
    }
    return n;
}

void submit()
{
    string s;
    cin >> s;
    bool check = false;

    for (auto &&i : s)
    {
        if (i - '0' > 1 || check)
        {
            i = '1';
            check = true;
        }
    }
    
    cout << to_int(s) << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();
    
    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}