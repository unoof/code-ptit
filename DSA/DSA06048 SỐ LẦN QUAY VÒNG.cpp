#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    int count = 1;
    bool check = false;
    cin >> A[0];

    for (int i = 1; i < n; i++)
    {
        cin >> A[i];
        if (A[i] >= A[i-1] && !check)
        {
            count++;
        }
        else
        {
            check = true;
        }
        
    }
    
    check ? cout << count : cout << 0;
    

    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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