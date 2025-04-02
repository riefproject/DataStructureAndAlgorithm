class Node:
    """
    Node class representing each element in the circular doubly linked list.
    """
    def __init__(self, name, price, available):
        """
        Constructor to initialize a new node.
        
        :param name: Item name
        :param price: Item price
        :param available: Item availability
        """
        self.name = name
        self.price = price
        self.available = available
        self.prev = None  # Pointer to the previous node in the list
        self.next = None  # Pointer to the next node in the list


class LinkedList:
    """
    LinkedList class to manage the circular doubly linked list.
    """
    def __init__(self):
        """
        Constructor to initialize an empty list.
        """
        self.head = None  # Pointer to the head of the list
        self.tail = None  # Pointer to the tail of the list
        self.size = 0     # Size of the list

    def create_circular_dl(self, name, price, available):
        """
        Function to create a circular doubly linked list with the first node.
        
        :param name: Item name
        :param price: Item price
        :param available: Item availability
        """
        new_node = Node(name, price, available)
        new_node.next = new_node
        new_node.prev = new_node
        self.head = new_node
        self.tail = new_node
        self.size = 1

    def add_at_first_node(self, name, price, available):
        """
        Function to add a node at the beginning of the list.
        
        :param name: Item name
        :param price: Item price
        :param available: Item availability
        """
        if self.size == 0:
            self.create_circular_dl(name, price, available)
            return
        new_node = Node(name, price, available)
        new_node.next = self.head
        new_node.prev = self.tail
        self.head.prev = new_node
        self.tail.next = new_node
        self.head = new_node
        self.size += 1

    def add_at_nth_node(self, name, price, available, pos):
        """
        Function to add a node at the nth position in the list.
        
        :param name: Item name
        :param price: Item price
        :param available: Item availability
        :param pos: Position to insert the new node
        """
        if pos < 1 or pos > self.size + 1:
            print("Invalid position!")
            return
        if pos == 1:
            self.add_at_first_node(name, price, available)
            return
        if pos == self.size + 1:
            self.add_at_last_node(name, price, available)
            return
        new_node = Node(name, price, available)
        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next
        new_node.next = cur.next
        new_node.prev = cur
        cur.next.prev = new_node
        cur.next = new_node
        self.size += 1

    def add_at_last_node(self, name, price, available):
        """
        Function to add a node at the end of the list.
        
        :param name: Item name
        :param price: Item price
        :param available: Item availability
        """
        if self.size == 0:
            self.create_circular_dl(name, price, available)
            return
        new_node = Node(name, price, available)
        new_node.next = self.head
        new_node.prev = self.tail
        self.tail.next = new_node
        self.head.prev = new_node
        self.tail = new_node
        self.size += 1

    def update_first_node(self, name, price, available):
        """
        Function to update the first node in the list.
        
        :param name: New item name
        :param price: New item price
        :param available: New item availability
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.head.name = name
        self.head.price = price
        self.head.available = available

    def update_nth_node(self, name, price, available, pos):
        """
        Function to update the nth node in the list.
        
        :param name: New item name
        :param price: New item price
        :param available: New item availability
        :param pos: Position of the node to update
        """
        if pos < 1 or pos > self.size:
            print("Invalid position!")
            return
        cur = self.head
        for _ in range(1, pos):
            cur = cur.next
        cur.name = name
        cur.price = price
        cur.available = available

    def update_last_node(self, name, price, available):
        """
        Function to update the last node in the list.
        
        :param name: New item name
        :param price: New item price
        :param available: New item availability
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.tail.name = name
        self.tail.price = price
        self.tail.available = available

    def remove_first_node(self):
        """
        Function to remove the first node from the list.
        """
        if self.size == 0:
            print("List is empty!")
            return
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = self.tail
            self.tail.next = self.head
        self.size -= 1

    def remove_nth_node(self, pos):
        """
        Function to remove the nth node from the list.
        
        :param pos: Position of the node to remove
        """
        if pos < 1 or pos > self.size:
            print("Invalid position!")
            return
        if pos == 1:
            self.remove_first_node()
            return
        if pos == self.size:
            self.remove_last_node()
            return
        cur = self.head
        for _ in range(1, pos):
            cur = cur.next
        cur.prev.next = cur.next
        cur.next.prev = cur.prev
        self.size -= 1

    def remove_last_node(self):
        """
        Function to remove the last node from the list.
        """
        if self.size == 0:
            print("List is empty!")
            return
        if self.size == 1:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = self.head
            self.head.prev = self.tail
        self.size -= 1

    def print_circular_dl(self):
        """
        Function to print the circular doubly linked list.
        """
        if self.size == 0:
            print("List is empty!")
            return
        cur = self.head
        for _ in range(self.size):
            print(f"Name: {cur.name}\nPrice: {cur.price}\nAvailable: {cur.available}")
            cur = cur.next

    def count_nodes(self):
        """
        Utility function to count the number of nodes in the list.
        
        :return: Total number of nodes
        """
        return self.size


if __name__ == "__main__":
    list = LinkedList()

    # Create the circular doubly linked list with the first node
    list.create_circular_dl("Laptop", 20000000, 20)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Add a node at the beginning of the list
    list.add_at_first_node("Handphone", 5000000, 50)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Add nodes at the end of the list
    list.add_at_last_node("Mouse", 1200000, 100)
    list.add_at_last_node("Keyboard", 2250000, 100)
    list.add_at_last_node("Headphone", 1800000, 100)
    list.add_at_last_node("Monitor", 4200000, 100)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Remove the first node from the list
    list.remove_first_node()
    list.print_circular_dl()
    print("==========\n\n\n")

    # Remove the last node from the list
    list.remove_last_node()
    list.print_circular_dl()
    print("==========\n\n\n")

    # Add a node at the nth position in the list
    list.add_at_nth_node("RTX 5090", 40000000, 15, 3)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Remove the nth node from the list
    list.remove_nth_node(4)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Update the first node in the list
    list.update_first_node("Laptop", 19000000, 10)
    # Update the nth node in the list
    list.update_nth_node("Mouse", 1000000, 3, 2)
    # Update the last node in the list
    list.update_last_node("Headphone", 1900000, 5)
    list.print_circular_dl()
    print("==========\n\n\n")

    # Print the total number of nodes in the list
    print("Total nodes:", list.count_nodes())