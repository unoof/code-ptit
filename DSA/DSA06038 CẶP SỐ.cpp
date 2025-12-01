#include <bits/stdc++.h>
using namespace std;

long long count_inversion(vector<int> &A)                                 //using merge sort
{
    if (A.size() <= 1) return 0;
    int mid = A.size()/2;

    vector<int> L(A.begin(), A.begin()+mid);
    vector<int> R(A.begin()+mid, A.end());
    long long inv = count_inversion(L) + count_inversion(R);

    int i = 0, j = 0, k = 0;
    while (i < L.size() && j < R.size())
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            inv += (long long)L.size()-i;
            A[k++] = R[j++];
        }
    }
    
    while (i < L.size()) A[k++] = L[i++];
    while (j < R.size()) A[k++] = R[j++];
    
    return inv;
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n), evens;
    for (auto &&i : A)
    {
        cin >> i;
        if (i%2 == 0) evens.push_back(i);
    }
    
    long long inv = count_inversion(evens), sub = 0;

    for (int i = 0; i < n;)
    {
        if (A[i]&1)
        {
            i++;
        }
        else
        {
            int j = i;
            vector<int> block;
            while (j < n && A[j]%2 == 0)
            {
                block.push_back(A[j++]);
            }

            if (block.size() > 1)
            {
                sub += count_inversion(block);
            }
            
            i = j;
        }
    }

    cout << inv-sub;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    submit();

    return 0;
}