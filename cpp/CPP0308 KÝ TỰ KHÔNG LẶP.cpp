#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string str;
    cin >> str;

    vector<int> check(100, 0);

    for (int i = 0; i < str.length(); i++)
    {
        check[str[i]]++;
    }
    
    for (int i = 0; i < str.length(); i++)
    {
        if (check[str[i]] == 1)
        {
            cout << str[i];
        }
        
    }
    

    cout << endl;
    return;
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