#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    cin.ignore();
    map<int,set<int>> A;

    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int temp;
        while (ss >> temp)
        {
            if (i != temp)
            {
                if (i > temp)
                {
                    A[temp].insert(i);
                }
                else
                {
                    A[i].insert(temp);
                }
            }
        }
    }
    
    for (auto &&i : A)
    {
        for (auto &&j : i.second)
        {
            cout << i.first << " " << j << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}