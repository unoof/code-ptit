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

void post_order(TreeNode* node)
{
    if (!node)
    {
        return;
    }

    post_order(node->left);
    post_order(node->right);
    cout << node->val << " ";
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

    post_order(root);

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