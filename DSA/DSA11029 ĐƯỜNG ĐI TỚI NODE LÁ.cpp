#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> child;

    TreeNode(int v) : val(v) {}
};

struct point
{
    int parent, child;
};




TreeNode* add(vector<pair<int,int>> &edges)
{
    unordered_map<int,TreeNode*> m;
    unordered_set<int> child_set;
    
    for (auto &&i : edges)
    {
        int parent = i.first, child = i.second;

        if (!m.count(parent)) m[parent] = new TreeNode(parent);
        if (!m.count(child)) m[child] = new TreeNode(child);

        m[parent]->child.push_back(m[child]);
        child_set.insert(child);
    }

    TreeNode* root = nullptr;
    for (auto &&i : m)
    {
        int node_val = i.first;
        if (!child_set.count(node_val))
        {
            root = i.second;
            break;
        }
    }
    
    return root;
}

bool is_leaves(TreeNode *node)
{
    if (!node) return false;
    if (node->child.size() == 0) return true;
    return false;
}

void traversal(TreeNode *node, vector<vector<int>> &ans, vector<int> now)
{
    if (!node)
    {
        return;
    }

    now.push_back(node->val);

    if (!is_leaves(node))
    {
        for (auto &&i : node->child)
        {
            traversal(i, ans, now);
        }
    }
    else if (is_leaves(node))
    {
        ans.push_back(now);
    }
    return;
}

bool cmp(vector<int> &A, vector<int> &B)
{
    return A[A.size()-1] < B[B.size()-1];
}

void submit()
{
    int n;
    cin >> n;

    vector<pair<int,int>> edges(n-1);

    for (int i = 0; i < n-1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    TreeNode *root = nullptr;
    root = add(edges);
    

    vector<vector<int>> ans;
    vector<int> now;
    traversal(root, ans, now);
    
    sort(ans.begin(), ans.end(), cmp);

    for (auto &&i : ans)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
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