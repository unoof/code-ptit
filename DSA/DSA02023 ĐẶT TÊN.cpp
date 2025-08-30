#include <bits/stdc++.h>
using namespace std;

vector<string> t;
int k;

void update(vector<string> &A, int i, int start)
{
    for (int j = start; j < A.size(); j++)
    {
        t[i] = A[j];
        if (i == k-1)
        {
            for (auto &&i : t)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            update(A, i+1, j+1);
        }
        
    }
    
}

void submit()
{
    int n;
    cin >> n >> k;
    set<string> A;
    
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        A.insert(temp);
    }
    vector<string> B(A.begin(), A.end());
    t.resize(k);
    
    update(B, 0, 0);
}   

int main()
{
    ios::sync_with_stdio(false);                                    // Speed up input/output
    cin.tie(nullptr);
    cout.tie(nullptr);

    submit();

    return 0;
}