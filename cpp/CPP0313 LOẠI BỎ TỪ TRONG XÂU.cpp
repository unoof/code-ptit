#include <bits/stdc++.h>
using namespace std;

vector<string> splitString(const string& text, const string& delimiter)     //To spilt a string in to substring with specific delimiter
{
    vector<string> substrings;
    int start = 0;
    int end = text.find(delimiter);                                         //Syntax: string.find(key, start_position)

    while (end != string::npos)                                             //If not found will return npos (mean "no position")
    {
        substrings.push_back(text.substr(start, end - start));
        start = end + delimiter.length();
        end = text.find(delimiter, start);
    }
    // Add the last substring
    substrings.push_back(text.substr(start));

    return substrings;
}

void submit()
{
    string str;
    getline(cin, str);

    string remove_str;
    cin >> remove_str;

    vector<char> remove_words;
    string delimiter = " ";

    vector<string> result = splitString(str, delimiter);

    for (const string& sub : result)
    {
        if (sub != remove_str)
        {
            cout << sub << " ";
        }
        
    }
    
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}