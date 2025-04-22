#include <bits/stdc++.h>
using namespace std;

void method_1(vector<string> s)
{
    cout << s.back() << " ";

    for (int i = 0; i < s.size()-1; i++)
    {
        cout << s[i] << " ";
    }
    
}

void method_2(vector<string> s)
{
    for (int i = 1; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    
    cout << s.front();
}

void submit()
{
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);
    bool past = true;

    for (auto &&i : s)
    {
        if (past && i != ' ')
        {
            i = toupper(i);
            past = false;
        }
        else if (i == ' ')
        {
            past = true;
        }
        else
        {
            i = tolower(i);
        }
        
    }
    
    stringstream ss(s);
    string word;
    vector<string> save;

    while (ss >> word)
    {
        save.push_back(word);
    }
    
    if (n == 1)
    {
        method_1(save);
    }
    else
    {
        method_2(save);
    }
    
    
    
    
    
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