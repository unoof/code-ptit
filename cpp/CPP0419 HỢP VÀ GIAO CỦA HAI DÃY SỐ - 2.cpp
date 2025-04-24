#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    
    set<int> Union;

    for (auto &&i : A)
    {
        Union.insert(i);
    }
    for (auto &&i : B)
    {
        Union.insert(i);
    }
    
    
    set<int> Intersection;

    for (int i = 0; i < n; i++)
    {
        if (find(B.begin(), B.end(), A[i]) != B.end())
        {
            Intersection.insert(A[i]);
        }
        
    }
    
    for (auto &&i : Union)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto &&i : Intersection)
    {
        cout << i << " ";
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