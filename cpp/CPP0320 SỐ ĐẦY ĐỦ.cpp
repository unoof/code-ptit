#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string num;
    cin >> num;

    vector<bool> A(10, false);

    if (num[0] - '0' == 0)
    {
        cout << "INVALID" << endl;
        return;
    }
    
    
    for (auto &&i : num)
    {
        if (!isdigit(i))
        {
            cout << "INVALID" << endl;
            return;
        }
        else
        {
            A[i-'0'] = true;
        }
    }
    
    for (bool i : A)
    {
        if (!i)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES";
    
    
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