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
    def print_tree(self,root):
        if root == None:
            return
        print(root.val,end =":")
        if root.left:
            print("L: {} ,".format(root.left.val),end ="")
        if root.right:
            print("R: {} ,".format(root.right.val),end="")
        print("\n")
        self.print_tree(root.left)
        self.print_tree(root.right)
