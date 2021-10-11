class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value


"""
In this traversal method, the left subtree is visited first, 
then the root and later the right sub-tree.

INORDER - (left, root, right)
"""

def inorder(node):
    if(node is not None):
        inorder(node.left)
        print(node.data)
        inorder(node.right)

def insertNode(root, newValue):
    if root is None:
        root = Node(newValue)
        return root
    if newValue > root.data:
        root.right = insertNode(root.right, newValue)
    else:
        root.left = insertNode(root.left, newValue)
    return root

root = insertNode(None, 15)
insertNode(root,12)
insertNode(root,2)
insertNode(root,23)
insertNode(root,3)


inorder(root)