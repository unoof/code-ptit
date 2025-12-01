#include <bits/stdc++.h>
using namespace std;

void post_order(int inL, int inR, int preL, int preR, unordered_map<int,int> &pos, vector<int> &in, vector<int> pre)
{
    if (inL > inR || preL > preR)
    {
        return;
    }

    int root = pre[preL];
    int k = pos[root];
    int left_size = k - inL;

    post_order(inL, k-1, preL+1, preL+left_size, pos, in, pre);
    post_order(k+1, inR, preL+left_size+1, preR, pos, in, pre);

    cout << root << " ";
}

void submit()
{
    int n;
    cin >> n;
    vector<int> in(n), pre(n);
    unordered_map<int,int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        pos[in[i]] = i;
    }
    for (auto &&i : pre) cin >> i;

    post_order(0, n - 1, 0, n - 1, pos, in, pre);



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