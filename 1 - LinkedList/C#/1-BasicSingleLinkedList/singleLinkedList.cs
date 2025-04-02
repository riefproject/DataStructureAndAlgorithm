using System;

namespace SingleLinkedList
{
    // Node class representing each element in the singly linked list
    public class Node
    {
        public string Title { get; set; }  // Book title
        public string Author { get; set; } // Author of the book
        public string Year { get; set; }   // Publication year of the book
        public Node Next { get; set; }     // Pointer to the next book in the list

        // Constructor to initialize a new node
        public Node(string title, string author, string year)
        {
            Title = title;
            Author = author;
            Year = year;
            Next = null;
        }
    }

    // LinkedList class to manage the singly linked list
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

        // Function to add a node at the beginning of the linked list
        public void AddAtFirstNode(string title, string author, string year)
        {
            Node newBook = new Node(title, author, year); // Create a new node

            // Insert the new book at the beginning of the linked list
            newBook.Next = head;
            head = newBook;

            if (size == 0)
            {
                tail = newBook;
            }

            size++;
        }

        // Function to add a node at a specified position in the linked list
        public void AddAtNthNode(string title, string author, string year, int pos)
        {
            if (pos < 1 || pos > size + 1) // Validate position
            {
                Console.WriteLine("Position out of range");
                return;
            }
            if (pos == 1) // If adding at the first position
            {
                AddAtFirstNode(title, author, year);
                return;
            }
            if (pos == size + 1) // If adding at the last position
            {
                AddNode(title, author, year);
                return;
            }

            // Normal insertion at the nth position
            Node newBook = new Node(title, author, year); // Create a new node

            // Find the position before where the new book will be inserted
            Node cur = head;
            for (int i = 1; i < pos - 1; i++)
            {
                cur = cur.Next;
            }

            // Insert the new book into the linked list at the specified position
            newBook.Next = cur.Next;
            cur.Next = newBook;

            size++;
        }

        // Function to add a node at the end of the linked list
        public void AddNode(string title, string author, string year)
        {
            Node newBook = new Node(title, author, year); // Create a new node

            // Insert the new book at the end of the linked list
            if (head == null) // If the list is empty
            {
                head = newBook;
                tail = newBook;
            }
            else
            {
                tail.Next = newBook;
                tail = newBook;
            }

            size++;
        }

        // Function to update the details of the first node in the linked list
        public void UpdateFirstNode(string title, string author, string year)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }

            // Update book details
            head.Title = title;
            head.Author = author;
            head.Year = year;
        }

        // Function to update the details of the nth node in the linked list
        public void UpdateNthNode(string title, string author, string year, int pos)
        {
            if (pos < 1 || pos > size) // Validate position
            {
                Console.WriteLine("Position out of range");
                return;
            }
            if (pos == 1) // If updating the first node
            {
                UpdateFirstNode(title, author, year);
                return;
            }
            if (pos == size) // If updating the last node
            {
                UpdateLastNode(title, author, year);
                return;
            }

            // Normal update at the nth position
            Node cur = head;
            for (int i = 1; i < pos; i++) // Traverse to the nth node
            {
                cur = cur.Next;
            }

            // Update book details
            cur.Title = title;
            cur.Author = author;
            cur.Year = year;
        }

        // Function to update the details of the last node in the linked list
        public void UpdateLastNode(string title, string author, string year)
        {
            if (size == 0)
            {
                Console.WriteLine("List is empty!");
                return;
            }

            // Update book details
            tail.Title = title;
            tail.Author = author;
            tail.Year = year;
        }

        // Function to remove the first node from the linked list
        public void RemoveAtFirst()
        {
            if (size == 0)
                return; // If the list is empty, do nothing

            Node del = head;        // Point to the node to be deleted
            head = head.Next;       // Update the head pointer to the next node

            if (size == 1)
            {
                tail = null;
            }

            size--;
        }

        // Function to remove the nth node from the linked list
        public void RemoveAtNthNode(int pos)
        {
            if (pos < 1 || pos > size) // Validate position
            {
                Console.WriteLine("Position out of range");
                return;
            }
            if (pos == 1) // If removing the first node
            {
                RemoveAtFirst();
                return;
            }
            if (pos == size) // If removing the last node
            {
                RemoveAtLast();
                return;
            }

            // Normal removal of the nth node
            Node cur = head;
            Node before = null;
            for (int i = 1; i < pos; ++i)
            {
                before = cur;    // Keep track of the node before the one to be deleted
                cur = cur.Next;  // Move to the next node
            }

            before.Next = cur.Next; // Bypass the node to be deleted

            size--;
        }

        // Function to remove the last node from the linked list
        public void RemoveAtLast()
        {
            if (size == 0)
                return; // If the list is empty, do nothing

            if (size == 1) // If there's only one node
            {
                head = tail = null; // Set both head and tail to null
                size--;
                return;
            }

            // Find the second last node
            Node cur = head;
            while (cur.Next != tail)
            {
                cur = cur.Next;
            }

            tail = cur;              // Update the tail pointer
            tail.Next = null;        // Set the next pointer of the new tail to null

            size--;
        }

        // Function to print all nodes in the linked list
        public void PrintSingleLinkedList()
        {
            Console.WriteLine("Number of Nodes: " + size); // Display the total number of nodes
            Node cur = head;
            int i = 1;
            while (cur != null)
            {
                Console.WriteLine("NODE " + i);                // Print node number
                Console.WriteLine("Title\t: " + cur.Title);    // Print the title of the book
                Console.WriteLine("Author\t: " + cur.Author);  // Print the author of the book
                Console.WriteLine("Year\t: " + cur.Year);      // Print the publication year of the book
                Console.WriteLine();                           // Print a blank line
                cur = cur.Next;                                // Move to the next node
                i++;
            }
        }

        // Utility function to count the number of nodes in the linked list
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

            // Adding and printing nodes to demonstrate linked list operations
            list.AddNode("Introduction to C", "Arief", "2022");
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");

            list.AddAtFirstNode("Chemistry", "Wijaya", "2019");
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");

            list.AddNode("Physics", "Nisa", "2024");
            list.AddNode("Introduction to Python", "Arief", "2023");
            list.AddAtNthNode("F1 For Child", "Anomali", "2000", 2);
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");

            // Removing nodes and updating information to show dynamic modifications
            list.RemoveAtFirst();
            list.PrintSingleLinkedList();
            list.UpdateFirstNode("Introduction to C++", "Arief", "2022");
            Console.WriteLine("=========\n");

            list.RemoveAtLast();
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");

            list.RemoveAtNthNode(2);
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");

            list.AddNode("Introduction to Kotlin", "Arief", "2023");
            list.UpdateNthNode("Math", "Nisa", "2024", 2);
            list.PrintSingleLinkedList();
            Console.WriteLine("=========\n");
        }
    }
}