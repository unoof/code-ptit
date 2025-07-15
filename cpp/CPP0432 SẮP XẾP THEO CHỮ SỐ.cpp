#include <bits/stdc++.h>
using namespace std;

bool sort_2_num(string n, string m)
{
    string temp1 = n+m;
    string temp2 = m+n;
    return temp1>temp2;
}

void submit()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end(), sort_2_num);
    
    for (auto &&i : A)
    {
        cout << i;
    }
    

    cout << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;
    cin.ignore();

    while (test--)
    {
        submit();
    }
    
    return 0;
}