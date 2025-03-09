#include <bits/stdc++.h>
using namespace std;

bool check_divide_11(vector<char> num, int str_num)
{
    int total {0};
    for (int i = 0; i < str_num; i++)
    {
        if (i%2 == 0)
        {
            total += num[i] - 48;
        }
        else
        {
            total -= num[i] - 48;
        }
    }
    
    if (total%11 == 0)
    {
        return true;
    }
    return false;
}

void submit()
{
    string real_num;
    cin >> real_num;
    vector<char> num;


    for (int i = 0; i < real_num.length(); i++)
    {
        num.push_back(real_num[i]);
    }

    check_divide_11(num, real_num.length()) ? (cout << "1") : (cout << "0");

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