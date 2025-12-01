#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct point
{
    int parent, child;
    char pos;
};

void add(TreeNode** root, point* node, int n)
{
    unordered_map<int,TreeNode*> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(node[i].parent) == mp.end())
        {
            (*root) = new TreeNode(node[i].parent);
            if (node[i].pos == 'L')
            {
                (*root)->left = new TreeNode(node[i].child);
                mp[node[i].child] = (*root)->left;
            }
            else
            {
                (*root)->right = new TreeNode(node[i].child);
                mp[node[i].child] = (*root)->right;
            }
            mp[node[i].parent] = (*root);
        }
        else
        {
            if (node[i].pos == 'L')
            {
                mp[node[i].parent]->left = new TreeNode(node[i].child);
                mp[node[i].child] = mp[node[i].parent]->left;
            }
            else
            {
                mp[node[i].parent]->right = new TreeNode(node[i].child);
                mp[node[i].child] = mp[node[i].parent]->right;
            }
        }
    }
}


vector<int> in_order(TreeNode* node)
{
    vector<int> ans, left, right;

    if (node->left)
    {
        left = in_order(node->left);
    }
    if (node->right)
    {
        right = in_order(node->right);
    }
    
    ans.insert(ans.end(), left.begin(), left.end());
    ans.push_back(node->val);
    ans.insert(ans.end(), right.begin(), right.end());
    

    return ans;
}

void submit()
{
    int n;
    cin >> n;
    point* node = new point[n];

    for (int i = 0; i < n; i++)
    {
        cin >> node[i].parent >> node[i].child >> node[i].pos;
    }
    
    TreeNode* root = nullptr;
    add(&root, node, n);

    vector<int> ans = in_order(root);

    sort(ans.begin(), ans.end());

    for (auto &&i : ans)
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