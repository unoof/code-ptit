#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &A, vector<int> &B, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i] && A[i] != B[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    vector<int> B(A.begin(), A.end());
    
    sort(B.begin(), B.end());

    check(A, B, n) ? (cout << "Yes") : (cout << "No");
    

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}