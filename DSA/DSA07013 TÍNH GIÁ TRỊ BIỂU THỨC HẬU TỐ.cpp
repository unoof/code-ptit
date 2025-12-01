#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);

    string temp = "+/*-";
    stack<int> A;

    for (int i = 0; i < s.size(); i++)
    {
        if (temp.find(s[i]) == string::npos)
        {
            A.push(s[i]-'0');
        }
        else
        {
            int b = A.top(); A.pop();
            int a = A.top(); A.pop();

            switch (s[i])
            {
            case '+':
                A.push(a + b);
                break;
            case '-':
                A.push(a - b);
                break;
            case '*':
                A.push(a * b);
                break;
            case '/':
                A.push(a / b);
                break;
            }
        }
    }
    
    cout << A.top();

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