#include <bits/stdc++.h>
using namespace std;

int n;
void recursion(vector<int> store, vector<bool> placed, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (!placed[i])
        {
            store[j] = i;
            placed[i] = true;

            if (j == n-1)
            {
                for (auto &&k : store)
                {
                    cout << char(k+'A');
                }
                cout << " ";
            }
            else
            {
                recursion(store, placed, j+1);
            }
            placed[i] = false;
        }
    }
}

void submit()
{
    string A;
    cin >> A;
    n = A.size();
    vector<int> store(n);
    vector<bool> placed(n, false);

    recursion(store, placed, 0);
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