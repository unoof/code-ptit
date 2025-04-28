#include <bits/stdc++.h>
using namespace std;

unordered_set<long long> A {6, 28, 496, 8128, 33550336, 8589869056, 137438691328};

void submit()
{
    long long n;
    cin >> n;

    count(A.begin(), A.end(), n) ? (cout << 1) : (cout << 0);
    
    
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