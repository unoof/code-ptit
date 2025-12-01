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

bool check_same_tree(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    else if ((root1->val == root2->val) && root1 && root2)
    {
        return check_same_tree(root1->left, root2->left) && check_same_tree(root1->right, root2->right);
    }
    return false;
}

void submit()
{
    int n;
    int parent, child;
    char pos;
    cin >> n >> parent >> child >> pos;
    
    TreeNode *root1 = new TreeNode(parent);

    add(root1, parent, child, pos);
    
    for (int i = 1; i < n; i++)
    {
        cin >> parent >> child >> pos;
        add(root1, parent, child, pos);
    }



    cin >> n >> parent >> child >> pos;
    
    TreeNode *root2 = new TreeNode(parent);

    add(root2, parent, child, pos);

    for (int i = 1; i < n; i++)
    {
        cin >> parent >> child >> pos;
        add(root2, parent, child, pos);
    }

    check_same_tree(root1, root2) ? cout << 1 : cout << 0;

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