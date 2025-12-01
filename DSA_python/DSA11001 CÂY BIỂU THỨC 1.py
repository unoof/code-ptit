class TreeNode:
    def __init__(self, val = 0, left = None, right = None):
        self.val = val
        self.left = left
        self.right = right


def traversal(node):
    if node is None:
        return

    traversal(node.left)
    print(node.val, end="")
    traversal(node.right)

def submit():
    s = input()
    temp = "+-/*"
    A = list()

    for i in s:
        if temp.find(i) == -1:
            A.append(TreeNode(i))
        else:
            root = TreeNode(i)
            root.right = A.pop()
            root.left = A.pop()
            A.append(root)

    root = A[-1]

    traversal(root)
    print()





test = int(input())
for i in range(test):
    submit()