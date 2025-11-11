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

    vector<string> A(1, "6");
    string s = "6";

    while (s.size() <= n)
    {
        bool check = false;
        for (int j = s.size() - 1; j >= 0; j--)
        {
            if (s[j] == '6')
            {
                s[j] = '8';
                check = true;
                break;
            }
            s[j] = '6';
        }
        if (!check)
        {
            s = to_6(s) + "6";
        }
        A.push_back(s);
    }
    

    for (int i = A.size() - 2; i >= 0; i--)
    {
        cout << A[i] << " ";
    }
    
    
    
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