#include <bits/stdc++.h>
using namespace std;

void find_min(int m, int s)
{
    int total {0};

    for (int i = 1; i <= m; i++)
    {
        if (i == 1)
        {
            for (int j = 1; j <= 9; j++)
            {
                int max = 9*(m-i) + j + total;
        
                if (max < s)
                {
                    continue;
                }
                else
                {
                    total += j;
                    cout << j;
                    break;
                }
                
            }
        }
        else
        {
            for (int j = 0; j <= 9; j++)
            {
                int max = 9*(m-i) + j + total;
        
                if (max < s)
                {
                    continue;
                }
                else
                {
                    total += j;
                    cout << j;
                    break;
                }
                
            }
        }
        
    }
    cout << " ";
}

void find_max(int m, int s)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (s <= j)
            {
                cout << s;
                for (int k = i+1; k <= m; k++)
                {
                    cout << "0";
                }
                
                return;
            }
            else
            {
                if (s - j >= 0)
                {
                    s -= j;
                    cout << j;
                    break;
                }
                else
                {
                    cout << s;
                    for (int k = i+1; k <= m; k++)
                    {
                        cout << "0";
                    }
                    
                    return;
                }
                
            }
            
            
        }
        
    }
}

void submit()
{
    int m, s, check {0};
    cin >> m >> s;

    for (int i = 0; i < m; i++)
    {
        check += 9;
    }
    
    if (check < s || s == 0)
    {
        cout << "-1 -1";
        return;
    }
    else
    {
        find_min(m, s);
        find_max(m, s);
    }
    
    

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