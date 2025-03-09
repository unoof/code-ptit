#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    vector<bool> check(1000, false);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        check[A[i]] = true;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {
        if (check[A[i]] == true)
        {
            cout << A[i] << " ";
            check[A[i]] = false;
        }
        
    }
    
    
    
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}