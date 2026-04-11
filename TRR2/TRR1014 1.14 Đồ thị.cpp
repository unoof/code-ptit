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
    vector<vector<int>> temp;
    vector<int> sample(n, 0);

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                temp.push_back(sample);
                temp[index][i] = 1; temp[index][j] = -1;
                index++;
            }
        }
    }
    
    cout << n << " " << index << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < index; j++)
        {
            cout << temp[j][i] << " ";
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