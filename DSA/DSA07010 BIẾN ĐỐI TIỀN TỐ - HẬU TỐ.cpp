#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);

    string temp = "+/*-";
    stack<string> A;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (temp.find(s[i]) == string::npos)
        {
            A.push(string(1, s[i]));
        }
        else
        {
            string a = A.top(); A.pop();
            string b = A.top(); A.pop();

            A.push(a + b + s[i]);
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