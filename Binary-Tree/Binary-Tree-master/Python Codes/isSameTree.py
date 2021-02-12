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
    def isSameTree(self, p, q):
        if(p == None and q == None):
            return True
        if(p == None or q == None):
            return False
        return (p.val == q.val) and (self.isSameTree(p.left,q.left)) and (self.isSameTree(p.right,q.right))
