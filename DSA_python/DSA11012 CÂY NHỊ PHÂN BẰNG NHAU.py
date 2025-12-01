from collections import deque

class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


def add_to_tree(edges):
    if not edges:
        return

    nodes = dict()

    for parent, child, pos in edges:
        if parent not in nodes:
            nodes[parent] = TreeNode(parent)
        if child not in nodes:
            nodes[child] = TreeNode(child)
        if pos == 'L':
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]
        
    children = [child for _,child,_ in edges]
    parents = [parent for parent,_,_ in edges]
    root = parents[0]

    for parent in parents:
        if parent not in children:
            root = parent
    
    return nodes[root]

def traversal(node1, node2):
    if not node1 and not node2:
        return True
    elif (node1.val == node2.val) and node1 and node2:
        return traversal(node1.left, node2.left) and traversal(node1.right, node2.right)
    return False

def submit():
    n = int(input())
    A = list(input().split())
    
    edges = list()
    for i in range(2, len(A), 3):
        edges.append((A[i-2], A[i-1], A[i]))
    root1 = add_to_tree(edges)

    m = int(input())
    B = list(input().split())

    edges = list()
    for i in range(2, len(A), 3):
        edges.append((B[i-2], B[i-1], B[i]))
    root2 = add_to_tree(edges)

    print(1 if traversal(root1, root2) else 0)









test = int(input())
for i in range(test):
    submit()