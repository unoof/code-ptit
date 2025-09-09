#include <bits/stdc++.h>
using namespace std;

void recursion(string out, string in, string other, int high)
{
    if (high <= 1)
    {
        cout << out + " -> " + in << endl;
    }
    else
    {
        recursion(out, other, in, high-1);
        cout << out + " -> " + in << endl;
        recursion(other, in, out, high-1);
    }
}

void submit()
{
    int n;
    cin >> n;

    recursion("A", "C", "B", n);
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}