#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void submit()
{
    int n;
    cin >> n;

    vector<pair<int,int>> A(n);
    for (auto &&i : A)
    {
        cin >> i.first >> i.second;
    }
    
    sort(A.begin(), A.end(), cmp);
    
    int prev = 0, count = 1;
    
    for (int i = 1; i < n; i++)
    {
        if (A[i].first >= A[prev].second)
        {
            prev = i;
            count++;
        }
    }
    
    cout << count;

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