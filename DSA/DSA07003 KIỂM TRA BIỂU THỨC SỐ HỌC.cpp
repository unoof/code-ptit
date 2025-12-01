#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    string temp = "(+-*/";
    stack<char> A;

    for (auto &&i : s)
    {
        if (temp.find(i) != string::npos)
        {
            A.push(i);
        }
        else if (i == ')')
        {
            if (A.top() == '(')
            {
                return true;
            }
            else
            {
                while (A.top() != '(')
                {
                    A.pop();
                }
                A.pop();
            }
        }
    }
    return 0;
}

void submit()
{
    string s;
    getline(cin, s);

    check(s) ? cout << "Yes" : cout << "No";
    

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