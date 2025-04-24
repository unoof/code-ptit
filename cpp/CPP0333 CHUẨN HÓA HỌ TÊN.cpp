#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string s;
    getline(cin, s);
    bool alr_space = true;

    for (auto &&i : s)
    {
        i = tolower(i);
    }
    
    vector<string> save;
    string temp;
    
    for (auto &&i : s)
    {
        if (alr_space)
        {
            if (isspace(i))
            {
                continue;
            }
            else
            {
                temp += toupper(i);
                alr_space = false;
            }
        }
        else
        {
            if (isspace(i))
            {
                temp += i;
                alr_space = true;
            }
            else
            {
                temp += i;
            }
            
        }
        
    }

    string A;
    
    for (auto &&i : temp)
    {
        if (isspace(i))
        {
            save.push_back(A);
            A.clear();
        }
        else
        {
            A += i;
        }
        
    }
    save.push_back(A);

    cout << save[0];
    
    for (int i = 1; i < save.size(); i++)
    {
        if (i < save.size() - 1)
        {
            cout << " " << save[i];
        }
        else
        {
            cout << ", ";
            
            for (auto &&j : A)
            {
                j = toupper(j);
                cout << j;
            }
            
        }
        
    }
    
    
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