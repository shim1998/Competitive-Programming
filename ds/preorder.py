class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value

"""
In this traversal method, the root node is visited first, 
then the left subtree and finally the right subtree.

PREORDER - (root, left, right)
"""


def preorder(node):
    if(node is not None):
        print(node.data)
        preorder(node.left)
        preorder(node.right)

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


preorder(root)
