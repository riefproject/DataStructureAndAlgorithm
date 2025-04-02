// Node class representing each element in the circular singly linked list
class Node(
    var id: String,    // Student ID
    var name: String,  // Student name
    var major: String  // Student major
) {
    var next: Node? = null // Pointer to the next node in the list
}

// LinkedList class to manage the circular singly linked list
class LinkedList {
    private var head: Node? = null // Pointer to the head of the list
    private var tail: Node? = null // Pointer to the tail of the list
    private var size: Int = 0      // Size of the list

    // Function to create a circular singly linked list with the first node
    fun createCircularSL(id: String, name: String, major: String) {
        val newNode = Node(id, name, major)
        newNode.next = newNode
        head = newNode
        tail = newNode
        size = 1
    }

    // Function to add a node at the beginning of the list
    fun addAtFirstNode(id: String, name: String, major: String) {
        if (size == 0) {
            createCircularSL(id, name, major)
            return
        }
        val newNode = Node(id, name, major)
        newNode.next = head
        tail?.next = newNode
        head = newNode
        size++
    }

    // Function to add a node at the nth position in the list
    fun addAtNthNode(id: String, name: String, major: String, pos: Int) {
        if (pos < 1 || pos > size + 1) {
            println("Invalid position!")
            return
        }
        if (pos == 1) {
            addAtFirstNode(id, name, major)
            return
        }
        if (pos == size + 1) {
            addAtLastNode(id, name, major)
            return
        }
        val newNode = Node(id, name, major)
        var cur = head
        for (i in 1 until pos - 1) {
            cur = cur?.next
        }
        newNode.next = cur?.next
        cur?.next = newNode
        size++
    }

    // Function to add a node at the end of the list
    fun addAtLastNode(id: String, name: String, major: String) {
        if (size == 0) {
            createCircularSL(id, name, major)
            return
        }
        val newNode = Node(id, name, major)
        newNode.next = head
        tail?.next = newNode
        tail = newNode
        size++
    }

    // Function to update the first node in the list
    fun updateFirstNode(id: String, name: String, major: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        head?.id = id
        head?.name = name
        head?.major = major
    }

    // Function to update the nth node in the list
    fun updateNthNode(id: String, name: String, major: String, pos: Int) {
        if (pos < 1 || pos > size) {
            println("Invalid position!")
            return
        }
        var cur = head
        for (i in 1 until pos) {
            cur = cur?.next
        }
        cur?.id = id
        cur?.name = name
        cur?.major = major
    }

    // Function to update the last node in the list
    fun updateLastNode(id: String, name: String, major: String) {
        if (size == 0) {
            println("List is empty!")
            return
        }
        tail?.id = id
        tail?.name = name
        tail?.major = major
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
        var cur = head
        for (i in 1 until pos - 1) {
            cur = cur?.next
        }
        cur?.next = cur?.next?.next
        if (pos == size) {
            tail = cur
        }
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
            var cur = head
            while (cur?.next != tail) {
                cur = cur?.next
            }
            tail = cur
            tail?.next = head
        }
        size--
    }

    // Function to print the circular singly linked list
    fun printCircularSL() {
        if (size == 0) {
            println("List is empty!")
            return
        }
        println("Number of Nodes: ${countNodes()}") // Display the total number of nodes
        var cur = head
        var i = 1
        do {
            println("Node $i")
            println("ID\t\t: ${cur?.id}")
            println("Name\t\t: ${cur?.name}")
            println("Major\t\t: ${cur?.major}\n")
            cur = cur?.next
            i++
        } while (cur != head)
    }

    // Utility function to count the number of nodes in the list
    fun countNodes(): Int {
        return size // Return the total number of nodes
    }
}

fun main() {
    val list = LinkedList()

    // Create the circular singly linked list with the first node
    list.createCircularSL("11223399", "Arief F-sa", "Computer Science")
    list.printCircularSL()
    println("==========\n\n\n")

    // Add a node at the beginning of the list
    list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology")
    list.printCircularSL()
    println("==========\n\n\n")

    // Add a node at the end of the list
    list.addAtLastNode("11223400", "Pejeel", "Drop out")
    list.printCircularSL()
    println("==========\n\n\n")

    // Remove the first node from the list
    list.removeFirstNode()
    list.printCircularSL()
    println("==========\n\n\n")

    // Remove the last node from the list
    list.removeLastNode()
    list.printCircularSL()
    println("==========\n\n\n")

    // Add nodes at the beginning and end of the list
    list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology")
    list.addAtLastNode("11223400", "Pejeel", "Drop out")
    list.printCircularSL()
    println("==========\n\n\n")

    // Add nodes at specific positions in the list
    list.addAtNthNode("11223401", "dummy1", "Math", 3)
    list.addAtNthNode("11223402", "dummy2", "Physics", 2)
    list.printCircularSL()
    println("==========\n\n\n")

    // Remove the node at the specified position in the list
    list.removeNthNode(2)
    list.printCircularSL()
    println("==========\n\n\n")
}