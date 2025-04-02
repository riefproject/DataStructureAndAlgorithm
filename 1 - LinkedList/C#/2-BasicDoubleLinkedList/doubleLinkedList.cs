using System;

namespace DoubleLinkedList
{
    // Node class representing each element in the doubly linked list
    public class Node
    {
        public string Name { get; set; }     // Data title
        public string Username { get; set; } // Author of the data
        public string Email { get; set; }    // Author of the data
        public string Password { get; set; } // Publication year of the data
        public Node Prev { get; set; }       // Pointer to the previous data in the list
        public Node Next { get; set; }       // Pointer to the next data in the list

        // Constructor to initialize a new node
        public Node(string name, string username, string email, string password)
        {
            Name = name;
            Username = username;
            Email = email;
            Password = password;
            Prev = null;
            Next = null;
        }
    }

    // LinkedList class to manage the doubly linked list
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

        // Function to create a doubly linked list with the first node
        public void CreateDoubleLinkedList(string name, string username, string email, string password)
        {
            Node newNode = new Node(name, username, email, password);
            head = newNode;
            tail = newNode;
            size = 1;
        }

        // Function to add a node at the beginning of the list
        public void AddAtFirstNode(string name, string username, string email, string password)
        {
            if (size == 0)
            {
                CreateDoubleLinkedList(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
            newNode.Next = head;
            head.Prev = newNode;
            head = newNode;
            size++;
        }

        // Function to add a node at the nth position in the list
        public void AddAtNthNode(string name, string username, string email, string password, int pos)
        {
            if (pos < 1 || pos > size + 1)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            if (pos == 1)
            {
                AddAtFirstNode(name, username, email, password);
                return;
            }
            if (pos == size + 1)
            {
                AddAtLastNode(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
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
        public void AddAtLastNode(string name, string username, string email, string password)
        {
            if (size == 0)
            {
                CreateDoubleLinkedList(name, username, email, password);
                return;
            }
            Node newNode = new Node(name, username, email, password);
            newNode.Prev = tail;
            tail.Next = newNode;
            tail = newNode;
            size++;
        }

        // Function to update the first node in the list
        public void UpdateFirstNode(string name, string username, string email, string password)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            head.Name = name;
            head.Username = username;
            head.Email = email;
            head.Password = password;
        }

        // Function to update the nth node in the list
        public void UpdateNthNode(string name, string username, string email, string password, int pos)
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
            cur.Username = username;
            cur.Email = email;
            cur.Password = password;
        }

        // Function to update the last node in the list
        public void UpdateLastNode(string name, string username, string email, string password)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            tail.Name = name;
            tail.Username = username;
            tail.Email = email;
            tail.Password = password;
        }

        // Function to remove the first node from the list
        public void RemoveAtFirst()
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
                head.Prev = null;
            }
            size--;
        }

        // Function to remove the nth node from the list
        public void RemoveAtNthNode(int pos)
        {
            if (pos < 1 || pos > size)
            {
                Console.WriteLine("Invalid position!");
                return;
            }
            if (pos == 1)
            {
                RemoveAtFirst();
                return;
            }
            if (pos == size)
            {
                RemoveAtLast();
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
        public void RemoveAtLast()
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
                tail = tail.Prev;
                tail.Next = null;
            }
            size--;
        }

        // Function to print the doubly linked list
        public void PrintDoubleLinkedList()
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }
            Console.WriteLine("Number of Nodes: " + size); // Display the total number of nodes

            Node cur = head;
            int i = 1;
            while (cur != null)
            {
                Console.WriteLine("Node " + i);
                Console.WriteLine("Name\t\t: " + cur.Name);
                Console.WriteLine("Username\t: " + cur.Username);
                Console.WriteLine("Email\t\t: " + cur.Email);
                Console.WriteLine("Password\t: " + cur.Password);
                Console.WriteLine();
                cur = cur.Next;
                i++;
            }
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

            // Create the doubly linked list with the first node
            list.CreateDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the end of the list
            list.AddAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the beginning of the list
            list.AddAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Remove the first node from the list
            list.RemoveAtFirst();
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Remove the last node from the list
            list.RemoveAtLast();
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Add multiple nodes at the beginning of the list
            list.AddAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
            list.AddAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
            list.AddAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
            list.AddAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
            list.AddAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Add a node at the nth position in the list
            list.AddAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");

            // Remove the nth node from the list
            list.RemoveAtNthNode(6);
            list.PrintDoubleLinkedList();
            Console.WriteLine("==========\n\n\n");
        }
    }
}