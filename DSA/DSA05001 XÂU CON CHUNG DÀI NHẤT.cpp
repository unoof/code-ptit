#include <bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>> &mem, string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0) return 0;

    if (mem[n][m] != -1)
    {
        return mem[n][m];
    }
    
    if (s1[n-1] == s2[m-1])
    {
        return mem[n][m] = 1 + recursion(mem, s1, s2, n-1, m-1);
    }
    
    return mem[n][m] = max(recursion(mem, s1, s2, n-1, m), recursion(mem, s1, s2, n, m-1));
}

void submit()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> mem (s1.size()+1, vector<int>(s2.size()+1, -1));

    cout << recursion(mem, s1, s2, s1.size(), s2.size());

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