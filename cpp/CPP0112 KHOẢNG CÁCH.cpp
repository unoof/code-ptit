#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long double A_x, A_y, B_x, B_y;
    cin >> A_x >> A_y >> B_x >> B_y;

    long double x = A_x - B_x, y = A_y - B_y;

    x *= x;
    y *= y;
    

    cout << setprecision(4) << fixed << sqrt(x + y);
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