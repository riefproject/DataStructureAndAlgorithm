public class singleLinkedList {
    // Node class representing each element in the singly linked list
    static class Node {
        String title; // Book title
        String author; // Author of the book
        String year; // Publication year of the book
        Node next; // Pointer to the next book in the list

        // Constructor to initialize a new node
        Node(String title, String author, String year) {
            this.title = title;
            this.author = author;
            this.year = year;
            this.next = null;
        }
    }

    // LinkedList class to manage the singly linked list
    static class LinkedList {
        private Node head; // Pointer to the head of the list
        private Node tail; // Pointer to the tail of the list
        private int size; // Size of the list

        // Constructor to initialize an empty list
        LinkedList() {
            this.head = null;
            this.tail = null;
            this.size = 0;
        }

        // Function to add a node at the end of the linked list
        void addNode(String title, String author, String year) {
            Node newBook = new Node(title, author, year); // Create a new node

            if (head == null) { // If the list is empty
                head = newBook;
                tail = newBook;
            } else {
                tail.next = newBook;
                tail = newBook;
            }

            size++;
        }

        // Function to add a node at the beginning of the linked list
        void addAtFirstNode(String title, String author, String year) {
            Node newBook = new Node(title, author, year); // Create a new node

            newBook.next = head;
            head = newBook;

            if (size == 0) {
                tail = newBook;
            }

            size++;
        }

        // Function to add a node at a specified position in the linked list
        void addAtNthNode(String title, String author, String year, int pos) {
            if (pos < 1 || pos > size + 1) { // Validate position
                System.out.println("Position out of range");
                return;
            }
            if (pos == 1) { // If adding at the first position
                addAtFirstNode(title, author, year);
                return;
            }
            if (pos == size + 1) { // If adding at the last position
                addNode(title, author, year);
                return;
            }

            Node newBook = new Node(title, author, year); // Create a new node

            // Find the position before where the new book will be inserted
            Node cur = head;
            for (int i = 1; i < pos - 1; i++) {
                cur = cur.next;
            }

            // Insert the new book into the linked list at the specified position
            newBook.next = cur.next;
            cur.next = newBook;

            size++;
        }

        // Function to update the details of the first node in the linked list
        void updateFirstNode(String title, String author, String year) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }

            // Update book details
            head.title = title;
            head.author = author;
            head.year = year;
        }

        // Function to update the details of the nth node in the linked list
        void updateNthNode(String title, String author, String year, int pos) {
            if (pos < 1 || pos > size) { // Validate position
                System.out.println("Position out of range");
                return;
            }
            if (pos == 1) { // If updating the first node
                updateFirstNode(title, author, year);
                return;
            }
            if (pos == size) { // If updating the last node
                updateLastNode(title, author, year);
                return;
            }

            // Normal update at the nth position
            Node cur = head;
            for (int i = 1; i < pos; i++) { // Traverse to the nth node
                cur = cur.next;
            }

            // Update book details
            cur.title = title;
            cur.author = author;
            cur.year = year;
        }

        // Function to update the details of the last node in the linked list
        void updateLastNode(String title, String author, String year) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }

            // Update book details
            tail.title = title;
            tail.author = author;
            tail.year = year;
        }

        // Function to remove the first node from the linked list
        void removeAtFirst() {
            if (size == 0) {
                return; // If the list is empty, do nothing
            }

            head = head.next; // Update the head pointer to the next node

            if (size == 1) {
                tail = null;
            }

            size--;
        }

        // Function to remove the nth node from the linked list
        void removeAtNthNode(int pos) {
            if (pos < 1 || pos > size) { // Validate position
                System.out.println("Position out of range");
                return;
            }
            if (pos == 1) { // If removing the first node
                removeAtFirst();
                return;
            }
            if (pos == size) { // If removing the last node
                removeAtLast();
                return;
            }

            // Normal removal of the nth node
            Node cur = head;
            Node before = null;
            for (int i = 1; i < pos; ++i) {
                before = cur; // Keep track of the node before the one to be deleted
                cur = cur.next; // Move to the next node
            }

            before.next = cur.next; // Bypass the node to be deleted

            size--;
        }

        // Function to remove the last node from the linked list
        void removeAtLast() {
            if (size == 0) {
                return; // If the list is empty, do nothing
            }

            if (size == 1) { // If there's only one node
                head = null;
                tail = null;
                size--;
                return;
            }

            // Find the second last node
            Node cur = head;
            while (cur.next != tail) {
                cur = cur.next;
            }

            tail = cur; // Update the tail pointer
            tail.next = null; // Set the next pointer of the new tail to null

            size--;
        }

        // Function to print all nodes in the linked list
        void printSingleLinkedList() {
            System.out.println("Number of Nodes: " + countNodes()); // Display the total number of nodes
            Node cur = head;
            int i = 1;
            while (cur != null) {
                System.out.println("NODE " + i); // Print node number
                System.out.println("Title\t: " + cur.title); // Print the title of the book
                System.out.println("Author\t: " + cur.author); // Print the author of the book
                System.out.println("Year\t: " + cur.year + "\n"); // Print the publication year of the book
                cur = cur.next; // Move to the next node
                i++;
            }
        }

        // Utility function to count the number of nodes in the linked list
        int countNodes() {
            return size; // Return the total number of nodes
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Adding and printing nodes to demonstrate linked list operations
        list.addNode("Introduction to C", "Arief", "2022");
        list.printSingleLinkedList();
        System.out.println("=========\n");

        list.addAtFirstNode("Chemistry", "Wijaya", "2019");
        list.printSingleLinkedList();
        System.out.println("=========\n");

        list.addNode("Physics", "Nisa", "2024");
        list.addNode("Introduction to Python", "Arief", "2023");
        list.addAtNthNode("F1 For Child", "Anomali", "2000", 2);
        list.printSingleLinkedList();
        System.out.println("=========\n");

        // Removing nodes and updating information to show dynamic modifications
        list.removeAtFirst();
        list.printSingleLinkedList();
        list.updateFirstNode("Introduction to C++", "Arief", "2022");
        System.out.println("=========\n");

        list.removeAtLast();
        list.printSingleLinkedList();
        System.out.println("=========\n");

        list.removeAtNthNode(2);
        list.printSingleLinkedList();
        System.out.println("=========\n");

        list.addNode("Introduction to Kotlin", "Arief", "2023");
        list.updateNthNode("Math", "Nisa", "2024", 2);
        list.printSingleLinkedList();
        System.out.println("=========\n");
    }
}