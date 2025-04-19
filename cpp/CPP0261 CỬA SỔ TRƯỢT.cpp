#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        
    }
    
    int m;
    cin >> m;
    int B[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
        
    }
    
    for (int i = 0; i < n/m; i++)
    {
        for (int j = 0; j < n/m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    A[k + i*m][l + j*m] *= B[k][l];
                }
                
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    cout << endl;
}


int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}