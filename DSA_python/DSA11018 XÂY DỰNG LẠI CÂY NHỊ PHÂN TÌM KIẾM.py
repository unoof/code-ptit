class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


def add_to_tree(root, node):
    if root.val > node:
        if not root.left: root.left = TreeNode(node)
        else: add_to_tree(root.left, node)
    elif root.val < node:
        if not root.right: root.right = TreeNode(node)
        else: add_to_tree(root.right, node)

def pre_order(node):
    if not node:
        return
    
    print(node.val, end=" ")
    pre_order(node.left)
    pre_order(node.right)

def submit():
    n = int(input())
    edges = list(map(int, input().split()))

    root = TreeNode(edges[0])
    for i in range(1, n):
        add_to_tree(root, edges[i])

    pre_order(root)
    print()











test = int(input())
for i in range(test):
    submit()