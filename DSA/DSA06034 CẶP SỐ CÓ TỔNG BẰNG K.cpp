#include <bits/stdc++.h>
using namespace std;

long long check(vector<long long> &A, int n, int k)
{
    unordered_map<long long, long long> temp;
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        int need = k-A[i];
        if (temp.find(need) != temp.end())
        {
            count += temp[need];
        }
        temp[A[i]]++;
    }
    
    return count;
}

void submit()
{
    int n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (auto &&i : A) cin >> i;
    
    
    cout << check(A, n, k);
    


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