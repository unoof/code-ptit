#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int start = 1;
    int end = k;
    int max = -1;
    
    for (int i = 0; i < end; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    ans.push_back(max);

    while (end < n)
    {
        if (A[start-1] == max)
        {
            max = -1;
            for (int i = start; i <= end; i++)
            {
                if (A[i] > max)
                {
                    max = A[i];
                }
            }
        }
        else if (A[end] > max)
        {
            max = A[end];
        }
        
        ans.push_back(max);
        start++;
        end++;
    }
    
    for (auto &&i : ans)
    {
        cout << i << " ";
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