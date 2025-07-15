#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    int B[n], index = 0;
    for (int i = 0; i < n; i += 2)
    {
        B[i] = A[index++];
    }

    for (int i = 1; i < n; i += 2)
    {
        B[i] = A[index++];
    }

    for (auto &&i : B)
    {
        cout << i << " ";
    }
    


    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    cin.ignore();

    while (test--)
    {
        submit();
    }
    
    return 0;
}