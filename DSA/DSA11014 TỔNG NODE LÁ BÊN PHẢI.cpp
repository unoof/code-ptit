#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct point
{
    int parent, child;
    char pos;
};



long long total = 0;

void add(TreeNode **node, point *edges, int n)
{
    map<int,TreeNode*> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(edges[i].parent) == m.end())
        {
            (*node) = new TreeNode(edges[i].parent);
            if (edges[i].pos == 'L')
            {
                (*node)->left = new TreeNode(edges[i].child);
                m[edges[i].child] = (*node)->left;
            }
            else
            {
                (*node)->right = new TreeNode(edges[i].child);
                m[edges[i].child] = (*node)->right;
            }
            m[edges[i].parent] = (*node);
        }
        else
        {
            if (edges[i].pos == 'L')
            {
                m[edges[i].parent]->left = new TreeNode(edges[i].child);
                m[edges[i].child] = m[edges[i].parent]->left;
            }
            else
            {
                m[edges[i].parent]->right = new TreeNode(edges[i].child);
                m[edges[i].child] = m[edges[i].parent]->right;
            }
        }
    }
}

void count_right_leaves(TreeNode *node)
{
    if (!node)
    {
        return;
    }

    if (node->right && !node->right->left && !node->right->right)
    {
        total += node->right->val;
    }
    
    count_right_leaves(node->left);
    count_right_leaves(node->right);
    return;
}

void submit()
{
    total = 0;
    int n;
    cin >> n;

    point *edges = new point[n];

    for (int i = 0; i < n; i++)
    {
        cin >> edges[i].parent >> edges[i].child >> edges[i].pos;
    }

    TreeNode *root = nullptr;
    add(&root, edges, n);
    

    count_right_leaves(root);
    cout << total;

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