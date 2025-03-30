#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        cout << "*";

        if (i >= 2)
        {
            for (int k = 0; k < 2*(i-2) + 1; k++)
            {
                cout << " ";
            }
            cout << "*";
        }
        
        cout << endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "* ";
    }
    
    
    
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}