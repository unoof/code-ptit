#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

void traversal(TreeNode* node)
{
    if (!node)
    {
        return;
    }
    
    traversal(node->left);
    cout << node->val;
    traversal(node->right);
}

void submit()
{
    string s;
    getline(cin, s);

    string temp = "+/*-";
    stack<TreeNode*> A;

    for (int i = 0; i < s.size(); i++)
    {
        if (temp.find(s[i]) == string::npos)
        {
            A.push(new TreeNode(s[i]));
        }
        else
        {
            TreeNode* root = new TreeNode(s[i]);
            root->right = A.top(); A.pop();
            root->left = A.top(); A.pop();
            A.push(root);
        }
    }
    
    TreeNode* root = A.top();

    traversal(root);
    

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