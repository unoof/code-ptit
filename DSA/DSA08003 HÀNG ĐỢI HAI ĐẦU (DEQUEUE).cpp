#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    cin.ignore();
    deque<int> A;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s == "PUSHBACK")
        {
            int idk;
            cin >> idk;
            A.push_back(idk);
        }
        else if (s == "PUSHFRONT")
        {
            int idk;
            cin >> idk;
            A.push_front(idk);
        }
        else if (s == "POPBACK")
        {
            if (!A.empty()) A.pop_back();
        }
        else if (s == "POPFRONT")
        {
            if (!A.empty()) A.pop_front();
        }
        else if (s == "PRINTBACK")
        {
            !A.empty() ? cout << A.back() : cout << "NONE";
            cout << endl;
        }
        else if (s == "PRINTFRONT")
        {
            !A.empty() ? cout << A.front() : cout << "NONE";
            cout << endl;
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