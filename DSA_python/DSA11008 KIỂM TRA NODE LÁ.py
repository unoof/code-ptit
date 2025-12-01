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

def traversal(node, depth, mp):
    if not node:
        mp.add(depth)
        return

    traversal(node.left, depth+1, mp)
    traversal(node.right, depth+1, mp)

def submit():
    n = int(input())
    A = list(map(str, input().split()))
    edges = list()

    for i in range(2, len(A), 3):
        edges.append((A[i-2], A[i-1], A[i]))

    root = add_to_tree(edges)
    mp = set()
    traversal(root, 0, mp)

    print(1 if len(mp) == 1 else 0)







test = int(input())
for i in range(test):
    submit()