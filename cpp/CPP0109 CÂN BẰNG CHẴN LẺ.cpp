#include <bits/stdc++.h>
using namespace std;

bool check(int num)
{
    int odd {0}, even {0};

    while (num > 0)
    {
        if ((num%10)%2 != 0)
        {
            odd++;
        }
        else
        {
            even++;
        }
        num/=10;
    }

    return odd == even;
}


void submit()
{
    int a, count {1};
    cin >> a;
    
    for (int i = pow(10, a - 1); i < pow(10, a); i++)
    {
        if (check(i) && count < 10)
        {
            cout << i << " ";
            count++;
        }
        else if (check(i) && count == 10)
        {
            cout << i << endl;
            count = 1;
        }
    }
    
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);  // Speed up input/output
    cin.tie(nullptr);

    submit();

    return 0;
}
