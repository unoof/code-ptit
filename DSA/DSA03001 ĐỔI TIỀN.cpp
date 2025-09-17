#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 0;
    cin >> n;
    int A[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

    for (int i = 9; i >= 0; i--)
    {
        if (A[i] <= n)
        {
            count += n / A[i];
            n %= A[i];
        }
    }
    
    cout << count << endl;
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