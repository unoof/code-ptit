#include <bits/stdc++.h>
using namespace std;

void submit()
{
    int num;
    cin >> num;
    cin.ignore();

    unordered_set<string> loi_chuc;                                 // use set because set remove repeat input

    for (int i = 0; i < num; i++)
    {
        string A;
        getline(cin, A);
        loi_chuc.insert(A);
    }
    
    cout << loi_chuc.size();
    
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