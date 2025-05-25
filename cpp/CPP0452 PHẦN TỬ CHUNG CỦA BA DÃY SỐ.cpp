#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int x, y, z, i = 0, j = 0, k = 0;
    cin >> x >> y >> z;

    vector<long long> A(x), B(y), C(z);
    set<long long> out;
    for (auto &&i : A)  cin >> i;
    for (auto &&i : B)  cin >> i;
    for (auto &&i : C)  cin >> i;

    bool check = false;
    while (i < x && j < y && k < z)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            out.insert(A[i]);
            check = true;
            i++, j++, k++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else if (B[j] > C[k])
        {
            k++;
        }
        else
        {
            i++;
        }
    }
    
    if (check)
    {
        for (auto &&i : out)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1;
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