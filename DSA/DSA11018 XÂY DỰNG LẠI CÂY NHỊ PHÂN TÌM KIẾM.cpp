#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


void add(TreeNode* node, int num)
{
    if (num < node->val)
    {
        if (node->left) add(node->left, num);
        else node->left = new TreeNode(num);
    }
    else if (num > node->val)
    {
        if (node->right) add(node->right, num);
        else node->right = new TreeNode(num);
    }
}

void post_order_traversal(TreeNode* node)
{
    if (!node)
    {
        return;
    }
    
    cout << node->val << " ";
    post_order_traversal(node->left);
    post_order_traversal(node->right);
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
    
    post_order_traversal(root);

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