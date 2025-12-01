#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) cin >> i;

    stack<int> temp;
    stack<int> B;
    vector<int> ans = {-1};
    temp.push(A[n-1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (!temp.empty())
        {
            if (A[i] < temp.top())
            {
                ans.push_back(temp.top());
            }
            
            while (A[i] >= temp.top())
            {
                B.push(temp.top());
                temp.pop();
                if (!temp.empty() && A[i] < temp.top())
                {
                    ans.push_back(temp.top());
                    break;
                }
                else if (temp.empty())
                {
                    ans.push_back(-1);
                    break;
                }
                
            }
            while (!B.empty())
            {
                temp.push(B.top());
                B.pop();
            }
            temp.push(A[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto &&i : ans)
    {
        cout << i << " ";
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