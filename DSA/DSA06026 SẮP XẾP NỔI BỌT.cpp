#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    for (int i = 0; i < n; i++)
    {
        bool check = false;
        for (int j = 0; j < n-1; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                check = true;
            }
        }
        
        if (!check)
        {
            break;
        }
        
        cout << "Buoc " << i+1 << ": ";
        for (auto &&k : A) cout << k << " ";
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