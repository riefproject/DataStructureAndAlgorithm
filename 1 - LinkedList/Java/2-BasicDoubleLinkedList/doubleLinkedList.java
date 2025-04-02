public class doubleLinkedList {
    // Node class representing each element in the doubly linked list
    static class Node {
        String name; // Data title
        String username; // Author of the data
        String email; // Email of the user
        String password; // Password of the user
        Node prev; // Pointer to the previous node in the list
        Node next; // Pointer to the next node in the list

        // Constructor to initialize a new node
        Node(String name, String username, String email, String password) {
            this.name = name;
            this.username = username;
            this.email = email;
            this.password = password;
            this.prev = null;
            this.next = null;
        }
    }

    // LinkedList class to manage the doubly linked list
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

        // Function to create a doubly linked list with the first node
        void createDoubleLinkedList(String name, String username, String email, String password) {
            Node newNode = new Node(name, username, email, password);
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        void addAtFirstNode(String name, String username, String email, String password) {
            if (size == 0) {
                createDoubleLinkedList(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        void addAtNthNode(String name, String username, String email, String password, int pos) {
            if (pos < 1 || pos > size + 1) {
                System.out.println("Invalid position!");
                return;
            }
            if (pos == 1) {
                addAtFirstNode(name, username, email, password);
                return;
            }
            if (pos == size + 1) {
                addAtLastNode(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
            Node cur = head;
            for (int i = 1; i < pos - 1; i++) {
                cur = cur.next;
            }
            newNode.next = cur.next;
            newNode.prev = cur;
            cur.next.prev = newNode;
            cur.next = newNode;
            size++;
        }

        // Function to add a node at the end of the list
        void addAtLastNode(String name, String username, String email, String password) {
            if (size == 0) {
                createDoubleLinkedList(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        void updateFirstNode(String name, String username, String email, String password) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            head.name = name;
            head.username = username;
            head.email = email;
            head.password = password;
        }

        // Function to update the nth node in the list
        void updateNthNode(String name, String username, String email, String password, int pos) {
            if (pos < 1 || pos > size) {
                System.out.println("Invalid position!");
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++) {
                cur = cur.next;
            }
            cur.name = name;
            cur.username = username;
            cur.email = email;
            cur.password = password;
        }

        // Function to update the last node in the list
        void updateLastNode(String name, String username, String email, String password) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            tail.name = name;
            tail.username = username;
            tail.email = email;
            tail.password = password;
        }

        // Function to remove the first node from the list
        void removeAtFirst() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                head = head.next;
                head.prev = null;
            }
            size--;
        }

        // Function to remove the nth node from the list
        void removeAtNthNode(int pos) {
            if (pos < 1 || pos > size) {
                System.out.println("Invalid position!");
                return;
            }
            if (pos == 1) {
                removeAtFirst();
                return;
            }
            if (pos == size) {
                removeAtLast();
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++) {
                cur = cur.next;
            }
            cur.prev.next = cur.next;
            cur.next.prev = cur.prev;
            size--;
        }

        // Function to remove the last node from the list
        void removeAtLast() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                tail = tail.prev;
                tail.next = null;
            }
            size--;
        }

        // Function to print the doubly linked list
        void printDoubleLinkedList() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            System.out.println("Number of Nodes: " + countNodes()); // Display the total number of nodes
            Node cur = head;
            int i = 1;
            while (cur != null) {
                System.out.println("Node " + i);
                System.out.println("Name\t\t: " + cur.name);
                System.out.println("Username\t: " + cur.username);
                System.out.println("Email\t\t: " + cur.email);
                System.out.println("Password\t: " + cur.password + "\n");
                cur = cur.next;
                i++;
            }
        }

        // Utility function to count the number of nodes in the list
        int countNodes() {
            return size; // Return the total number of nodes
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Create the doubly linked list with the first node
        list.createDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Add a node at the end of the list
        list.addAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Add a node at the beginning of the list
        list.addAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Remove the first node from the list
        list.removeAtFirst();
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Remove the last node from the list
        list.removeAtLast();
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Add multiple nodes at the beginning of the list
        list.addAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
        list.addAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
        list.addAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
        list.addAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
        list.addAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Add a node at the nth position in the list
        list.addAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");

        // Remove the nth node from the list
        list.removeAtNthNode(6);
        list.printDoubleLinkedList();
        System.out.println("==========\n\n\n");
    }
}