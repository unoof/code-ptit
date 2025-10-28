#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> prepare()
{
    vector<vector<long long>> save(1001, vector<long long>(1001, 1));

    for (int i = 2; i < 1001; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (j == 1) save[i][j] = i;
            else save[i][j] = (save[i-1][j] + save[i-1][j-1])%MOD;
        }
    }
    return save;
}

void submit(vector<vector<long long>> &save)
{
    int n, k;
    cin >> n >> k;

    
    cout << save[n][k]%MOD;
    
    
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
    vector<vector<long long>> save = prepare();
    
    while (so_bo_test--)
    {
        submit(save);
    }

    return 0;
}