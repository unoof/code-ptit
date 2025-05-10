#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(k);

    for (int i = 1; i <= k; i++)
    {
        A[i-1] = i;
    }
    while(true)
    {
        for (auto &&i : A)
        {
            cout << i;
        }
        cout << " ";
        
        int i = k-1;
        while (A[i] == n-k+i+1)
        {
            i--;
        }

        if (i < 0)
        {
            break;
        }

        A[i]++;
        for (int j = i+1; j < k; j++)
        {
            A[j] = A[i] + j - i;
        }
        
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