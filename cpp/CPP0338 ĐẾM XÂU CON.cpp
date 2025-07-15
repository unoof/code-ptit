#include <bits/stdc++.h>
using namespace std;

int check(string s, int n)
{
    vector<int> A(1);
    A[0] = s[0];
    int count = 0;
    for (auto &&i : s)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (i == A[j])
            {
                if (A.size() == n)
                {
                    count++;
                }
                break;
            }
            else
            {
                if (j == A.size() - 1)
                {
                    if (A.size() < n)
                    {
                        A.push_back(i);
                    }
                    else if (A.size() == n)
                    {
                        return count;
                    }
                }
                else
                {
                    continue;
                }
            }
            
        }
    }
    
    return count;
}

void submit()
{
    string s;
    cin >> s;
    int n, count = 0;
    cin >> n;
    
    while (s.length() >= n)
    {
        count += check(s, n);
        s.erase(0, 1);
    }
    
    cout << count;
    
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