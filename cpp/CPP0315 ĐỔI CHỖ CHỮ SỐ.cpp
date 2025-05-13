#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<int> A;

    for (int i = 0; i < n; i++)
    {
        int temp = s[i] - '0';
        A.push_back(temp);
    }
    
    int i = n-2;
    while (A[i] <= A[i+1])
    {
        i--;
    }

    if (i >= 0)
    {
        int k = n-1;
        while (A[i] <= A[k])
        {
            k--;
        }

        while (A[k] == A[k-1])
        {
            k--;
        }
        
        if (i == 0 && A[k] == 0)
        {
            cout << -1;
        }
        else
        {
            swap(A[i], A[k]);
            
            for (auto &&i : A)
            {
                cout << i;
            }
        }
    }
    else
    {
        cout << -1;
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