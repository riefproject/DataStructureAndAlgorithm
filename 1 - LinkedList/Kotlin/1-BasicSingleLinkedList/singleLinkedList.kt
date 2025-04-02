// Node class representing each element in the singly linked list
class Node(
    var title: String,  // Book title
    var author: String, // Author of the book
    var year: String    // Publication year of the book
) {
    var next: Node? = null // Pointer to the next book in the list
}

// LinkedList class to manage the singly linked list
class LinkedList {
    private var head: Node? = null // Pointer to the head of the list
    private var tail: Node? = null // Pointer to the tail of the list
    private var size: Int = 0      // Size of the list

    // Function to add a node at the end of the linked list
    fun addNode(title: String, author: String, year: String) {
        val newBook = Node(title, author, year) // Create a new node

        if (head == null) { // If the list is empty
            head = newBook
            tail = newBook
        } else {
            tail?.next = newBook
            tail = newBook
        }

        size++
    }

    // Function to add a node at the beginning of the linked list
    fun addAtFirstNode(title: String, author: String, year: String) {
        val newBook = Node(title, author, year) // Create a new node

        newBook.next = head
        head = newBook

        if (size == 0) {
            tail = newBook
        }

        size++
    }

    // Function to add a node at a specified position in the linked list
    fun addAtNthNode(title: String, author: String, year: String, pos: Int) {
        if (pos < 1 || pos > size + 1) { // Validate position
            println("Position out of range")
            return
        }
        if (pos == 1) { // If adding at the first position
            addAtFirstNode(title, author, year)
            return
        }
        if (pos == size + 1) { // If adding at the last position
            addNode(title, author, year)
            return
        }

        val newBook = Node(title, author, year) // Create a new node

        // Find the position before where the new book will be inserted
        var cur = head
        for (i in 1 until pos - 1) {
            cur = cur?.next
        }

        // Insert the new book into the linked list at the specified position
        newBook.next = cur?.next
        cur?.next = newBook

        size++
    }

    // Function to update the details of the first node in the linked list
    fun updateFirstNode(title: String, author: String, year: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }

        // Update book details
        head?.title = title
        head?.author = author
        head?.year = year
    }

    // Function to update the details of the nth node in the linked list
    fun updateNthNode(title: String, author: String, year: String, pos: Int) {
        if (pos < 1 || pos > size) { // Validate position
            println("Position out of range")
            return
        }
        if (pos == 1) { // If updating the first node
            updateFirstNode(title, author, year)
            return
        }
        if (pos == size) { // If updating the last node
            updateLastNode(title, author, year)
            return
        }

        // Normal update at the nth position
        var cur = head
        for (i in 1 until pos) { // Traverse to the nth node
            cur = cur?.next
        }

        // Update book details
        cur?.title = title
        cur?.author = author
        cur?.year = year
    }

    // Function to update the details of the last node in the linked list
    fun updateLastNode(title: String, author: String, year: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }

        // Update book details
        tail?.title = title
        tail?.author = author
        tail?.year = year
    }

    // Function to remove the first node from the linked list
    fun removeAtFirst() {
        if (size == 0) return // If the list is empty, do nothing

        head = head?.next // Update the head pointer to the next node

        if (size == 1) {
            tail = null
        }

        size--
    }

    // Function to remove the nth node from the linked list
    fun removeAtNthNode(pos: Int) {
        if (pos < 1 || pos > size) { // Validate position
            println("Position out of range")
            return
        }
        if (pos == 1) { // If removing the first node
            removeAtFirst()
            return
        }
        if (pos == size) { // If removing the last node
            removeAtLast()
            return
        }

        // Normal removal of the nth node
        var cur = head
        var before: Node? = null
        for (i in 1 until pos) {
            before = cur // Keep track of the node before the one to be deleted
            cur = cur?.next // Move to the next node
        }

        before?.next = cur?.next // Bypass the node to be deleted

        size--
    }

    // Function to remove the last node from the linked list
    fun removeAtLast() {
        if (size == 0) return // If the list is empty, do nothing

        if (size == 1) { // If there's only one node
            head = null
            tail = null
            size--
            return
        }

        // Find the second last node
        var cur = head
        while (cur?.next != tail) {
            cur = cur?.next
        }

        tail = cur // Update the tail pointer
        tail?.next = null

        size--
    }

    // Function to print all nodes in the linked list
    fun printSingleLinkedList() {
        println("Number of Nodes: $size") // Display the total number of nodes
        var cur = head
        var i = 1
        while (cur != null) {
            println("NODE $i")                // Print node number
            println("Title\t: ${cur.title}")  // Print the title of the book
            println("Author\t: ${cur.author}") // Print the author of the book
            println("Year\t: ${cur.year}\n")  // Print the publication year of the book
            cur = cur.next                    // Move to the next node
            i++
        }
    }

    // Utility function to count the number of nodes in the linked list
    fun countNodes(): Int {
        return size // Return the total number of nodes
    }
}

fun main() {
    val list = LinkedList()

    // Adding and printing nodes to demonstrate linked list operations
    list.addNode("Introduction to C", "Arief", "2022")
    list.printSingleLinkedList()
    println("=========\n")

    list.addAtFirstNode("Chemistry", "Wijaya", "2019")
    list.printSingleLinkedList()
    println("=========\n")

    list.addNode("Physics", "Nisa", "2024")
    list.addNode("Introduction to Python", "Arief", "2023")
    list.addAtNthNode("F1 For Child", "Anomali", "2000", 2)
    list.printSingleLinkedList()
    println("=========\n")

    // Removing nodes and updating information to show dynamic modifications
    list.removeAtFirst()
    list.printSingleLinkedList()
    list.updateFirstNode("Introduction to C++", "Arief", "2022")
    println("=========\n")

    list.removeAtLast()
    list.printSingleLinkedList()
    println("=========\n")

    list.removeAtNthNode(2)
    list.printSingleLinkedList()
    println("=========\n")

    list.addNode("Introduction to Kotlin", "Arief", "2023")
    list.updateNthNode("Math", "Nisa", "2024", 2)
    list.printSingleLinkedList()
    println("=========\n")
}