#include <bits/stdc++.h>
using namespace std;

bool is_an_int(string s)
{
    for (auto &&i : s)
    {
        if (!isdigit(i))
        {
            return false;
        }
    }
    return true;
}

void submit()
{
    ifstream temp("DATA.in");

    vector<string> A;
    string s;

    while (getline(temp, s))
    {
        stringstream ss(s);
        string word;
        while (ss >> word)
        {
            A.push_back(word);
        }
    }
    
    long long total = 0;
    for (auto &&i : A)
    {
        if (i.size() <= 9)
        {
            if (is_an_int(i))
            {
                int n = stoi(i);
                total += n;
            }
        }
    }
    
    cout << total;

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