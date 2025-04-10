#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n;
    cin >> n;
    
    int count = 0;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0 && i*i != n)
        {
            if (i%2 == 0)
            {
                count++;
            }

            if ((n/i)%2 == 0)
            {
                count++;
            }
            
        }
        else if (i*i == n)
        {
            if (i%2 == 0)
            {
                count++;
            }
        }
        
        
    }

    if (n%2 == 0)
    {
        count++;
    }
    
    
    cout << count;
    
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