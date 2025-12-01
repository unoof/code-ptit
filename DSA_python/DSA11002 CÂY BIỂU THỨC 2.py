class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


def add(root, node, depth, max):
    if depth >= max:
        return False
    
    if root.left is None:
        root.left = node
    elif root.right is None:
        root.right =  node
    else:
        if add(root.left, node, depth+1, max): return True
        if add(root.right, node, depth+1, max): return True
        return False
    return True

def traversal(node):
    if node.left is None and node.right is None:
        return int(node.val)
    
    if node.val == '+':
        return traversal(node.left) + traversal(node.right)
    elif node.val == '/':
        return traversal(node.left) // traversal(node.right)
    elif node.val == '*':
        return traversal(node.left) * traversal(node.right)
    elif node.val == '-':
        return traversal(node.left) - traversal(node.right)

def max_depth(n):
    now, count = 1, 1
    while n > 0:
        now *= 2
        n -= now
        count +=1
    return count

def submit():
    n = int(input())
    temp = "+-/*"
    A = list(map(str, input().split()))

    root = TreeNode(A[0])

    for i in range(1, n):
        node = TreeNode(A[i])

        add(root, node, 1, max_depth(i))

    print(traversal(root))







test = int(input())
for i in range(test):
    submit()