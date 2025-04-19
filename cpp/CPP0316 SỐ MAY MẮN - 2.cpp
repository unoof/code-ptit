#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string num;
    getline(cin , num);
    
    long long total = 0;

    if (num == "0")
    {
        cout << 0 << '\n';
        return;
    }

    for (auto &&temp : num)
    {
        total = (total + temp - '0')%9;
    }
    
    total%9 == 0 ? (cout << 1) : (cout << 0);
    
    cout << endl;
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