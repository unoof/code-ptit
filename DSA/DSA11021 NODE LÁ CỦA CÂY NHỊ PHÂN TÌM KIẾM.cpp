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

vector<int> find_leaves(TreeNode* node)
{
    vector<int> leaves;

    if (!node->left && !node->right)
    {
        leaves.push_back(node->val);
        return leaves;
    }
    
    vector<int> left, right;
    if (node->left) left = find_leaves(node->left);
    if (node->right) right = find_leaves(node->right);

    leaves.insert(leaves.end(), left.begin(), left.end());
    leaves.insert(leaves.end(), right.begin(), right.end());

    return leaves;
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
    
    vector<int> leaves = find_leaves(root);

    for (auto &&i : leaves)
    {
        cout << i << " ";
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