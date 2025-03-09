#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string real_num;
    cin >> real_num;

    long long int_num {0};
    int power {0};

    for (int i = real_num.length() - 1; i >= 0; i--)
    {
        if (real_num[i] == '1')
        {
            int mod_value;
            switch (power % 4)
            {                                                       // Cycle of 2^k mod 5
                case 0: mod_value = 1; break;                       // 2^0, 2^4, 2^8...
                case 1: mod_value = 2; break;                       // 2^1, 2^5, 2^9...
                case 2: mod_value = 4; break;                       // 2^2, 2^6, 2^10...
                case 3: mod_value = 3; break;                       // 2^3, 2^7, 2^11...
            }
            int_num = (int_num + mod_value) % 5;
        }
        power++;
    }

    if (int_num%5 == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    cout << endl;
    return;
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