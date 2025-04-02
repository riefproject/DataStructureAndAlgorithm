public class circularSingleLinkedList {
    // Node class representing each element in the circular singly linked list
    static class Node {
        String id; // Student ID
        String name; // Student name
        String major; // Student major
        Node next; // Pointer to the next node in the list

        // Constructor to initialize a new node
        Node(String id, String name, String major) {
            this.id = id;
            this.name = name;
            this.major = major;
            this.next = null;
        }
    }

    // LinkedList class to manage the circular singly linked list
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

        // Function to create a circular singly linked list with the first node
        void createCircularSL(String id, String name, String major) {
            Node newNode = new Node(id, name, major);
            newNode.next = newNode;
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        void addAtFirstNode(String id, String name, String major) {
            if (size == 0) {
                createCircularSL(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            newNode.next = head;
            tail.next = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        void addAtNthNode(String id, String name, String major, int pos) {
            if (pos < 1 || pos > size + 1) {
                System.out.println("Invalid position!");
                return;
            }
            if (pos == 1) {
                addAtFirstNode(id, name, major);
                return;
            }
            if (pos == size + 1) {
                addAtLastNode(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            Node cur = head;
            for (int i = 1; i < pos - 1; i++) {
                cur = cur.next;
            }
            newNode.next = cur.next;
            cur.next = newNode;
            size++;
        }

        // Function to add a node at the end of the list
        void addAtLastNode(String id, String name, String major) {
            if (size == 0) {
                createCircularSL(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            newNode.next = head;
            tail.next = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        void updateFirstNode(String id, String name, String major) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            head.id = id;
            head.name = name;
            head.major = major;
        }

        // Function to update the nth node in the list
        void updateNthNode(String id, String name, String major, int pos) {
            if (pos < 1 || pos > size) {
                System.out.println("Invalid position!");
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++) {
                cur = cur.next;
            }
            cur.id = id;
            cur.name = name;
            cur.major = major;
        }

        // Function to update the last node in the list
        void updateLastNode(String id, String name, String major) {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            tail.id = id;
            tail.name = name;
            tail.major = major;
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
            Node cur = head;
            for (int i = 1; i < pos - 1; i++) {
                cur = cur.next;
            }
            cur.next = cur.next.next;
            if (pos == size) {
                tail = cur;
            }
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
                Node cur = head;
                while (cur.next != tail) {
                    cur = cur.next;
                }
                tail = cur;
                tail.next = head;
            }
            size--;
        }

        // Function to print the circular singly linked list
        void printCircularSL() {
            if (size == 0) {
                System.out.println("List is empty!");
                return;
            }
            System.out.println("Number of Nodes: " + countNodes()); // Display the total number of nodes
            Node cur = head;
            int i = 1;
            do {
                System.out.println("Node " + i);
                System.out.println("ID\t\t: " + cur.id);
                System.out.println("Name\t\t: " + cur.name);
                System.out.println("Major\t\t: " + cur.major + "\n");
                cur = cur.next;
                i++;
            } while (cur != head);
        }

        // Utility function to count the number of nodes in the list
        int countNodes() {
            return size; // Return the total number of nodes
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        // Create the circular singly linked list with the first node
        list.createCircularSL("11223399", "Arief F-sa", "Computer Science");
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Add a node at the beginning of the list
        list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Add a node at the end of the list
        list.addAtLastNode("11223400", "Pejeel", "Drop out");
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Remove the first node from the list
        list.removeFirstNode();
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Remove the last node from the list
        list.removeLastNode();
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Add nodes at the beginning and end of the list
        list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
        list.addAtLastNode("11223400", "Pejeel", "Drop out");
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Add nodes at specific positions in the list
        list.addAtNthNode("11223401", "dummy1", "Math", 3);
        list.addAtNthNode("11223402", "dummy2", "Physics", 2);
        list.printCircularSL();
        System.out.println("==========\n\n\n");

        // Remove the node at the specified position in the list
        list.removeNthNode(2);
        list.printCircularSL();
        System.out.println("==========\n\n\n");
    }
}