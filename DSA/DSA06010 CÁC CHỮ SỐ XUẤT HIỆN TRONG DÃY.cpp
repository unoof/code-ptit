#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);

    vector<bool> check(11, false);
    for (auto &&i : s)
    {
        if (isdigit(i)) check[i-'0'] = true;
    }
    
    for (int i = 0; i < 11; i++)
    {
        if (check[i])
        {
            cout << i << " ";
        }
    }
    


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