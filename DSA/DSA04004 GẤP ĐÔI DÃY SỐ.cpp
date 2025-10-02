#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 1; long long k;
    cin >> n >> k;

    while (true)
    {
        if (k&1)
        {
            cout << count;
            break;
        }
        k >>= 1;
        count++;
    }



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