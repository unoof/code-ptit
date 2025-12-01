#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


void add(TreeNode* root, int node)
{
    if (!root)
    {
        root = new TreeNode(node);
    }
    else if (node < root->val)
    {
        if (root->left) add(root->left, node);
        else root->left = new TreeNode(node);
    }
    else if (node > root->val)
    {
        if (root->right) add(root->right, node);
        else root->right = new TreeNode(node);
    }
}

int find_depth(TreeNode* node, int depth)
{
    if (!node)
    {
        return depth;
    }
    
    return max(find_depth(node->left, depth+1), find_depth(node->right, depth+1));
}

void submit()
{
    int n;
    cin >> n;
    vector<int> node(n);
    for (auto &&i : node) cin >> i;

    TreeNode* root = new TreeNode(node[0]);
    for (int i = 1; i < n; i++)
    {
        add(root, node[i]);
    }
    
    cout << find_depth(root, 0) - 1;

    

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