// Node class representing each element in the circular doubly linked list
class Node(
    var name: String,     // Item name
    var price: Int,       // Item price
    var available: Int    // Item availability
) {
    var prev: Node? = null // Pointer to the previous node in the list
    var next: Node? = null // Pointer to the next node in the list
}

// LinkedList class to manage the circular doubly linked list
class LinkedList {
    private var head: Node? = null // Pointer to the head of the list
    private var tail: Node? = null // Pointer to the tail of the list
    private var size: Int = 0      // Size of the list

    // Function to create a circular doubly linked list with the first node
    fun createCircularDL(name: String, price: Int, available: Int) {
        val newNode = Node(name, price, available)
        newNode.next = newNode
        newNode.prev = newNode
        head = newNode
        tail = newNode
        size = 1
    }

    // Function to add a node at the beginning of the list
    fun addAtFirstNode(name: String, price: Int, available: Int) {
        if (size == 0) {
            createCircularDL(name, price, available)
            return
        }
        val newNode = Node(name, price, available)
        newNode.next = head
        newNode.prev = tail
        head?.prev = newNode
        tail?.next = newNode
        head = newNode
        size++
    }

    // Function to add a node at the nth position in the list
    fun addAtNthNode(name: String, price: Int, available: Int, pos: Int) {
        if (pos < 1 || pos > size + 1) {
            println("Invalid position!")
            return
        }
        if (pos == 1) {
            addAtFirstNode(name, price, available)
            return
        }
        if (pos == size + 1) {
            addAtLastNode(name, price, available)
            return
        }
        val newNode = Node(name, price, available)
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
    fun addAtLastNode(name: String, price: Int, available: Int) {
        if (size == 0) {
            createCircularDL(name, price, available)
            return
        }
        val newNode = Node(name, price, available)
        newNode.next = head
        newNode.prev = tail
        tail?.next = newNode
        head?.prev = newNode
        tail = newNode
        size++
    }

    // Function to update the first node in the list
    fun updateFirstNode(name: String, price: Int, available: Int) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        head?.name = name
        head?.price = price
        head?.available = available
    }

    // Function to update the nth node in the list
    fun updateNthNode(name: String, price: Int, available: Int, pos: Int) {
        if (pos < 1 || pos > size) {
            println("Invalid position!")
            return
        }
        var cur = head
        for (i in 1 until pos) {
            cur = cur?.next
        }
        cur?.name = name
        cur?.price = price
        cur?.available = available
    }

    // Function to update the last node in the list
    fun updateLastNode(name: String, price: Int, available: Int) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        tail?.name = name
        tail?.price = price
        tail?.available = available
    }

    // Function to remove the first node from the list
    fun removeFirstNode() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        if (size == 1) {
            head = null
            tail = null
        } else {
            head = head?.next
            head?.prev = tail
            tail?.next = head
        }
        size--
    }

    // Function to remove the nth node from the list
    fun removeNthNode(pos: Int) {
        if (pos < 1 || pos > size) {
            println("Invalid position!")
            return
        }
        if (pos == 1) {
            removeFirstNode()
            return
        }
        if (pos == size) {
            removeLastNode()
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
    fun removeLastNode() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        if (size == 1) {
            head = null
            tail = null
        } else {
            tail = tail?.prev
            tail?.next = head
            head?.prev = tail
        }
        size--
    }

    // Function to print the circular doubly linked list
    fun printCircularDL() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        var cur = head
        for (i in 0 until size) {
            println("Name\t\t: ${cur?.name}\nPrice\t\t: ${cur?.price}\nAvailable\t: ${cur?.available}")
            cur = cur?.next
        }
    }

    // Utility function to count the number of nodes in the list
    fun countNodes(): Int {
        return size // Return the total number of nodes
    }
}

fun main() {
    val list = LinkedList()

    // Create the circular doubly linked list with the first node
    list.createCircularDL("Laptop", 20000000, 20)
    list.printCircularDL()
    println("==========\n\n\n")

    // Add a node at the beginning of the list
    list.addAtFirstNode("Handphone", 5000000, 50)
    list.printCircularDL()
    println("==========\n\n\n")

    // Add nodes at the end of the list
    list.addAtLastNode("Mouse", 1200000, 100)
    list.addAtLastNode("Keyboard", 2250000, 100)
    list.addAtLastNode("Headphone", 1800000, 100)
    list.addAtLastNode("Monitor", 4200000, 100)
    list.printCircularDL()
    println("==========\n\n\n")

    // Remove the first node from the list
    list.removeFirstNode()
    list.printCircularDL()
    println("==========\n\n\n")

    // Remove the last node from the list
    list.removeLastNode()
    list.printCircularDL()
    println("==========\n\n\n")

    // Add a node at the nth position in the list
    list.addAtNthNode("RTX 5090", 40000000, 15, 3)
    list.printCircularDL()
    println("==========\n\n\n")

    // Remove the nth node from the list
    list.removeNthNode(4)
    list.printCircularDL()
    println("==========\n\n\n")

    // Update the first node in the list
    list.updateFirstNode("Laptop", 19000000, 10)
    // Update the nth node in the list
    list.updateNthNode("Mouse", 1000000, 3, 2)
    // Update the last node in the list
    list.updateLastNode("Headphone", 1900000, 5)
    list.printCircularDL()
    println("==========\n\n\n")

    // Print the total number of nodes in the list
    println("Total nodes: ${list.countNodes()}")
}