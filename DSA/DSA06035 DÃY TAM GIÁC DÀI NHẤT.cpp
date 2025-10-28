#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    
    int count = 1, maxi = -1;
    bool down = false, up = false;
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] < A[i+1])
        {
            if (down)
            {
                maxi = max(count, maxi);
                count = 2;
                down = false;
            }
            else
            {
                count++;
                up = true;
            }
        }
        else if (A[i] > A[i+1] && up)
        {
            count++;
            down = true;
        }
        else if (A[i] == A[i+1])
        {
            maxi = max(maxi, count);
            count = 1;
            up = down = false;
        }
    }
    
    cout << max(maxi, count);
    
    


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