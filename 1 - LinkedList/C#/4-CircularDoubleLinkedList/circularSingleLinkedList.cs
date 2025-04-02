using System;

namespace CircularDoubleLinkedList
{
    // Node class representing each element in the circular doubly linked list
    public class Node
    {
        public string Name { get; set; }     // Item name
        public int Price { get; set; }       // Item price
        public int Available { get; set; }   // Item availability
        public Node Prev { get; set; }       // Pointer to the previous node in the list
        public Node Next { get; set; }       // Pointer to the next node in the list

        // Constructor to initialize a new node
        public Node(string name, int price, int available)
        {
            Name = name;
            Price = price;
            Available = available;
            Prev = null;
            Next = null;
        }
    }

    // LinkedList class to manage the circular doubly linked list
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

        // Function to create a circular doubly linked list with the first node
        public void CreateCircularDL(string name, int price, int available)
        {
            Node newNode = new Node(name, price, available);
            newNode.Next = newNode;
            newNode.Prev = newNode;
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        public void AddAtFirstNode(string name, int price, int available)
        {
            if (size == 0)
            {
                CreateCircularDL(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
            newNode.Next = head;
            newNode.Prev = tail;
            head.Prev = newNode;
            tail.Next = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        public void AddAtNthNode(string name, int price, int available, int pos)
        {
            if (pos < 1 || pos > size + 1)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            if (pos == 1)
            {
                AddAtFirstNode(name, price, available);
                return;
            }
            if (pos == size + 1)
            {
                AddAtLastNode(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
            Node cur = head;
            for (int i = 1; i < pos - 1; i++)
            {
                cur = cur.Next;
            }
            newNode.Next = cur.Next;
            newNode.Prev = cur;
            cur.Next.Prev = newNode;
            cur.Next = newNode;
            size++;
        }

        // Function to add a node at the end of the list
        public void AddAtLastNode(string name, int price, int available)
        {
            if (size == 0)
            {
                CreateCircularDL(name, price, available);
                return;
            }
            Node newNode = new Node(name, price, available);
            newNode.Next = head;
            newNode.Prev = tail;
            tail.Next = newNode;
            head.Prev = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        public void UpdateFirstNode(string name, int price, int available)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            head.Name = name;
            head.Price = price;
            head.Available = available;
        }

        // Function to update the nth node in the list
        public void UpdateNthNode(string name, int price, int available, int pos)
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
            cur.Name = name;
            cur.Price = price;
            cur.Available = available;
        }

        // Function to update the last node in the list
        public void UpdateLastNode(string name, int price, int available)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            tail.Name = name;
            tail.Price = price;
            tail.Available = available;
        }

        // Function to remove the first node from the list
        public void RemoveFirstNode()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Node temp = head;
            if (size == 1)
            {
                head = null;
                tail = null;
            }
            else
            {
                head = head.Next;
                head.Prev = tail;
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
            if (pos == size)
            {
                RemoveLastNode();
                return;
            }
            Node cur = head;
            for (int i = 1; i < pos; i++)
            {
                cur = cur.Next;
            }
            cur.Prev.Next = cur.Next;
            cur.Next.Prev = cur.Prev;
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
            Node temp = tail;
            if (size == 1)
            {
                head = null;
                tail = null;
            }
            else
            {
                tail = tail.Prev;
                tail.Next = head;
                head.Prev = tail;
            }
            size--;
        }

        // Function to print the circular doubly linked list
        public void PrintCircularDL()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Node cur = head;
            do
            {
                Console.WriteLine($"Name: {cur.Name}, Price: {cur.Price}, Available: {cur.Available}");
                cur = cur.Next;
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

            // Create the circular doubly linked list with the first node
            list.CreateCircularDL("Laptop", 20000000, 20);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the beginning of the list
            list.AddAtFirstNode("Handphone", 5000000, 50);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Add nodes at the end of the list
            list.AddAtLastNode("Mouse", 1200000, 100);
            list.AddAtLastNode("Keyboard", 2250000, 100);
            list.AddAtLastNode("Headphone", 1800000, 100);
            list.AddAtLastNode("Monitor", 4200000, 100);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Remove the first node from the list
            list.RemoveFirstNode();
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Remove the last node from the list
            list.RemoveLastNode();
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the nth position in the list
            list.AddAtNthNode("RTX 5090", 40000000, 15, 3);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Remove the nth node from the list
            list.RemoveNthNode(4);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Update the first node in the list
            list.UpdateFirstNode("Laptop", 19000000, 10);
            // Update the nth node in the list
            list.UpdateNthNode("Mouse", 1000000, 3, 2);
            // Update the last node in the list
            list.UpdateLastNode("Headphone", 1900000, 5);
            list.PrintCircularDL();
            Console.WriteLine("==========\n\n\n");

            // Print the total number of nodes in the list
            Console.WriteLine("Total nodes: " + list.CountNodes());
        }
    }
}