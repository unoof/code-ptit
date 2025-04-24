#include <bits/stdc++.h>
using namespace std;

void check_diff(vector<int> A, vector<int> save, int n)
{
    int start = -1, end = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] != save[i]) 
        {
            if (start == -1)
            {
                start = i;
            }
            else
            {
                end = i;
            }
        }
        
    }
    cout << start+1 << " " << end+1;
}

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> save(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        save[i] = A[i];

    }
    
    sort(A.begin(), A.end());

    check_diff(A, save, n);
    
    
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