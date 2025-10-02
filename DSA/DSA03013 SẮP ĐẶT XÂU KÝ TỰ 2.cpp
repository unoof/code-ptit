#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int d;
    string s;
    cin >> d >> s;

    vector<int> alpha(127);
    int max_num = 0;
    for (auto &&i : s)
    {
        alpha[i]++;
        max_num = max(max_num, alpha[i]);
    }
    int max = (s.length()+1)/d;

    max_num <= max ? (cout << 1) : (cout << -1);
    
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