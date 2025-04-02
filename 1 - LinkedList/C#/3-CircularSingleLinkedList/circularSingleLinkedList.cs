using System;

namespace CircularSingleLinkedList
{
    // Node class representing each element in the circular singly linked list
    public class Node
    {
        public string Id { get; set; }    // Student ID
        public string Name { get; set; }  // Student name
        public string Major { get; set; } // Student major
        public Node Next { get; set; }    // Pointer to the next node in the list

        // Constructor to initialize a new node
        public Node(string id, string name, string major)
        {
            Id = id;
            Name = name;
            Major = major;
            Next = null;
        }
    }

    // LinkedList class to manage the circular singly linked list
    public class LinkedList
    {
        private Node head; // Pointer to the head of the list
        private Node tail; // Pointer to the tail of the list
        private int size;  // Size of the list

        // Constructor to initialize an empty list
        public LinkedList()
        {
            head = null;
            tail = null;
            size = 0;
        }

        // Function to create a circular singly linked list with the first node
        public void CreateCircularSL(string id, string name, string major)
        {
            Node newNode = new Node(id, name, major);
            newNode.Next = newNode;
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        public void AddAtFirstNode(string id, string name, string major)
        {
            if (size == 0)
            {
                CreateCircularSL(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            newNode.Next = head;
            tail.Next = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        public void AddAtNthNode(string id, string name, string major, int pos)
        {
            if (pos < 1 || pos > size + 1)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            if (pos == 1)
            {
                AddAtFirstNode(id, name, major);
                return;
            }
            if (pos == size + 1)
            {
                AddAtLastNode(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            Node cur = head;
            for (int i = 1; i < pos - 1; i++)
            {
                cur = cur.Next;
            }
            newNode.Next = cur.Next;
            cur.Next = newNode;
            size++;
        }

        // Function to add a node at the end of the list
        public void AddAtLastNode(string id, string name, string major)
        {
            if (size == 0)
            {
                CreateCircularSL(id, name, major);
                return;
            }
            Node newNode = new Node(id, name, major);
            newNode.Next = head;
            tail.Next = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        public void UpdateFirstNode(string id, string name, string major)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            head.Id = id;
            head.Name = name;
            head.Major = major;
        }

        // Function to update the nth node in the list
        public void UpdateNthNode(string id, string name, string major, int pos)
        {
            if (pos < 1 || pos > size)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++)
            {
                cur = cur.Next;
            }
            cur.Id = id;
            cur.Name = name;
            cur.Major = major;
        }

        // Function to update the last node in the list
        public void UpdateLastNode(string id, string name, string major)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            tail.Id = id;
            tail.Name = name;
            tail.Major = major;
        }

        // Function to remove the first node from the list
        public void RemoveFirstNode()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Node del = head;
            if (size == 1)
            {
                head = null;
                tail = null;
            }
            else
            {
                head = head.Next;
                tail.Next = head;
            }
            size--;
        }

        // Function to remove the nth node from the list
        public void RemoveNthNode(int pos)
        {
            if (pos < 1 || pos > size)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            if (pos == 1)
            {
                RemoveFirstNode();
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos - 1; i++)
            {
                cur = cur.Next;
            }
            Node del = cur.Next;
            cur.Next = del.Next;
            if (del == tail)
            {
                tail = cur;
            }
            size--;
        }

        // Function to remove the last node from the list
        public void RemoveLastNode()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Node del = tail;
            if (size == 1)
            {
                head = null;
                tail = null;
            }
            else
            {
                Node cur = head;
                while (cur.Next != tail)
                {
                    cur = cur.Next;
                }
                tail = cur;
                tail.Next = head;
            }
            size--;
        }

        // Function to print the circular singly linked list
        public void PrintCircularSL()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Console.WriteLine("Number of Nodes: " + size); // Display the total number of nodes

            Node cur = head;
            int i = 1;
            do
            {
                Console.WriteLine("Node " + i);
                Console.WriteLine("ID\t\t: " + cur.Id);
                Console.WriteLine("Name\t\t: " + cur.Name);
                Console.WriteLine("Major\t\t: " + cur.Major);
                Console.WriteLine();
                cur = cur.Next;
                i++;
            } while (cur != head);
        }

        // Utility function to count the number of nodes in the list
        public int CountNodes()
        {
            return size; // Return the total number of nodes
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LinkedList list = new LinkedList();

            // Create the circular singly linked list with the first node
            list.CreateCircularSL("11223399", "Arief F-sa", "Computer Science");
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the beginning of the list
            list.AddAtFirstNode("11223398", "Nisa Uswa", "Psychology");
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the end of the list
            list.AddAtLastNode("11223400", "Pejeel", "Drop out");
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Remove the first node from the list
            list.RemoveFirstNode();
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Remove the last node from the list
            list.RemoveLastNode();
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Add nodes at the beginning and end of the list
            list.AddAtFirstNode("11223398", "Nisa Uswa", "Psychology");
            list.AddAtLastNode("11223400", "Pejeel", "Drop out");
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Add nodes at specific positions in the list
            list.AddAtNthNode("11223401", "dummy1", "Math", 3);
            list.AddAtNthNode("11223402", "dummy2", "Physics", 2);
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");

            // Remove the node at the specified position in the list
            list.RemoveNthNode(2);
            list.PrintCircularSL();
            Console.WriteLine("==========\n\n\n");
        }
    }
}