#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int num;
    cin >> num;
    int min = 1000;

    vector<int> arr(num);

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    

    sort(arr.begin(), arr.end());

    for (int i = 0; i < num-1; i++)
    {
        if (min > arr[i+1] - arr[i])
        {
            min = arr[i+1] - arr[i];
        }
        
    }
    cout << min;
    
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