#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }

    sort(A.begin(), A.end(), __greater_equal());

    priority_queue<long long> pq;

    long long var1 = A[0]*A[1], var2 = A[n-1]*A[n-2]*A[0], var3 = A[n-1]*A[n-2];
    pq.push(var1);    pq.push(var2);    pq.push(var3);

    pq.push(var1*A[2]);
    cout << pq.top();
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}