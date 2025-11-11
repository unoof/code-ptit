#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    
    sort(A.begin(), A.end());
    bool check = false;

    for (int i = 0; i < n-1; i++)
    {
        int l = i+1, r = n-1;

        while (l < r)
        {
            if (A[l] + A[r] < k - A[i])
            {
                l++;
            }
            else if (A[l] + A[r] > k - A[i])
            {
                r--;
            }
            else
            {
                check = true;
                break;
            }
        }
    }
    
    check ? cout << "YES" : cout << "NO";
    
    


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