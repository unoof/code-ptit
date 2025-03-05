#include <bits/stdc++.h>
using namespace std;


void submit()
{
    long long num;
    cin >> num;

    cout << 1 + (num - 1)%9;                                        // Use modulo of 9

    cout << endl;
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