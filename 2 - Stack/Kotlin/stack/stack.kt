class Stack(private var capacity: Int) {
    private val data = mutableListOf<String>()

    fun isFull(): Boolean {
        return data.size == capacity
    }

    fun isEmpty(): Boolean {
        return data.isEmpty()
    }

    fun push(value: String) {
        if (isFull()) {
            resize()
        }
        data.add(value)
        println("Pushed $value onto stack.")
    }

    fun pop() {
        if (isEmpty()) {
            println("Stack is EMPTY! Cannot pop.")
            return
        }
        val poppedValue = data.removeAt(data.size - 1)
        println("Popped $poppedValue from stack.")
    }

    fun topValue(): String? {
        if (isEmpty()) {
            println("Stack is EMPTY! No top value.")
            return null
        }
        return data[data.size - 1]
    }

    fun peek(n: Int): String? {
        if (isEmpty()) {
            println("Stack is EMPTY! No element to peek.")
            return null
        }
        val index = data.size - n
        if (index < 0 || index >= data.size) {
            println("Invalid peek($n). Not enough elements.")
            return null
        }
        return data[index]
    }

    fun display() {
        if (isEmpty()) {
            println("Stack is EMPTY!")
            return
        }
        println("Stack contents (top -> bottom):")
        for (i in data.size - 1 downTo 0) {
            println("[${i + 1}]: ${data[i]}")
        }
        println()
    }

    private fun resize() {
        capacity *= 2
        println("Stack resized.")
    }
}

fun main() {
    val books = Stack(5)

    books.push("Mathematics")
    books.push("Calculus")
    books.push("Physics")
    books.push("Web Design")
    books.push("Data Structure")

    books.display()

    println("Top of stack: ${books.topValue()}")
    println("Peek(2): ${books.peek(2)}")

    books.pop()

    books.display()
}