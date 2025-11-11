#include <bits/stdc++.h>
using namespace std;

string BDN(int n)
{
    queue<string> A;
    A.push("1");

    
    while (!A.empty())
    {
        string s = A.front();
        A.pop();
        
        int temp = 0;
        for (auto &&i : s)
        {
            temp = (temp*10 + (i-'0'))%n;
        }
        
        if (temp == 0) return s;

        A.push(s+"0"), A.push(s+"1");
    }
}

void submit()
{
    int n;
    cin >> n;

    cout << BDN(n) << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed down input/output
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