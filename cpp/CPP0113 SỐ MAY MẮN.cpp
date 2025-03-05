#include <bits/stdc++.h>
using namespace std;

bool check_lucky_num(long long num)
{
    if (num%100 == 86)
    {
        return true;
    }
    return false;
    
}

void submit()
{
    long long num;
    cin >> num;

    check_lucky_num(num) ? (cout << 1) : (cout << 0);
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