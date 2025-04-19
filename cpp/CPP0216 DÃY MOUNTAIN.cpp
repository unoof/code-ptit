#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int> A, int start, int end)
{
    int max = -1;
    for (int i = start; i <= end; i++)
    {
        if (A[i] > A[max])
        {
            max = i;
        }
        
    }
    return max;
}

bool check_mountain(vector<int> A, int max, int start, int end)
{
    for (int i = max; i <= end - 1; i++)
    {
        if (A[i] < A[i+1])
        {
            return false;
        }
        
    }
    
    for (int i = start; i < max; i++)
    {
        if (A[i] > A[i+1])
        {
            return false;
        }
        
    }
    return true;
}

void submit()
{
    int n, start, end;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> start >> end;

    int max = maximum(A, start, end);

    check_mountain(A, max, start, end) ? (cout << "Yes") : (cout << "No");
    
    
    cout << endl;
}



int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}