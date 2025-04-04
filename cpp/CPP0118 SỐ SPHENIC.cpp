#include <bits/stdc++.h>
using namespace std;

bool sphenic_num(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }
    
    int check = 0;
    int count = 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
        check = 0;
        while (num%i == 0)
        {
            if (check == 1)
            {
                return false;
            }
            
            num /= i;
            check++;
            count++;
        }
        
    }

    if (num != 1)
    {
        count++;
    }
    
    
    return count == 3;
}

void submit()
{
    int n;
    cin >> n;
    
    cout << sphenic_num(n);
    
    
    
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