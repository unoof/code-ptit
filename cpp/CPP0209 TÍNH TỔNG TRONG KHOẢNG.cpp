#include <bits/stdc++.h>
using namespace std;

long total(vector<int> arr, int start, int end)
{
    long total {0};

    for (int i = start-1; i < end; i++)
    {
        total += arr[i];
    }
    return total;
}

void submit()
{
    int num, questions;
    cin >> num >> questions;

    vector<int> arr(num);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < questions; i++)
    {
        int start, end;
        cin >> start >> end;
    
        cout << total(arr, start, end) << endl;
    
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


    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}