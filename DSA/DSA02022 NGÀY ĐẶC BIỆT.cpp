#include <bits/stdc++.h>
using namespace std;

void out(string &d, string &y)
{
    if (d == "00")
    {
        return;
    }
    
    cout << d << "/02/" << y << endl;
}

void year(string &y, string &d)
{
    if (y.size() == 4)
    {
        out(d, y);
        return;
    }
    
    for (int i = 0; i <= 2; i++)
    {
        if (i == 1)
        {
            continue;
        }
        
        y += to_string(i);
        year(y, d);
        y.erase(y.size()-1);
    }
    
}

void days(string &d)
{
    if (d.size() == 2)
    {
        string y = "2";
        year(y, d);
        return;
    }
    
    for (int i = 0; i <= 2; i++)
    {
        if (i == 1)
        {
            continue;
        }
        
        d += to_string(i);
        days(d);
        d.erase(d.size()-1);
    }
}

void submit()
{
    string d;
    days(d);
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}