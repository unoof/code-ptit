#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int n;
    cin >> n;
    cin.ignore();
    stack<int> A;

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);

        string temp;
        ss >> temp;

        if (temp == "PUSH")
        {
            int idk;
            ss >> idk;
            A.push(idk);
        }
        else if (temp == "POP")
        {
            if (!A.empty()) A.pop();
        }
        else
        {
            if (!A.empty())
            {
                cout << A.top();
            }
            else
            {
                cout << "NONE";
            }
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