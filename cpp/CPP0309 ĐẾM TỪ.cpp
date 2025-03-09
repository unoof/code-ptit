#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string str;
    getline(cin, str);
    cin.ignore();                                                   //To have a new line after cin

    int count {1};

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
        {
            count++;
        }
        
    }
    
    cout << count;
    

    cout << endl;
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