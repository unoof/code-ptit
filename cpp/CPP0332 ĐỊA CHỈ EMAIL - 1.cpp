#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);
    vector<char> save;

    bool past = true;

    for (auto &&i : s)
    {
        i = tolower(i);

        if (past && i != ' ')
        {
            save.push_back(i);
            past = false;
        }
        else if (i == ' ')
        {
            past = true;
        }        
    }
    
    stringstream ss(s);
    string word;
    vector<string> last;

    while (ss >> word)
    {
        last.push_back(word);
    }
    
    cout << last.back();
    
    for (int i = 0; i < save.size()-1; i++)
    {
        cout << save[i];
    }
    
    cout << "@ptit.edu.vn";
    
    
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