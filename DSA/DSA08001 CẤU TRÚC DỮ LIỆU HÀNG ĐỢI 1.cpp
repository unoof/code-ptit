#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    deque<int> A;

    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f;
        if (f == 3) cin >> s;

        switch (f)
        {
            case 1:
                cout << A.size() << endl;
                break;
            case 2:
                A.empty() ? cout << "YES" : cout << "NO";
                cout << endl;
                break;
            case 3:
                A.push_back(s);
                break;
            case 4:
                if (!A.empty()) A.pop_front();
                break;
            case 5:
                A.empty() ? cout << -1 : cout << A.front();
                cout << endl;
                break;
            case 6:
                A.empty() ? cout << -1 : cout << A.back();
                cout << endl;
                break;
        }
    }
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