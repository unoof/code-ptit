#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string str;
    cin >> str;

    int last {0}, count {0};

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[last])
        {
            count++;
        }
        else
        {
            cout << str[last] << count;
            last = i;
            count = 1;
        }
    }

    cout << str[str.length() - 1] << count;
    
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