#include <bits/stdc++.h>
using namespace std;

string to_binary(int n)
{
    string s;
    while (n != 0)
    {
        if (n%2 == 1)
        {
            s = to_string(9) + s;
        }
        else
        {
            s = to_string(n%2) + s;
        }
        n /= 2;
    }
    return s;
}

void submit()
{
    int n, temp = 1;
    long long res = 9;
    cin >> n;    
    
    while (res%n != 0)
    {
        res = stoi(to_binary(temp));
        temp++;
    }
    
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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