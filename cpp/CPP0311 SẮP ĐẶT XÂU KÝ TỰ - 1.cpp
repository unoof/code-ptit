#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> alpha, int max)
{
    for (auto &&i : alpha)
    {
        if (i > max)
        {
            return false;
        }
    }
    return true;
}

void submit()
{
    string s;
    getline(cin, s);

    float len = s.length();
    int max = ceil(len/2);
    vector<int> alpha(26);

    for (auto &&i : s)
    {
        alpha[i - 'a']++;
    }
    
    check(alpha, max) ? (cout << 1) : (cout << 0);
    
    
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    cin.ignore();

    while (test--)
    {
        submit();
    }
    
    return 0;
}