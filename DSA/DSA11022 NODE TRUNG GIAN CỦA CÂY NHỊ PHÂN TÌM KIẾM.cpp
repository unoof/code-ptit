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

vector<int> find_parents(TreeNode* node)
{
    vector<int> parents;

    if (node->left || node->right)
    {
        parents.push_back(node->val);
    }
    
    vector<int> left, right;
    if (node->left) left = find_parents(node->left);
    if (node->right) right = find_parents(node->right);

    parents.insert(parents.end(), left.begin(), left.end());
    parents.insert(parents.end(), right.begin(), right.end());

    return parents;
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
    
    vector<int> parents = find_parents(root);

    cout << parents.size();
    

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