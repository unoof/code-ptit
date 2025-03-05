#include <bits/stdc++.h>
using namespace std;

bool check_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num%i == 0)
        {
            return false;
        }
        
    }
    return true;
}

void submit()
{
    int num;
    cin >> num;
    
    
    check_prime(num) ? (cout << "YES") : (cout << "NO");
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    submit();

    return 0;
}