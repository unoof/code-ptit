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

def post_order(node):
    if not node:
        return

    post_order(node.left)
    post_order(node.right)
    print(node.val, end=" ")

def submit():
    n = int(input())
    edges = list(map(int, input().split()))
    edges.sort()

    root = TreeNode(edges[(n-1)//2])
    change_to_tree(root, edges)

    post_order(root)

    print()











test = int(input())
for i in range(test):
    submit()