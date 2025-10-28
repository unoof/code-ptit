#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    set<int> A;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.insert(temp);
    }
    
    vector<int> B(A.begin(), A.end());
    if (B.size() == 1)
    {
        cout << -1;
    }
    else
    {
        cout << B[0] << " " << B[1];
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