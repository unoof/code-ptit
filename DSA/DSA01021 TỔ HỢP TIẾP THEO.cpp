#include <bits/stdc++.h>
using namespace std;

void change(vector<bool> &A, int n)
{
    if (A[n])
    {
        A[n] = false;
        return;
    }
    A[n] = true;
}

void update(vector<bool> &A, int n, int k)
{
    int i = k, j = n-1;
    while (j > 0)
    {
        if (A[j])
        {
            if (j+1 == n-k+i)
            {
                i--;
            }
            else
            {
                break;
            }
            
        }
        j--;
    }
    if (i != 0)
    {
        A[j] = false;
        change(A, j+1);
        for (int x = j+2; x < j+2+k-i; x++)
        {
            change(A, x);
        }
        
        for (int x = j+2+k-i; x < n; x++)
        {
            A[x] = false;
        }
        for (int x = 0; x < j+1; x++)
        {
            A[x] = false;
        }
    }
}

void submit()
{
    int n, k, count = 0; 
    cin >> n >> k;
    vector<bool> A(n, false);
    
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        A[temp-1] = true;
    }
    
    update(A, n, k);
    for (auto &&i : A)
    {
        if (i)
        {
            count++;
        }
    }
    cout << count << endl;

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