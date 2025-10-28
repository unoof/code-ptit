#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
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