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
    def isCousins(self, root, x, y):
        if not root:
            return root
        queue = collections.deque([root])
        level = set()
        last = n_last = root
        while any(queue):
            node = queue.popleft()
            same_father = set()
            if node.left:
                level.add(node.left.val)
                queue.append(node.left)
                n_last = node.left
                same_father.add(node.left.val)
            if node.right:
                level.add(node.right.val)
                queue.append(node.right)
                n_last = node.right
                same_father.add(node.right.val)
            if x in same_father and y in same_father:
                return False
            if node == last:
                last = n_last
                if x in level and y in level:
                    return True
                level = set()
        return False
