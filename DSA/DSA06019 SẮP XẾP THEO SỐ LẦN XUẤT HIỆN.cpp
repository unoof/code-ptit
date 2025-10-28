#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &A, pair<int,int> &B)
{
    return A.second == B.second ? A.first < B.first : A.second > B.second; 
}

void submit()
{
    int n;
    cin >> n;
    unordered_map<int, int> A;
    vector<pair<int,int>> res;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A[temp]++;
    }
    
    for (auto &&i : A)
    {
        res.push_back(i);
    }
    
    sort(res.begin(), res.end(), cmp);
    
    
    for (auto &&i : res)
    {
        while (i.second > 0)
        {
            cout << i.first << " ";
            i.second--;
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