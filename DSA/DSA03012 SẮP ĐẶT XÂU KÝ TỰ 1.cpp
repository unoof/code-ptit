#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    cin >> s;

    vector<int> alpha(26);
    int maxx = 0;
    for (auto &&i : s)
    {
        alpha[i-'a']++;
        maxx = max(maxx, alpha[i-'a']);
    }
    int max = (s.length()+1)/2;
    
    maxx <= max ? (cout << 1) : (cout << -1);
    
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}