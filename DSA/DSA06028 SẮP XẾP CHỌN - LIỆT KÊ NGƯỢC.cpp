#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;
    vector<vector<int>> res;

    
    for (int i = 0; i < n-1; i++)
    {
        int mini = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }
        swap(A[mini], A[i]);

        res.push_back(A);
    }
    
    for (int i = res.size()-1; i >= 0; i--)
    {
        
        cout << "Buoc " << i+1 << ": ";
        for (auto &&k : res[i]) cout << k << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}