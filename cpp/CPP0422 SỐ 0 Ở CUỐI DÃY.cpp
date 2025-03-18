#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, count = 0;
    cin >> n;
    
    vector<long long> A;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (a != 0)
        {
            A.push_back(a);
        }
        else
        {
            count++;
        }
        
    }

    for (long long num : A)
    {
        cout << num << "  ";
    }
    
    for (int i = 0; i < count; i++)
    {
        cout << 0 << "  ";
    }
    
    
    cout << endl;
    return;
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