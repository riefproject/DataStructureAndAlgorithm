class Node:
    """
    Node class representing each element in the doubly linked list.
    """
    def __init__(self, name, username, email, password):
        """
        Constructor to initialize a new node.
        
        :param name: Name of the user
        :param username: Username of the user
        :param email: Email of the user
        :param password: Password of the user
        """
        self.name = name
        self.username = username
        self.email = email
        self.password = password
        self.prev = None  # Pointer to the previous node in the list
        self.next = None  # Pointer to the next node in the list


class LinkedList:
    """
    LinkedList class to manage the doubly linked list.
    """
    def __init__(self):
        """
        Constructor to initialize an empty list.
        """
        self.head = None  # Pointer to the head of the list
        self.tail = None  # Pointer to the tail of the list
        self.size = 0     # Size of the list

    def create_double_linked_list(self, name, username, email, password):
        """
        Function to create a doubly linked list with the first node.
        
        :param name: Name of the user
        :param username: Username of the user
        :param email: Email of the user
        :param password: Password of the user
        """
        new_node = Node(name, username, email, password)
        self.head = new_node
        self.tail = new_node
        self.size = 1

    def add_at_first_node(self, name, username, email, password):
        """
        Function to add a node at the beginning of the list.
        
        :param name: Name of the user
        :param username: Username of the user
        :param email: Email of the user
        :param password: Password of the user
        """
        if self.size == 0:
            self.create_double_linked_list(name, username, email, password)
            return
        new_node = Node(name, username, email, password)
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
        self.size += 1

    def add_at_nth_node(self, name, username, email, password, pos):
        """
        Function to add a node at the nth position in the list.
        
        :param name: Name of the user
        :param username: Username of the user
        :param email: Email of the user
        :param password: Password of the user
        :param pos: Position to insert the new node
        """
        if pos < 1 or pos > self.size + 1:
            print("Invalid position!")
            return
        if pos == 1:
            self.add_at_first_node(name, username, email, password)
            return
        if pos == self.size + 1:
            self.add_at_last_node(name, username, email, password)
            return
        new_node = Node(name, username, email, password)
        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next
        new_node.next = cur.next
        new_node.prev = cur
        cur.next.prev = new_node
        cur.next = new_node
        self.size += 1

    def add_at_last_node(self, name, username, email, password):
        """
        Function to add a node at the end of the list.
        
        :param name: Name of the user
        :param username: Username of the user
        :param email: Email of the user
        :param password: Password of the user
        """
        if self.size == 0:
            self.create_double_linked_list(name, username, email, password)
            return
        new_node = Node(name, username, email, password)
        new_node.prev = self.tail
        self.tail.next = new_node
        self.tail = new_node
        self.size += 1

    def update_first_node(self, name, username, email, password):
        """
        Function to update the first node in the list.
        
        :param name: New name of the user
        :param username: New username of the user
        :param email: New email of the user
        :param password: New password of the user
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.head.name = name
        self.head.username = username
        self.head.email = email
        self.head.password = password

    def update_nth_node(self, name, username, email, password, pos):
        """
        Function to update the nth node in the list.
        
        :param name: New name of the user
        :param username: New username of the user
        :param email: New email of the user
        :param password: New password of the user
        :param pos: Position of the node to update
        """
        if pos < 1 or pos > self.size:
            print("Invalid position!")
            return
        cur = self.head
        for _ in range(1, pos):
            cur = cur.next
        cur.name = name
        cur.username = username
        cur.email = email
        cur.password = password

    def update_last_node(self, name, username, email, password):
        """
        Function to update the last node in the list.
        
        :param name: New name of the user
        :param username: New username of the user
        :param email: New email of the user
        :param password: New password of the user
        """
        if self.size == 0:
            print("List is empty!")
            return
        self.tail.name = name
        self.tail.username = username
        self.tail.email = email
        self.tail.password = password

    def remove_at_first(self):
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
            self.head.prev = None
        self.size -= 1

    def remove_at_nth_node(self, pos):
        """
        Function to remove the nth node from the list.
        
        :param pos: Position of the node to remove
        """
        if pos < 1 or pos > self.size:
            print("Invalid position!")
            return
        if pos == 1:
            self.remove_at_first()
            return
        if pos == self.size:
            self.remove_at_last()
            return
        cur = self.head
        for _ in range(1, pos):
            cur = cur.next
        cur.prev.next = cur.next
        cur.next.prev = cur.prev
        self.size -= 1

    def remove_at_last(self):
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
            self.tail.next = None
        self.size -= 1

    def print_double_linked_list(self):
        """
        Function to print the doubly linked list.
        """
        if self.size == 0:
            print("List is empty!")
            return
        print(f"Number of Nodes: {self.size}")  # Display the total number of nodes
        cur = self.head
        i = 1
        while cur is not None:
            print(f"Node {i}")
            print(f"Name\t\t: {cur.name}")
            print(f"Username\t: {cur.username}")
            print(f"Email\t\t: {cur.email}")
            print(f"Password\t: {cur.password}\n")
            cur = cur.next
            i += 1

    def count_nodes(self):
        """
        Utility function to count the number of nodes in the list.
        
        :return: Total number of nodes
        """
        return self.size


if __name__ == "__main__":
    list = LinkedList()

    # Create the doubly linked list with the first node
    list.create_double_linked_list("Arief F-sa", "ariefff", "arief@mail.id", "Arief123")
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Add a node at the end of the list
    list.add_at_last_node("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123")
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Add a node at the beginning of the list
    list.add_at_first_node("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123")
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Remove the first node from the list
    list.remove_at_first()
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Remove the last node from the list
    list.remove_at_last()
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Add multiple nodes at the beginning of the list
    list.add_at_first_node("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123")
    list.add_at_first_node("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123")
    list.add_at_first_node("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123")
    list.add_at_first_node("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123")
    list.add_at_first_node("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123")
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Add a node at the nth position in the list
    list.add_at_nth_node("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5)
    list.print_double_linked_list()
    print("==========\n\n\n")

    # Remove the nth node from the list
    list.remove_at_nth_node(6)
    list.print_double_linked_list()
    print("==========\n\n\n")