#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    cin >> s;

    vector<int> A;

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);

        if (s[i] >= 'A' && s[i] <= 'C')
        {
            A.push_back(2);
        }
        else if (s[i] >= 'D' && s[i] <= 'F')
        {
            A.push_back(3);
        }
        else if (s[i] >= 'G' && s[i] <= 'I')
        {
            A.push_back(4);
        }
        else if (s[i] >= 'J' && s[i] <= 'L')
        {
            A.push_back(5);
        }
        else if (s[i] >= 'M' && s[i] <= 'O')
        {
            A.push_back(6);
        }
        else if (s[i] >= 'P' && s[i] <= 'S')
        {
            A.push_back(7);
        }
        else if (s[i] >= 'T' && s[i] <= 'V')
        {
            A.push_back(8);
        }
        else
        {
            A.push_back(9);
        }
    }

    int size = A.size();
    

    for (int i = 0; i <= size/2; i++)
    {
        if (A[i] != A[size - i-1])
        {
            cout << "NO" << endl;
            return;
        }
        
    }
    cout << "YES";

    
    
    
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