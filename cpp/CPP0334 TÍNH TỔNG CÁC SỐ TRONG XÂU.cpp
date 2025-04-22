#include <bits/stdc++.h>
using namespace std;

vector<int> check(string s, int n)
{
    vector<int> total;
    for (int i = n; i >= 0; i--)
    {
        if (!isdigit(s[i]))
        {
            return total;
        }
        else
        {
            total.push_back((s[i] - '0'));
        }
    }
    return total;
}

int power(vector<int> A)
{
    int total = 0, pow = 1;
    for (int i = 0; i < A.size(); i++)
    {
        total += A[i]*pow;
        pow *= 10;
    }
    return total;
}

void submit()
{
    string s;
    cin >> s;
    long total = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            vector<int> save = check(s, i);
            i -= save.size();
            total += power(save);
        }
        
    }
    
    
    cout << total;
    
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