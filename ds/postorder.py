class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.data = value


"""
In this traversal method, the root node is visited last.
First we traverse the left subtree, then the right subtree and finally the root node.

POSTORDER - (left, right, root)
"""

def postorder(node):
    if(node is not None):
        postorder(node.left)
        postorder(node.right)
        print(node.data)


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



postorder(root)
