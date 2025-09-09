#include <bits/stdc++.h>
using namespace std;

void recursion(vector<char> &A, char c, int k, int i, int deep)
{
    if (deep == A.size())
    {
        for (auto &&i : A)
        {
            cout << i;
        }
        cout << endl;
    }
    else
    {
        A[deep] = A[deep-1];
        while (A[deep] != c+1)
        {
            recursion(A, c, k, i, deep+1);
            A[deep]++;
        }
    }
    
}

void submit()
{
    char c;
    int k;
    cin >> c >> k;
    
    
    for (int i = 0; i <= c-'A'; i++)
    {
        vector<char> A(k, 'A' + i);
        recursion(A, c, k, i, 1);
    }
    
    

}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}