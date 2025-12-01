#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);

    stack<int> A;
    int count = 0;

    for (auto &&i : s)
    {
        if (!A.empty() && 
            (i == ')' && A.top() == '(')||
            (i == ']' && A.top() == '[')||
            (i == '}' && A.top() == '{'))
        {
            A.pop();
        }
        else
        {
            switch (i)
            {
            case ')':
                A.push('(');
                count++;
                break;
            case ']':
                A.push('[');
                count++;
                break;
            case '}':
                A.push('{');
                count++;
                break;
            default:
                A.push(i);
                break;
            }
        }
    }
    
    cout << count + A.size()/2;
    

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