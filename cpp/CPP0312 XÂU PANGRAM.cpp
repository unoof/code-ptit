#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string str;
    cin >> str;

    int step;
    cin >> step;

    int count {0};
    vector<bool> alphabet(26, false);

    for (int i = 0; i < str.length(); i++)
    {
        if (!alphabet[str[i]-97])
        {
            alphabet[str[i]-97] = true;
            count++;
        }
    }
    
    if (26 - count > step)
    {
        cout << 0;
    }
    else
    {
        cout << 1;
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
    cin.ignore();


    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}