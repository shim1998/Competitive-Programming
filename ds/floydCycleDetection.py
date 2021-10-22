# floyd's algorithm for cycle detection

class node:
    def __init__(self, data):
        self.data = data
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        newNode = node(data)
        if self.head is None:
            self.head = newNode
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = newNode

    def printList(self):
        curr = self.head
        while curr:
            print(curr.data, end=" ")
            curr = curr.next
        print()

    def floydCycleDetection(self):
        slow = self.head
        fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                print("Cycle detected at",end=" ")
                print(slow.data)
                return
        print("No cycle detected")

ll = linkedList()
ll.insert(1)
ll.insert(2)
ll.insert(3)
ll.insert(4)
ll.insert(5)
ll.insert(6)

ll.head.next.next.next.next.next.next = ll.head.next.next

ll.floydCycleDetection()