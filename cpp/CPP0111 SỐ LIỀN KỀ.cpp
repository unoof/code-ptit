#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> num, int a)
{
    for (int i = 0; i < a-1; i++)
    {
        if (abs(num[i] - num[i+1]) != 1)
        {
            return false;
        }
        
    }
    return true;
}

void submit()
{
    long long a;
    cin >> a;

    vector<int> num(18);
    int i {0};
    
    while (a > 0)
    {
        num[i] = a%10;
        a /= 10;
        i++;
    }
    
    check(num, i) ? (cout << "YES") : (cout << "NO");
    cout << endl;
    
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}
