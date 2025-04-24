#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    vector<int> temp;
    for (auto &&i : A)
    {
        temp.push_back(abs(m - i));
    }
    
    sort(temp.begin(), temp.end());
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (abs(m - A[j]) == temp[i])
            {
                cout << A[j] << " ";
                A.erase(A.begin() + j);
                break;
            }
        }
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