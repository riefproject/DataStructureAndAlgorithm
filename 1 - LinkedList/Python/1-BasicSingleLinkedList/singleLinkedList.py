class Node:
    """
    Node class representing each element in the singly linked list.
    """
    def __init__(self, title, author, year):
        """
        Constructor to initialize a new node.
        
        :param title: Title of the book
        :param author: Author of the book
        :param year: Publication year of the book
        """
        self.title = title
        self.author = author
        self.year = year
        self.next = None  # Pointer to the next book in the list


class LinkedList:
    """
    LinkedList class to manage the singly linked list.
    """
    def __init__(self):
        """
        Constructor to initialize an empty list.
        """
        self.head = None  # Pointer to the head of the list
        self.tail = None  # Pointer to the tail of the list
        self.size = 0     # Size of the list

    def add_node(self, title, author, year):
        """
        Function to add a node at the end of the linked list.
        
        :param title: Title of the book
        :param author: Author of the book
        :param year: Publication year of the book
        """
        new_book = Node(title, author, year)  # Create a new node

        if self.head is None:  # If the list is empty
            self.head = new_book
            self.tail = new_book
        else:
            self.tail.next = new_book
            self.tail = new_book

        self.size += 1

    def add_at_first_node(self, title, author, year):
        """
        Function to add a node at the beginning of the linked list.
        
        :param title: Title of the book
        :param author: Author of the book
        :param year: Publication year of the book
        """
        new_book = Node(title, author, year)  # Create a new node

        new_book.next = self.head
        self.head = new_book

        if self.size == 0:
            self.tail = new_book

        self.size += 1

    def add_at_nth_node(self, title, author, year, pos):
        """
        Function to add a node at a specified position in the linked list.
        
        :param title: Title of the book
        :param author: Author of the book
        :param year: Publication year of the book
        :param pos: Position to insert the new node
        """
        if pos < 1 or pos > self.size + 1:  # Validate position
            print("Position out of range")
            return

        if pos == 1:  # If adding at the first position
            self.add_at_first_node(title, author, year)
            return

        if pos == self.size + 1:  # If adding at the last position
            self.add_node(title, author, year)
            return

        new_book = Node(title, author, year)  # Create a new node

        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next

        new_book.next = cur.next
        cur.next = new_book

        self.size += 1

    def update_first_node(self, title, author, year):
        """
        Function to update the details of the first node in the linked list.
        
        :param title: New title of the book
        :param author: New author of the book
        :param year: New publication year of the book
        """
        if self.size == 0:
            print("List is empty!")
            return

        self.head.title = title
        self.head.author = author
        self.head.year = year

    def update_nth_node(self, title, author, year, pos):
        """
        Function to update the details of the nth node in the linked list.
        
        :param title: New title of the book
        :param author: New author of the book
        :param year: New publication year of the book
        :param pos: Position of the node to update
        """
        if pos < 1 or pos > self.size:  # Validate position
            print("Position out of range")
            return

        cur = self.head
        for _ in range(1, pos):
            cur = cur.next

        cur.title = title
        cur.author = author
        cur.year = year

    def update_last_node(self, title, author, year):
        """
        Function to update the details of the last node in the linked list.
        
        :param title: New title of the book
        :param author: New author of the book
        :param year: New publication year of the book
        """
        if self.size == 0:
            print("List is empty!")
            return

        self.tail.title = title
        self.tail.author = author
        self.tail.year = year

    def remove_at_first(self):
        """
        Function to remove the first node from the linked list.
        """
        if self.size == 0:
            return  # If the list is empty, do nothing

        self.head = self.head.next

        if self.size == 1:
            self.tail = None

        self.size -= 1

    def remove_at_nth_node(self, pos):
        """
        Function to remove the nth node from the linked list.
        
        :param pos: Position of the node to remove
        """
        if pos < 1 or pos > self.size:  # Validate position
            print("Position out of range")
            return

        if pos == 1:  # If removing the first node
            self.remove_at_first()
            return

        cur = self.head
        for _ in range(1, pos - 1):
            cur = cur.next

        cur.next = cur.next.next

        if pos == self.size:
            self.tail = cur

        self.size -= 1

    def remove_at_last(self):
        """
        Function to remove the last node from the linked list.
        """
        if self.size == 0:
            return  # If the list is empty, do nothing

        if self.size == 1:  # If there's only one node
            self.head = None
            self.tail = None
            self.size -= 1
            return

        cur = self.head
        while cur.next != self.tail:
            cur = cur.next

        cur.next = None
        self.tail = cur

        self.size -= 1

    def print_single_linked_list(self):
        """
        Function to print all nodes in the linked list.
        """
        print(f"Number of Nodes: {self.size}")  # Display the total number of nodes
        cur = self.head
        i = 1
        while cur is not None:
            print(f"NODE {i}")
            print(f"Title\t: {cur.title}")
            print(f"Author\t: {cur.author}")
            print(f"Year\t: {cur.year}\n")
            cur = cur.next
            i += 1

    def count_nodes(self):
        """
        Utility function to count the number of nodes in the linked list.
        
        :return: Total number of nodes
        """
        return self.size


if __name__ == "__main__":
    list = LinkedList()

    # Adding and printing nodes to demonstrate linked list operations
    list.add_node("Introduction to C", "Arief", "2022")
    list.print_single_linked_list()
    print("=========\n")

    list.add_at_first_node("Chemistry", "Wijaya", "2019")
    list.print_single_linked_list()
    print("=========\n")

    list.add_node("Physics", "Nisa", "2024")
    list.add_node("Introduction to Python", "Arief", "2023")
    list.add_at_nth_node("F1 For Child", "Anomali", "2000", 2)
    list.print_single_linked_list()
    print("=========\n")

    # Removing nodes and updating information to show dynamic modifications
    list.remove_at_first()
    list.print_single_linked_list()
    list.update_first_node("Introduction to C++", "Arief", "2022")
    print("=========\n")

    list.remove_at_last()
    list.print_single_linked_list()
    print("=========\n")

    list.remove_at_nth_node(2)
    list.print_single_linked_list()
    print("=========\n")

    list.add_node("Introduction to Kotlin", "Arief", "2023")
    list.update_nth_node("Math", "Nisa", "2024", 2)
    list.print_single_linked_list()
    print("=========\n")