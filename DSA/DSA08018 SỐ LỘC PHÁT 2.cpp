#include <bits/stdc++.h>
using namespace std;

string to_6(string s)
{
    for (auto &&i : s)
    {
        i = '6';
    }
    return s;
}

void submit()
{
    int n;
    cin >> n;

    queue<string> A;
    vector<string> ans;
    A.push("6");
    A.push("8");
    string s = "6";
    
    while (A.front().size() <= n)
    {
        s = A.front();
        A.pop();
        ans.push_back(s);
        A.push(s+"6"), A.push(s+"8");
    }
    
    cout << ans.size() << endl;
    for (auto &&i : ans) cout << i << " ";
    
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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