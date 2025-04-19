#include <bits/stdc++.h>
using namespace std;

void max(const string& x1, const string& x2)
{
    string a = x1, b = x2;

    for (auto& c : a) if (c == '5') c = '6';

    for (auto& c : b) if (c == '5') c = '6';

    long long na = stoll(a);
    long long nb = stoll(b);
    cout << (na + nb) << " ";
}

void min(const string& x1, const string& x2)
{
    string a = x1, b = x2;

    for (auto& c : a) if (c == '6') c = '5';
    
    for (auto& c : b) if (c == '6') c = '5';

    long long na = stoll(a);
    long long nb = stoll(b);
    cout << (na + nb) << " ";
}

void submit()
{
    string x1, x2;
    cin >> x1 >> x2;

    min(x1, x2);
    max(x1, x2);

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