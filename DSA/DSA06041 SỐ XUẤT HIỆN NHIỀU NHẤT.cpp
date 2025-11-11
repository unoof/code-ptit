#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    unordered_map<int,int> A;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A[temp]++;
    }
    
    int maxi = 0, now = 0;
    for (auto &&i : A)
    {
        if (maxi < i.second)
        {
            maxi = i.second;
            now = i.first;
        }
    }
    
    maxi > n/2 ? cout << now : cout << "NO";
    


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