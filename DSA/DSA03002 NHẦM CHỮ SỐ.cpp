#include <bits/stdc++.h>
using namespace std;

long maxi(string a, string b)
{
    for (auto &&i : a)
    {
        if (i == '5') i = '6';
    }

    for (auto &&i : b)
    {
        if (i == '5') i = '6';
    }

    return stoi(a) + stoi(b);
}

long mini(string a, string b)
{
    for (auto &&i : a)
    {
        if (i == '6') i = '5';
    }

    for (auto &&i : b)
    {
        if (i == '6') i = '5';
    }

    return stoi(a) + stoi(b);
}


void submit()
{
    string a, b;
    cin >> a >> b;

    cout << mini(a, b) << " " << maxi(a, b);
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}