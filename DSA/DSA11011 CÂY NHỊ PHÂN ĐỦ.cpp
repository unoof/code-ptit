#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};



bool check = true;

bool add(TreeNode *node, int parent, int child, char pos)
{
    if (!node) return false;
    
    if (node->val != parent)
    {
        if (add(node->left, parent, child, pos)) return true;
        if (add(node->right, parent, child, pos)) return true;
        return false;
    }
    else
    {
        if (pos == 'L')
        {
            if (!node->left) node->left = new TreeNode(child);
        }
        else
        {
            if (!node->right) node->right = new TreeNode(child);
        }
        return true;
    }
}

void lvl_traversal(TreeNode *node, int depth)
{
    if (!node || (node->left == nullptr && node->right == nullptr))
    {
        return;
    }
    

    if (!node->left || !node->right)
    {
        check = false;
        return;
    }
    
    lvl_traversal(node->left, depth+1);
    lvl_traversal(node->right, depth+1);
}

void submit()
{
    check = true;

    int n;
    cin >> n;

    int parent, child;
    char pos;
    cin >> parent >> child >> pos;

    TreeNode *root = new TreeNode(parent);
    
    add(root, parent, child, pos);

    for (int i = 1; i < n; i++)
    {
        cin >> parent >> child >> pos;
        add(root, parent, child, pos);
    }
    
    lvl_traversal(root, 0);

    if (check)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
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