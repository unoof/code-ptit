#include <bits/stdc++.h>
using namespace std;

string remove_space(string s)
{
    size_t start = s.find_first_not_of(' \t\n\r');
    if (start == string::npos)
    {
        return "";
    }
    
    size_t end = s.find_last_not_of(" \t\n\r");

    return s.substr(start, end - start + 1);
}

bool have_num_or_words(string s)
{
    for (auto &&i : s)
    {
        if (isalnum(i))
        {
            return true;
        }
        
    }
    return false;    
}

string format(string s)
{
    if (s.empty())
    {
        return "";
    }

    string temp;
    bool alr_space = false;
    for (auto &&i : s)
    {
        i = tolower(i);
    }

    if (!s.empty())
    {
        s[0] = toupper(s[0]);
    }
    
    for (auto &&i : s)
    {
        if (isspace(i))
        {
            if (!alr_space)
            {
                temp += ' ';
                alr_space = true;
            }
        }
        else
        {
            temp += i;
            alr_space = false;
        }
    }
    
    return temp;
}

void submit()
{
    vector<string> out;
    string s;
    string temp;
    bool skip = false;

    while (getline(cin, temp))
    {
        for (auto &&i : temp)
        {
            if (skip)
            {
                if (i == '.' || i == '?' || i == '!' || isspace(i))
                {
                    continue;
                }
                else
                {
                    s+= i;
                    skip = false;
                }
            }
            else
            {
                if (i == '.' || i == '!' || i == '?')
                {
                    string alr_remove = remove_space(s);
                    if (have_num_or_words(alr_remove))
                    {
                        out.push_back(format(alr_remove));
                    }

                    s.clear();
                    skip = true;
                }
                else
                {
                    s += i;
                }
            }
        }
        
    }
    
    string alr_remove = remove_space(s);
    if (have_num_or_words(alr_remove))
    {
        out.push_back(format(alr_remove));
    }

    for (auto &&i : out)
    {
        cout << i << endl;
    }
    
    
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}