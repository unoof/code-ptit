#include <bits/stdc++.h>
using namespace std;

bool check(deque<int> dq)
{
    for (int i = 0; i < dq.size()/2; i++)
    {
        if (dq[i] != dq[dq.size() - i])
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

    deque<int> dq;
    int i {0};

    while (num > 0)
    {
        dq[i] = num%10;
        num /= 10;
        i++;
    }
    

    check(dq) ? (cout << "YES") : (cout << "NO");
    

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