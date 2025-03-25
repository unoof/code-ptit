#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n, count = 0;
    cin >> n;
    set<int> unique_numbers;
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        unique_numbers.insert(x);
    }

    int start = *unique_numbers.begin();
    int end = *unique_numbers.rbegin();
    
    for (int i = start; i < end; i++)
    {
        if (unique_numbers.find(i) == unique_numbers.end())
        {
            count++;
        }
    }

    cout << count << endl;
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