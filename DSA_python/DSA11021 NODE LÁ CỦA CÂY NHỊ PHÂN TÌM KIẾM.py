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

def find_leaves(node):
    leaves = list()
    if not node.right and not node.left:
        leaves.append(node.val)
        return leaves

    left, right = list(), list()
    if node.left: left = find_leaves(node.left)
    if node.right: right = find_leaves(node.right)

    leaves = left[:] + right[:]
    return leaves

def submit():
    n = int(input())
    edges = list(map(int, input().split()))

    root = TreeNode(edges[0])
    for i in range(1, n):
        add_to_tree(root, edges[i])

    leaves = find_leaves(root)

    print(" ".join(map(str, leaves)))











test = int(input())
for i in range(test):
    submit()