public class circularDoubleLinkedList {
    // Node class representing each element in the circular doubly linked list
    static class Node {
        String name; // Item name
        int price; // Item price
        int available; // Item availability
        Node prev; // Pointer to the previous node in the list
        Node next; // Pointer to the next node in the list

        // Constructor to initialize a new node
        Node(String name, int price, int available) {
            this.name = name;
            this.price = price;
            this.available = available;
            this.prev = null;
            this.next = null;
        }
    }

    // LinkedList class to manage the circular doubly linked list
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

        // Function to create a circular doubly linked list with the first node
        void createCircularDL(String name, int price, int available) {
            Node newNode = new Node(name, price, available);
            newNode.next = newNode;
            newNode.prev = newNode;
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        void addAtFirstNode(String name, int price, int available) {
            if (size == 0) {
                createCircularDL(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
            newNode.next = head;
            newNode.prev = tail;
            head.prev = newNode;
            tail.next = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        void addAtNthNode(String name, int price, int available, int pos) {
            if (pos < 1 || pos > size + 1) {
                System.out.println("Invalid position!");
                return;
            }
            if (pos == 1) {
                addAtFirstNode(name, price, available);
                return;
            }
            if (pos == size + 1) {
                addAtLastNode(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
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
        void addAtLastNode(String name, int price, int available) {
            if (size == 0) {
                createCircularDL(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
            newNode.next = head;
            newNode.prev = tail;
            tail.next = newNode;
            head.prev = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        void updateFirstNode(String name, int price, int available) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            head.name = name;
            head.price = price;
            head.available = available;
        }

        // Function to update the nth node in the list
        void updateNthNode(String name, int price, int available, int pos) {
            if (pos < 1 || pos > size) {
                System.out.println("Invalid position!");
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++) {
                cur = cur.next;
            }
            cur.name = name;
            cur.price = price;
            cur.available = available;
        }

        // Function to update the last node in the list
        void updateLastNode(String name, int price, int available) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            tail.name = name;
            tail.price = price;
            tail.available = available;
        }

        // Function to remove the first node from the list
        void removeFirstNode() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                head = head.next;
                head.prev = tail;
                tail.next = head;
            }
            size--;
        }

        // Function to remove the nth node from the list
        void removeNthNode(int pos) {
            if (pos < 1 || pos > size) {
                System.out.println("Invalid position!");
                return;
            }
            if (pos == 1) {
                removeFirstNode();
                return;
            }
            if (pos == size) {
                removeLastNode();
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
        void removeLastNode() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            if (size == 1) {
                head = null;
                tail = null;
            } else {
                tail = tail.prev;
                tail.next = head;
                head.prev = tail;
            }
            size--;
        }

        // Function to print the circular doubly linked list
        void printCircularDL() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            Node cur = head;
            for (int i = 0; i < size; i++) {
                System.out.printf("Name: %s\nPrice: %d\nAvailable: %d\n", cur.name, cur.price, cur.available);
                cur = cur.next;
            }
        }

        // Utility function to count the number of nodes in the list
        int countNodes() {
            return size; // Return the total number of nodes
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Create the circular doubly linked list with the first node
        list.createCircularDL("Laptop", 20000000, 20);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Add a node at the beginning of the list
        list.addAtFirstNode("Handphone", 5000000, 50);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Add nodes at the end of the list
        list.addAtLastNode("Mouse", 1200000, 100);
        list.addAtLastNode("Keyboard", 2250000, 100);
        list.addAtLastNode("Headphone", 1800000, 100);
        list.addAtLastNode("Monitor", 4200000, 100);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Remove the first node from the list
        list.removeFirstNode();
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Remove the last node from the list
        list.removeLastNode();
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Add a node at the nth position in the list
        list.addAtNthNode("RTX 5090", 40000000, 15, 3);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Remove the nth node from the list
        list.removeNthNode(4);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Update the first node in the list
        list.updateFirstNode("Laptop", 19000000, 10);
        // Update the nth node in the list
        list.updateNthNode("Mouse", 1000000, 3, 2);
        // Update the last node in the list
        list.updateLastNode("Headphone", 1900000, 5);
        list.printCircularDL();
        System.out.println("==========\n\n\n");

        // Print the total number of nodes in the list
        System.out.printf("Total nodes: %d\n", list.countNodes());
    }
}