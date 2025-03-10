#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& num,const string& delimeter)
{
    vector<string> substring;

    int start = 0;
    int end = num.find(delimeter);

    while (end != string::npos)
    {
        substring.push_back(num.substr(start, end-start));
        start = end + delimeter.length();
        end = num.find(delimeter, start);
    }

    substring.push_back(num.substr(start));
    return substring;
}


void submit()
{
    string num;
    getline(cin, num);
    string delimeter = " ";

    vector<string> substring = split(num, delimeter);

    int even {0};
    int odd {0};

    for (int i = 0; i < substring.size(); i++)
    {
        char last = substring[i][substring[i].size() - 1];
        switch (last)
        {
        case '1':
        case '3':
        case '5':
        case '7':
        case '9':
            odd++;
            break;
        case '0':
        case '2':
        case '4':
        case '6':
        case '8':
            even++;
            break;
        }            
    }
    
    if ((substring.size()%2 == 0 && even > odd) || (substring.size()%2 != 0 && odd > even))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    return;
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