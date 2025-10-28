#include <bits/stdc++.h>
using namespace std;

int k = 0;

bool cmp(int a, int b)
{
    return abs(k - a) < abs(k - b);
}

void submit()
{
    int n;
    cin >> n >> k;
    
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    stable_sort(A.begin(), A.end(), cmp);

    for (auto &&i : A)
    {
        cout << i << " ";
    }
    



    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();
    
    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}