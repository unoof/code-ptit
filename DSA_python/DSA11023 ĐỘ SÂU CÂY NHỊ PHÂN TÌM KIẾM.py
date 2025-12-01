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

def find_depth(node, depth):
    if not node:
        return depth

    return max(find_depth(node.left, depth+1), find_depth(node.right, depth+1))

def submit():
    n = int(input())
    edges = list(map(int, input().split()))

    root = TreeNode(edges[0])
    for i in range(1, n):
        add_to_tree(root, edges[i])


    print(find_depth(root, 0)-1)











test = int(input())
for i in range(test):
    submit()