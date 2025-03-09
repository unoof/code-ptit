#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, m, p;
    cin >> n >> m >> p;

    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(m, vector<int>(p));
    vector<vector<long>> C(n, vector<long>(p, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> B[i][j];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    
    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}