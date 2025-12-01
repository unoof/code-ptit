#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string v) : val(v), left(nullptr), right(nullptr) {}
};

long long traversal(TreeNode* node)
{
    if (!node->left && !node->right)
    {
        return stoll(node->val);
    }

    if (node->val == "+")
    {
        return traversal(node->left) + traversal(node->right);
    }
    else if (node->val == "-")
    {
        return traversal(node->left) - traversal(node->right);
    }
    else if (node->val == "*")
    {
        return traversal(node->left) * traversal(node->right);
    }
    else if (node->val == "/")
    {
        return traversal(node->left) / traversal(node->right);
    }
}

bool add(TreeNode* root, TreeNode* node, int depth, int max)
{
    if (depth >= max)
    {
        return false;
    }
    
    if (!root->left)
    {
        root->left = node;
    }
    else if (!root->right)
    {
        root->right = node;
    }
    else
    {
        if (add(root->left, node, depth+1, max)) return true;
        if (add(root->right, node, depth+1, max)) return true;
        return false;
    }
    return true;
}

int max_depth(int n)
{
    int now = 1, count = 1;
    while (n > 0)
    {
        now *= 2;
        n -= now;
        count++;
    }
    return count;
}

void submit()
{
    int n;
    cin >> n;
    vector<string> B(n);
    for (auto &&i : B) cin >> i;
    
    TreeNode* root = new TreeNode(B[0]);

    for (int i = 1; i < n; i++)
    {
        TreeNode* node = new TreeNode(B[i]);

        add(root, node, 1, max_depth(i));
    }
    

    cout << traversal(root);
    

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