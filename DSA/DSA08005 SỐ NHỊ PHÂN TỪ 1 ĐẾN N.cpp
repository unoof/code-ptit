#include <bits/stdc++.h>
using namespace std;

string to_binary(int n)
{
    string s;
    while (n != 0)
    {
        s = to_string(n%2) + s;
        n /= 2;
    }
    return s;
}

void submit()
{
    int n;
    cin >> n;    
    
    for (int i = 1; i <= n; i++)
    {
        cout << to_binary(i) << " ";
    }
    cout << endl;
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