#include <bits/stdc++.h>
using namespace std;

long long string_to_int(string a)
{
    long long temp = 0;
    for (auto &&i : a)
    {
        temp *= 10;
        temp += i-'0';
    }
    return temp;
}

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A)
    {
        cin >> i;
    }
    
    sort(A.begin(), A.end());

    string a, b;

    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            a += to_string(A[i]);
        }
        else
        {
            b += to_string(A[i]);
        }
    }
    
    cout << string_to_int(a) + string_to_int(b);



    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    while (test--)
    {
        submit();
    }
    

    return 0;
}