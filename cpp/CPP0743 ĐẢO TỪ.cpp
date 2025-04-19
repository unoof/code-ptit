#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;
    stack<string> out;

    while (ss >> word)
    {
        out.push(word);
    }
    
    while (out.empty() == false)
    {
        cout << out.top() << " ";
        out.pop();
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