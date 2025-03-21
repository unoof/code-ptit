#include <bits/stdc++.h>
using namespace std;

void submit()
{
    string num;
    cin >> num;

    size_t pos = num.find("084");
    
    if (pos != string::npos) {
        num.erase(pos, 3);
    }


    cout << num << endl;
    
}

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    int so_bo_test;
    cin >> so_bo_test;

    while (so_bo_test--)
    {
        submit();
    }

    return 0;
}
