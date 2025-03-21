#include <bits/stdc++.h>
using namespace std;

void submit(char *set_101, char *set_102)
{
    int b;  
    cin >> b;

    char ans[15];

    for (int i = 0; i < 15; i++)
    {
        cin >> ans[i];
    }
    double count {0};

    if (b == 101)
    {
        for (int i = 0; i < 15; i++)
        {
            if (ans[i] == set_101[i])
            {
                count++;
            }
            
        }
        
    }
    else
    {
        for (int i = 0; i < 15; i++)
        {
            if (ans[i] == set_102[i])
            {
                count++;
            }
            
        }
    }
    cout << setprecision(2) << fixed << count*10/15 << endl;
    
    
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    char set_101[] = {'A', 'B', 'B', 'A', 'D', 'C', 'C', 'A', 'B', 'D', 'C', 'C', 'A', 'B', 'D'};
    char set_102[] = {'A', 'C', 'C', 'A', 'B', 'C', 'D', 'D', 'B', 'B', 'C', 'D', 'D', 'B', 'B'};


    while (so_bo_test--)
    {
        submit(set_101, set_102);
    }

    return 0;
}
