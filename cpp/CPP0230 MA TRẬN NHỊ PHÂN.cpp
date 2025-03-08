#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n, total {0};
    cin >> n;

    vector<vector<bool>> A(n, vector<bool> (3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bool temp;
            cin >> temp;
            A[i][j] = temp;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        int num_1 {0};

        for (int j = 0; j < 3; j++)
        {
            if (A[i][j] == 1)
            {
                num_1++;
            }
            
        }

        if (num_1 > 3 - num_1)
        {
            total++;
        }
        
    }
    
    cout << total;
    
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