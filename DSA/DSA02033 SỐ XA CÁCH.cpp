#include <bits/stdc++.h>
using namespace std;

int n;

void recursion(vector<int> store, vector<bool> &placed, int j)
{
    if (j == n)
    {
        for (auto &&k : store)
        {
            cout << k;
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!placed[i])
        {
            if (j > 0 && abs(store[j-1]-i) == 1) continue;

            store[j] = i;
            placed[i] = true;
            recursion(store, placed, j+1);
            placed[i] = false;
        }
    }
}

void submit()
{
    cin >> n;
    vector<int> store(n);
    vector<bool> placed(n+1, false);
    
    recursion(store, placed, 0);
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