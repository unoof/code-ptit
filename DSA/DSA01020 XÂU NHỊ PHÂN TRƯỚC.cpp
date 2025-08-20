#include <bits/stdc++.h>
using namespace std;

void update(string &A)
{
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (A[i] == '1')
        {
            A[i] = '0';
            return;
        }
        A[i] = '1';
    }
}

void submit()
{
    string A;
    cin >> A;
    
    update(A);
    for (auto &&j : A)
    {
        cout << j;
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