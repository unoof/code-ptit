#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};


void add(TreeNode** root, int node)
{
    if (!(*root))
    {
        (*root) = new TreeNode(node);
    }
    else if (node < (*root)->val)
    {
        if (!(*root)->left) (*root)->left = new TreeNode(node);
        else add(&(*root)->left, node);
    }
    else if (node > (*root)->val)
    {
        if (!(*root)->right) (*root)->right = new TreeNode(node);
        else add(&(*root)->right, node);
    }
}

void insert(TreeNode** root, vector<int> node)
{
    if (node.empty())
    {
        return;
    }
    
    int mid = (node.size()-1)/2;

    add(&(*root), node[mid]);

    if (node.size() > 1)
    {
        vector<int> left(node.begin(), node.begin()+mid);
        vector<int> right(node.begin()+mid+1, node.end());
        
        insert(root, left);
        insert(root, right);
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

    sort(node.begin(), node.end());

    TreeNode* root = nullptr;

    insert(&root, node);

    vector<int> leaves = find_leaves(root);

    cout << leaves.size();

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