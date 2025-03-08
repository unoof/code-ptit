#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int num, d;
    cin >> num >> d;

    vector<int> arr(num);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = d; i < num+d; i++)
    {
        int a = i%num;
        cout << arr[a] << "  ";
    }

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