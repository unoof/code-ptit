#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> A;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        A.push(temp);
    }
    
    long long total = 0, temp = 0;
    while (A.size() > 1)
    {
        temp += A.top(); A.pop();
        temp += A.top(); A.pop();

        total += temp;
        A.push(temp);
        temp = 0;
    }
    
    cout << total;

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