#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    priority_queue<int> even;
    priority_queue<int, vector<int>, greater_equal<int>> odd;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i%2 == 0)
        {
            odd.push(temp);
        }
        else
        {
            even.push(temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            cout << odd.top() << " ";
            odd.pop();
        }
        else
        {
            cout << even.top() << " ";
            even.pop();
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