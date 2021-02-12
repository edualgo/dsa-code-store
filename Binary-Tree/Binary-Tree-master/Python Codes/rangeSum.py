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
    def rangeSumBST(self, root,L,R):
        if(root == None):
            return 0
        sum1 = 0; sum2 = 0
        if(root.left):
            sum1 = self.rangeSumBST(root.left,L,R)
        if(root.right):
            sum2 = self.rangeSumBST(root.right,L,R)
        if((root.val >= L )and (root.val <= R)):
            return root.val + sum1 + sum2
        else:
            return sum1 + sum2
