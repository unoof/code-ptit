#include <bits/stdc++.h>
using namespace std;


void submit()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    
    stringstream ss1(str1);
    string word1;
    set<string> out;

    while (ss1 >> word1)
    {
        out.insert(word1);
    }

    stringstream ss2(str2);
    string word2;
    set<string> track;
    
    while (ss2 >> word2)
    {
        track.insert(word2);
    }

    
    for (string temp : track)
    {
        auto erased = out.erase(temp);
    }

    for (string temp : out)
    {
        cout << temp + " "; 
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