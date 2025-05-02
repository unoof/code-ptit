#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string n;
    cin >> n;

    int count = 1;
    int store = 0;
    bool Degreasing = false;

    for (auto &&i : n)
    {
        if (i == 'I')
        {
            if (!Degreasing)
            {
                cout << count;
                count++;
            }
            else
            {
                for (int j = store; j >= 0; j--)
                {
                    cout << j + count;
                }
                count += store+1;
                store = 0;
                Degreasing = false;
            }
        }
        else
        {
            store++;
            Degreasing = true;
        }
    }
    
    if (store != 0)
    {
        for (int i = store; i >= 0; i--)
        {
            cout << i+count;
        }
        
    }
    else
    {
        cout << count;
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