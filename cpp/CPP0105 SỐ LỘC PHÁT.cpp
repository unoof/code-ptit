#include <bits/stdc++.h>
using namespace std;

bool check(int num)
{
    while (num > 0)
    {
        int a = num%10;
        num /= 10;
        if (a == 0 || a == 8 || a == 6)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


void submit()
{
    int num;
    cin >> num;
    

    check(num) ? (cout << "YES") : (cout << "NO");
    

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