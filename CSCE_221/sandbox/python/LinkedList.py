class Node: 
  
    def __init__(self, data): 
        self.next = None  
        self.data = data  
  
class LinkedList: 
  
    def __init__(self): 
        self.head = None

    def iterator(self):
        return self.head

    def push(self, new_data):
        new_Node = Node(new_data)
        new_Node.next = self.head
        self.head = new_Node

    def append(self, new_data):
        iterator = self.iterator()
        while(iterator.next != None):
            iterator = iterator.next
        new_Node = Node(new_data)
        iterator.next = new_Node
    
    def printList(self):
        iterator = self.iterator()
        while(iterator.next != None):
            print iterator.data 
            iterator = iterator.next
        print iterator.data

    def put(self, new_data, position):
        iterator = self.iterator()
        for i in range(position-1):
            iterator = iterator.next
        new_node = Node(new_data)
        new_node.next = iterator.next
        iterator.next = new_node


if __name__=='__main__': 
  
    list = LinkedList()

    list.push(2)
    list.push(1)
    list.push(0)

    list.append(4)
    list.append(5)

    list.put(3, 3)

    list.printList()
  