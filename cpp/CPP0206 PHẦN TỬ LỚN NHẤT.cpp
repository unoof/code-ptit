#include <bits/stdc++.h>
using namespace std;

void submit()
{
    long num;
    cin >> num;

    vector<int> arr(num);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    cout << arr[num-1];
    
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