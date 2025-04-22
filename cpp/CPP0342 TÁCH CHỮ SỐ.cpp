#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    cin >> s;

    vector<int> A(27);
    int total = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            total += s[i] - '0';
        }
        else
        {
            A[s[i] - 'A']++;
        }
        
    }
    
    for (int i = 0; i < 27; i++)
    {
        while (A[i] > 0)
        {
            char c = i + 'A';
            cout << c;
            A[i]--;
        }
    }
    
    cout << total;
    
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