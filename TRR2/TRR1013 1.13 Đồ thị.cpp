#include <bits/stdc++.h>
using namespace std;

void option1(vector<vector<int>> &A, int n)
{
    vector<pair<int,int>> temp(n, {0,0});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                temp[i].first++;
                temp[j].second++;
            }
        }
    }

    for (auto &&i : temp)
    {
        cout << i.second << " " << i.first << endl;
    }
}

void option2(vector<vector<int>> &A, int n)
{
    cout << n << endl;
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                count++;
                temp.push_back(j);
            }
        }
        
        cout << count;
        for (auto &&k : temp)
        {
            cout << " " << k+1;
        }
        cout << endl;
    }
    
}

void submit()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int n, s;
    cin >> s >> n;
    

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    
    

    if (s == 1)
    {
        option1(A, n);
    }
    else
    {
        option2(A, n);
    }
}

int main()
{
    submit();
    return 0;
}