#include <bits/stdc++.h>
using namespace std;

string submit(string s)
{
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

    string check;
    
    check += last.back();
    
    for (int i = 0; i < save.size()-1; i++)
    {
        check += save[i];
    }
    
    return check;
}



int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;
    cin.ignore();

    vector<string> if_alr_have;
    while (so_bo_test--)
    {
        string s;
        getline(cin, s);
    
        string save = submit(s);
        if_alr_have.push_back(save);

        if (count(if_alr_have.begin(), if_alr_have.end(), save) == 1)
        {
            cout << save << "@ptit.edu.vn";
        }
        else
        {
            cout << save << count(if_alr_have.begin(), if_alr_have.end(), save) << "@ptit.edu.vn";
        }
        cout << endl;
    }

    return 0;
}