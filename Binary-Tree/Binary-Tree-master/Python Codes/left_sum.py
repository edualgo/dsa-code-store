class Node:
    def __init__(self, val):

        self.left = None
        self.right = None
        self.val = val

    def insert(self, val):
        if self.val:
            if val < self.val:
                if self.left is None:
                    self.left = Node(val)
                else:
                    self.left.insert(val)
            else:
                if self.right is None:
                    self.right = Node(val)
                else:
                    self.right.insert(val)
        else:
            self.val = val

class BinaryTreeAlgorithms:
    def sumOfLeftLeaves(self, root):
        if(root == None):
            return 0
        sum = 0
        if(root.left != None and (root.left.left == None and root.left.right == None)):
            sum = root.left.val
        return sum + self.sumOfLeftLeaves(root.left)+self.sumOfLeftLeaves(root.right)
