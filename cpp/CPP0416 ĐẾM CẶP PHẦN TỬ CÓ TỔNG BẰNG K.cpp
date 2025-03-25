#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, k, count {0};
    cin >> n >> k;

    vector<int> A;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    
    for (int i = 0; i < n-1; i++)
    {
        int temp = k - A[i];
        for (int j = i+1; j < n; j++)
        {
            if (A[j] == temp)
            {
                count++;
            }
            
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