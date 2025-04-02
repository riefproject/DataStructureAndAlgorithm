// Node class representing each element in the doubly linked list
class Node(
    var name: String,     // Data title
    var username: String, // Author of the data
    var email: String,    // Email of the user
    var password: String  // Password of the user
) {
    var prev: Node? = null // Pointer to the previous node in the list
    var next: Node? = null // Pointer to the next node in the list
}

// LinkedList class to manage the doubly linked list
class LinkedList {
    private var head: Node? = null // Pointer to the head of the list
    private var tail: Node? = null // Pointer to the tail of the list
    private var size: Int = 0      // Size of the list

    // Function to create a doubly linked list with the first node
    fun createDoubleLinkedList(name: String, username: String, email: String, password: String) {
        val newNode = Node(name, username, email, password)
        head = newNode
        tail = newNode
        size = 1
    }

    // Function to add a node at the beginning of the list
    fun addAtFirstNode(name: String, username: String, email: String, password: String) {
        if (size == 0) {
            createDoubleLinkedList(name, username, email, password)
            return
        }
        val newNode = Node(name, username, email, password)
        newNode.next = head
        head?.prev = newNode
        head = newNode
        size++
    }

    // Function to add a node at the nth position in the list
    fun addAtNthNode(name: String, username: String, email: String, password: String, pos: Int) {
        if (pos < 1 || pos > size + 1) {
            println("Invalid position!")
            return
        }
        if (pos == 1) {
            addAtFirstNode(name, username, email, password)
            return
        }
        if (pos == size + 1) {
            addAtLastNode(name, username, email, password)
            return
        }
        val newNode = Node(name, username, email, password)
        var cur = head
        for (i in 1 until pos - 1) {
            cur = cur?.next
        }
        newNode.next = cur?.next
        newNode.prev = cur
        cur?.next?.prev = newNode
        cur?.next = newNode
        size++
    }

    // Function to add a node at the end of the list
    fun addAtLastNode(name: String, username: String, email: String, password: String) {
        if (size == 0) {
            createDoubleLinkedList(name, username, email, password)
            return
        }
        val newNode = Node(name, username, email, password)
        newNode.prev = tail
        tail?.next = newNode
        tail = newNode
        size++
    }

    // Function to update the first node in the list
    fun updateFirstNode(name: String, username: String, email: String, password: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        head?.name = name
        head?.username = username
        head?.email = email
        head?.password = password
    }

    // Function to update the nth node in the list
    fun updateNthNode(name: String, username: String, email: String, password: String, pos: Int) {
        if (pos < 1 || pos > size) {
            println("Invalid position!")
            return
        }
        var cur = head
        for (i in 1 until pos) {
            cur = cur?.next
        }
        cur?.name = name
        cur?.username = username
        cur?.email = email
        cur?.password = password
    }

    // Function to update the last node in the list
    fun updateLastNode(name: String, username: String, email: String, password: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        tail?.name = name
        tail?.username = username
        tail?.email = email
        tail?.password = password
    }

    // Function to remove the first node from the list
    fun removeAtFirst() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        if (size == 1) {
            head = null
            tail = null
        } else {
            head = head?.next
            head?.prev = null
        }
        size--
    }

    // Function to remove the nth node from the list
    fun removeAtNthNode(pos: Int) {
        if (pos < 1 || pos > size) {
            println("Invalid position!")
            return
        }
        if (pos == 1) {
            removeAtFirst()
            return
        }
        if (pos == size) {
            removeAtLast()
            return
        }
        var cur = head
        for (i in 1 until pos) {
            cur = cur?.next
        }
        cur?.prev?.next = cur?.next
        cur?.next?.prev = cur?.prev
        size--
    }

    // Function to remove the last node from the list
    fun removeAtLast() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        if (size == 1) {
            head = null
            tail = null
        } else {
            tail = tail?.prev
            tail?.next = null
        }
        size--
    }

    // Function to print the doubly linked list
    fun printDoubleLinkedList() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        println("Number of Nodes: ${countNodes()}") // Display the total number of nodes
        var cur = head
        var i = 1
        while (cur != null) {
            println("Node $i")
            println("Name\t\t: ${cur.name}")
            println("Username\t: ${cur.username}")
            println("Email\t\t: ${cur.email}")
            println("Password\t: ${cur.password}\n")
            cur = cur.next
            i++
        }
    }

    // Utility function to count the number of nodes in the list
    fun countNodes(): Int {
        return size // Return the total number of nodes
    }
}

fun main() {
    val list = LinkedList()

    // Create the doubly linked list with the first node
    list.createDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123")
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Add a node at the end of the list
    list.addAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123")
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Add a node at the beginning of the list
    list.addAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123")
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Remove the first node from the list
    list.removeAtFirst()
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Remove the last node from the list
    list.removeAtLast()
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Add multiple nodes at the beginning of the list
    list.addAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123")
    list.addAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123")
    list.addAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123")
    list.addAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123")
    list.addAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123")
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Add a node at the nth position in the list
    list.addAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5)
    list.printDoubleLinkedList()
    println("==========\n\n\n")

    // Remove the nth node from the list
    list.removeAtNthNode(6)
    list.printDoubleLinkedList()
    println("==========\n\n\n")
}