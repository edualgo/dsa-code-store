
# creating the Node class to frame a single node
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

# creating a Linked List class to get all the helper functionalities inside
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self,data):
        if self.tail is None:
            self.head = Node(data)
            self.tail = self.head

        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next

    def printLL(self):
        temp = self.head
        while(temp): 
            print(temp.data, end =" ")
            temp = temp.next

# creating a solution class to implement more methods on the Linked List
class solution:

    def length(self,head):
        temp = head
        count = 0
        while(temp):
            temp = temp.next
            count+=1
        return count

llist = LinkedList()
llist.head = Node(1)
arr = list(map(int,input().split()))
for i in arr:
    llist.append(i)
llist.printLL()
sol = solution()
print(sol.length(llist.head))
