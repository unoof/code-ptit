#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);
    stack<char> A;
    bool check = true;

    if (s[0] == ')' || s[0] == ']' || s[0] == '}')
    {
        cout << "NO" << endl;
        return;
    }
    
    
    for (auto &&i : s)
    {
        switch (i)
        {
        case ')':
            if (!A.empty())
            {
                if (A.top() != '(') check = false;
                else A.pop();
            }
            break;
        case ']':
            if (!A.empty())
            {
                if (A.top() != '[') check = false;
                else A.pop();
            }
            break;
        case '}':
            if (!A.empty())
            {
                if (A.top() != '{') check = false;
                else A.pop();
            }
            break;
        default:
            A.push(i);
            break;
        }
        if (!check)
        {
            break;
        }
    }
    

    check ? cout << "YES" : cout << "NO";

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