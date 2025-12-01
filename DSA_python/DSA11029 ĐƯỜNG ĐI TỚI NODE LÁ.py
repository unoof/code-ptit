class TreeNode:
    def __init__(self, parent = 0, child = None):
        self.parent = parent
        self.child = child if child is not None else []

def add_to_tree(edges):
    mp = dict()
    child_set = set()

    for parent, child in edges:
        if parent not in mp: mp[parent] = TreeNode(parent)
        if child not in mp: mp[child] = TreeNode(child)

        mp[parent].child.append(mp[child])
        child_set.add(child)
    
    parents = [parent for parent,_ in edges]
    root = parent

    for parent in parents:
        if parent not in child_set:
            root = parent
    
    return mp[root]

def is_leaves(node):
    if not node: return False
    if len(node.child) == 0: return True
    return False

def traversal(node, ans, now):
    if not node: return

    now.append(node.parent)

    if is_leaves(node) == False:
        for i in node.child:
            traversal(i, ans, now)
    elif is_leaves(node) == True:
        ans.append(now[:])

    now.pop()
    return ans

def cmp(A):
    return A[-1]

def submit():
    n = int(input())
    edges = list()
    for i in range(n-1):
        parent, child = map(int, input().split())
        edges.append((parent, child))

    root = add_to_tree(edges)

    ans = traversal(root, [], [])

    ans.sort(key = cmp)

    for i in ans:
        print(" ".join(map(str, i)))











test = int(input())
for i in range(test):
    submit()