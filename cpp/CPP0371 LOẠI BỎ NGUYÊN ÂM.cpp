#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'y')
        {
            cout << "." << str[i];
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