#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);

    stack<int> A;
    A.push(-1);
    int maxi = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            A.push(i);
        }
        else
        {
            if ((!A.empty() && A.top() != -1 &&
               ((c == ')' && s[A.top()] == '(')||
                (c == ']' && s[A.top()] == '[')||
                (c == '}' && s[A.top()] == '{'))))
            {
                A.pop();
                maxi = max(maxi, i-A.top());
            }
            else
            {
                A.push(i);
            }
        }
    }
    
    
    cout << maxi;

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