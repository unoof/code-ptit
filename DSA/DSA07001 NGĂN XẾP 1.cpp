#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    stack<int> A;
    while (getline(cin, s))
    {
        string temp;
        stringstream ss(s);
        int idk;
        
        ss >> temp;

        if (temp == "push")
        {
            ss >> idk;
            A.push(idk);
        }
        else if (temp == "show")
        {
            if (!A.empty())
            {
                stack<int> B;
                while (!A.empty())
                {
                    B.push(A.top());
                    A.pop();
                }
                while (!B.empty())
                {
                    A.push(B.top());
                    cout << B.top() << " ";
                    B.pop();
                }
            }
            else
            {
                cout << "empty";
            }
            
            cout << endl;
        }
        else
        {
            A.pop();
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