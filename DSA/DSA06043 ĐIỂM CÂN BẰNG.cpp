#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, left = 0, right = 0, count = 1;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
        right += i;
    }
    
    left += A[count-1], right -= A[count - 1] + A[count];
    count++;

    while (left != right && count < n)
    {
        left += A[count-1], right -= A[count];
        count++;
    }
    
    left == right ? cout << count : cout << -1;


    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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