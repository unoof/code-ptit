#include <bits/stdc++.h>
using namespace std;

vector<bool> fibo_num()
{
    vector<bool> fibo(1001, false);
    int a = 0;
    int b = 1;
    fibo[0] = true;

    while (a+b < 1001)
    {
        int temp = a;
        a += b;
        b = temp;
        fibo[a] = true;
    }
    return fibo;
}

void submit()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<bool> fibo = fibo_num();
    for (int num : A)
    {
        if (fibo[num])
        {
            cout << num << " ";
        }
        
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