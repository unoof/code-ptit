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

def change_to_tree(root, edges):
    if len(edges) == 0: return

    mid = (len(edges)-1)//2

    add_to_tree(root, edges[mid])

    if len(edges) > 1:
        left = edges[:mid]
        right = edges[mid+1:]

        change_to_tree(root, left)
        change_to_tree(root, right)

def find_leaves(node):
    leaves = list()

    if not node.left and not node.right:
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
    edges.sort()

    root = TreeNode(edges[(n-1)//2])
    change_to_tree(root, edges)

    leaves = find_leaves(root)

    print(len(leaves))











test = int(input())
for i in range(test):
    submit()