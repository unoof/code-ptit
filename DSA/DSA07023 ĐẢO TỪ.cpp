#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);

    stringstream ss(s);
    string words;
    stack<string> temp;
    
    while (ss >> words)
    {
        temp.push(words);
    }
    
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
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