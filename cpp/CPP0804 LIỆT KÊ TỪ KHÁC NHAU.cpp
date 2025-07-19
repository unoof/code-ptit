#include <bits/stdc++.h>
using namespace std;

string lower(string s)
{
    for (auto &&i : s)
    {
        i = tolower(i);
    }
    return s;
}

void submit()
{
    ifstream temp("VANBAN.in");
    
    set<string> out;
    string line;
    while (getline(temp, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            out.insert(lower(word));
        }
    }
    
    for (auto &&i : out)
    {
        cout << i << endl;
    }
    

    temp.close();

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}