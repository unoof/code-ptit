#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, max = -101, stored = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        stored += temp;
        if (stored < temp)
        {
            stored = temp;
        }
        
        if (stored > max)
        {
            max = stored;
        }
    }

    cout << max;

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