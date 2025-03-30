#include <bits/stdc++.h>
using namespace std;


void submit()
{
    int n;
    cin >> n;

    set<int> arr;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.insert(a);
    }

    if (arr.size() >= 2)
    {
        auto it1 = arr.begin();
    
        auto it2 = next(it1, 1);
        
        cout << *it1 << "  " << *it2;

/*                                                                  // other way to solve this problem
        int count = 0;
        for (int a : arr)
        {
            if (count == 2)
            {
                break;
            }
            cout << a << "  ";
            count++;
        }
*/
    }
    else
    {
        cout << -1;
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
    cin.ignore();

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}