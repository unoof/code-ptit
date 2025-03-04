#include <bits/stdc++.h>
using namespace std;


void submit()
{
    char a;
    cin >> a;
    if (a > 96)
    {
        a = toupper(a);
        cout << a << endl;

    }
    else
    {
        a = towlower(a);
        cout << a << endl;

    }
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}