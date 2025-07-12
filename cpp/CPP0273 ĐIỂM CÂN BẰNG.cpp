#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 1;
    long long left = 0, right = 0;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        right += A[i];
    }
    
    left += A[count-1], right -= A[count-1] + A[count];
    count++;
    
    while (left != right && count < n-1)
    {
        left += A[count-1], right -= A[count];
        count++;
    }
    
    if (left == right)
    {
        cout << count;
    }
    else
    {
        cout << -1;
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