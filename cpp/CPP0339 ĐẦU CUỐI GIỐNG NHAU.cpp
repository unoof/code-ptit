#include <bits/stdc++.h>
using namespace std;



void submit()
{
    string s;
    cin >> s;
    
    vector<int> A(26, 0);
    int count = s.size();

    for (int i = 0; i < s.size(); i++)
    {
        A[s[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        while (A[i] > 1)
        {
            count += A[i] - 1;
            A[i]--;
        }
    }
    
    cout << count;

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