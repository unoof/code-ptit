#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &in, int num)
{
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == num)
        {
            return i;
        }
    }
    return -1;
}

void post_order(vector<int> &in, vector<int> &lvl)
{
    if (in.empty()) return;
    
    int index = search(in, lvl[0]);

    vector<int> in_left(in.begin(), in.begin()+index);
    vector<int> in_right(in.begin()+index+1, in.end());

    unordered_set<int> set_left(in_left.begin(), in_left.end());
    unordered_set<int> set_right(in_right.begin(), in_right.end());

    vector<int> lvl_left, lvl_right;
    for (auto &&i : lvl)
    {
        if (set_left.count(i))
        {
            lvl_left.push_back(i);
        }
        else if (set_right.count(i))
        {
            lvl_right.push_back(i);
        }
    }
    
    post_order(in_left, lvl_left);
    post_order(in_right, lvl_right);
    cout << lvl[0] << " ";
}

void submit()
{
    int n;
    cin >> n;
    vector<int> in(n), lvl(n);
    for (auto &&i : in) cin >> i;
    for (auto &&i : lvl) cin >> i;

    post_order(in, lvl);



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