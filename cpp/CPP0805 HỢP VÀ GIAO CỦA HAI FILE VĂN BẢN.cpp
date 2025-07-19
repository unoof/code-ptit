#include <bits/stdc++.h>
using namespace std;

string all_low(string s)
{
    for (auto &&i : s)
    {
        i = tolower(i);
    }
    return s;
}

void submit()
{
    ifstream temp1("DATA1.in");
    ifstream temp2("DATA2.in");

    set<string> hop;
    set<string> giao;
    vector<string> data1;
    vector<string> data2;

    string temp;
    while (getline(temp1, temp))
    {
        stringstream ss(temp);
        string word;
        while (ss >> word)
        {
            hop.insert(all_low(word));
            data1.push_back(all_low(word));
        }
    }
    
    while (getline(temp2, temp))
    {
        stringstream ss(temp);
        string word;
        while (ss >> word)
        {
            hop.insert(all_low(word));
            data2.push_back(all_low(word));
        }
    }
    
    for (auto &&i : data1)
    {
        if (count(data2.begin(), data2.end(), i))
        {
            giao.insert(i);
        }
    }
    

    for (auto &&i : hop)
    {
        cout << i << " ";
    }
    
    cout << endl;
    for (auto &&i : giao)
    {
        cout << i << " ";
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