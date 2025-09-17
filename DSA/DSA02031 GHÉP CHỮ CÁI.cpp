#include <bits/stdc++.h>
using namespace std;

int n;

bool is_consonant(char a)
{
    return a == 'A' || a == 'E';
}

bool check(vector<char> &A)
{
    for (int i = 1; i < A.size()-1; i++)
    {
        if (A[i] == 'E' || A[i] == 'A')
        {
            if (!is_consonant(A[i-1]) && !is_consonant(A[i+1]))
            {
                return false;
            }
        }
    }
    return true;
}

void recursion(vector<char> store, vector<bool> &placed, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (!placed[i])
        {
            store[j] = 'A'+i;
            placed[i] = true;

            if (j == n-1)
            {
                if (check(store))
                {
                    for (auto &&k : store)
                    {
                        cout << char(k);
                    }
                    cout << endl;
                }
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
    char c;
    cin >> c;
    n = c-'A'+1;
    vector<char> store(n);
    vector<bool> placed(n, false);
    
    recursion(store, placed, 0);
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}