#include <bits/stdc++.h>
using namespace std;

void update(string &s, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
            break;
        }
        s[i] = '0';
    }
}

void submit()
{
    string s;
    cin >> s;

    update(s, s.size());
    cout << s << endl;
}   

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
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