#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};



bool add(TreeNode *node, int parent, int child, char pos)
{
    if (node == nullptr)
    {
        return false;
    }
    
    if (node->val != parent)
    {
        if (!add(node->left, parent, child, pos))
        {
            add(node->right, parent, child, pos);
        }
    }
    else
    {
        if (pos == 'L')
        {
            node->left = new TreeNode(child);
        }
        else
        {
            node->right = new TreeNode(child);
        }
        return true;
    }
    return false;
}

void lvl_traversal(TreeNode *node, int depth, map<int,vector<int>> &ans)
{
    if (node == nullptr) return;
    
    ans[depth].push_back(node->val);
    
    lvl_traversal(node->left, depth+1, ans);
    lvl_traversal(node->right, depth+1, ans);
}

void submit()
{
    TreeNode* root = nullptr;

    int n;
    cin >> n;

    int parent;
    int child;
    char pos;
    cin >> parent >> child >> pos;

    root = new TreeNode(parent);
    
    add(root, parent, child, pos);

    
    for (int i = 1; i < n; i++)
    {
        cin >> parent >> child >> pos;
        
        add(root, parent, child, pos);
    }
    
    map<int,vector<int>> ans;
    lvl_traversal(root, 0, ans);

    for (auto &&i : ans)
    {
        if (i.first&1)
        {
            for (int j = 0; j < i.second.size(); j++)
            {
                cout << i.second[j] << " ";
            }
        }
        else
        {
            for (int j = i.second.size() - 1; j >= 0; j--)
            {
                cout << i.second[j] << " ";
            }
        }
    }
    


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