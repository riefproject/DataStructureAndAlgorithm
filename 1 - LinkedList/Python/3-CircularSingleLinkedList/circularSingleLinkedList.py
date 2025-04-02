class Node:
    """
    Node class representing each element in the circular singly linked list.
    """
    def __init__(self, id, name, major):
        """
        Constructor to initialize a new node.
        
        :param id: Student ID
        :param name: Student name
        :param major: Student major
        """
        self.id = id
        self.name = name
        self.major = major
        self.next = None  # Pointer to the next node in the list


class LinkedList:
    """
    LinkedList class to manage the circular singly linked list.
    """
    def __init__(self):
        """
        Constructor to initialize an empty list.
        """
        self.head = None  # Pointer to the head of the list
        self.tail = None  # Pointer to the tail of the list
        self.size = 0     # Size of the list

    def create_circular_sl(self, id, name, major):
        """
        Function to create a circular singly linked list with the first node.
        
        :param id: Student ID
        :param name: Student name
        :param major: Student major
        """
        new_node = Node(id, name, major)
        new_node.next = new_node
        self.head = new_node
        self.tail = new_node
        self.size = 1

    def add_at_first_node(self, id, name, major):
        """
        Function to add a node at the beginning of the list.
        
        :param id: Student ID
        :param name: Student name
        :param major: Student major
        """
        if self.size == 0:
            self.create_circular_sl(id, name, major)
            return
        new_node = Node(id, name, major)
        new_node.next = self.head
        self.tail.next = new_node
        self.head = new_node
        self.size += 1

    def add_at_nth_node(self, id, name, major, pos):
        """
        Function to add a node at the nth position in the list.
        
        :param id: Student ID
        :param name: Student name
        :param major: Student major
        :param pos: Position to insert the new node
        """
        if pos < 1 or pos > self.size + 1:
            print("Invalid position!")
            return
        if pos == 1:
            self.add_at_first_node(id, name, major)
            return
        if pos == self.size + 1:
            self.add_at_last_node(id, name, major)
            return
        new_node = Node(id, name, major)
        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next
        new_node.next = cur.next
        cur.next = new_node
        self.size += 1

    def add_at_last_node(self, id, name, major):
        """
        Function to add a node at the end of the list.
        
        :param id: Student ID
        :param name: Student name
        :param major: Student major
        """
        if self.size == 0:
            self.create_circular_sl(id, name, major)
            return
        new_node = Node(id, name, major)
        new_node.next = self.head
        self.tail.next = new_node
        self.tail = new_node
        self.size += 1

    def update_first_node(self, id, name, major):
        """
        Function to update the first node in the list.
        
        :param id: New student ID
        :param name: New student name
        :param major: New student major
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.head.id = id
        self.head.name = name
        self.head.major = major

    def update_nth_node(self, id, name, major, pos):
        """
        Function to update the nth node in the list.
        
        :param id: New student ID
        :param name: New student name
        :param major: New student major
        :param pos: Position of the node to update
        """
        if pos < 1 or pos > self.size:
            print("Invalid position!")
            return
        cur = self.head
        for _ in range(1, pos):
            cur = cur.next
        cur.id = id
        cur.name = name
        cur.major = major

    def update_last_node(self, id, name, major):
        """
        Function to update the last node in the list.
        
        :param id: New student ID
        :param name: New student name
        :param major: New student major
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.tail.id = id
        self.tail.name = name
        self.tail.major = major

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
        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next
        cur.next = cur.next.next
        if pos == self.size:
            self.tail = cur
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
            cur = self.head
            while cur.next != self.tail:
                cur = cur.next
            self.tail = cur
            self.tail.next = self.head
        self.size -= 1

    def print_circular_sl(self):
        """
        Function to print the circular singly linked list.
        """
        if self.size == 0:
            print("List is empty!")
            return
        print(f"Number of Nodes: {self.size}")  # Display the total number of nodes
        cur = self.head
        i = 1
        while True:
            print(f"Node {i}")
            print(f"ID\t\t: {cur.id}")
            print(f"Name\t\t: {cur.name}")
            print(f"Major\t\t: {cur.major}\n")
            cur = cur.next
            i += 1
            if cur == self.head:
                break

    def count_nodes(self):
        """
        Utility function to count the number of nodes in the list.
        
        :return: Total number of nodes
        """
        return self.size


if __name__ == "__main__":
    list = LinkedList()

    # Create the circular singly linked list with the first node
    list.create_circular_sl("11223399", "Arief F-sa", "Computer Science")
    list.print_circular_sl()
    print("==========\n\n\n")

    # Add a node at the beginning of the list
    list.add_at_first_node("11223398", "Nisa Uswa", "Psychology")
    list.print_circular_sl()
    print("==========\n\n\n")

    # Add a node at the end of the list
    list.add_at_last_node("11223400", "Pejeel", "Drop out")
    list.print_circular_sl()
    print("==========\n\n\n")

    # Remove the first node from the list
    list.remove_first_node()
    list.print_circular_sl()
    print("==========\n\n\n")

    # Remove the last node from the list
    list.remove_last_node()
    list.print_circular_sl()
    print("==========\n\n\n")

    # Add nodes at the beginning and end of the list
    list.add_at_first_node("11223398", "Nisa Uswa", "Psychology")
    list.add_at_last_node("11223400", "Pejeel", "Drop out")
    list.print_circular_sl()
    print("==========\n\n\n")

    # Add nodes at specific positions in the list
    list.add_at_nth_node("11223401", "dummy1", "Math", 3)
    list.add_at_nth_node("11223402", "dummy2", "Physics", 2)
    list.print_circular_sl()
    print("==========\n\n\n")

    # Remove the node at the specified position in the list
    list.remove_nth_node(2)
    list.print_circular_sl()
    print("==========\n\n\n")