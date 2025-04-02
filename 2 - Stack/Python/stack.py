class Stack:
    def __init__(self, capacity):
        """
        Initialize the dynamic stack with a given capacity.
        
        :param capacity: Initial capacity of the stack
        """
        self.data = []
        self.top = -1
        self.capacity = capacity

    def is_full(self):
        """
        Check if the stack is full.
        
        :return: True if the stack is full, False otherwise
        """
        return self.top == self.capacity - 1

    def is_empty(self):
        """
        Check if the stack is empty.
        
        :return: True if the stack is empty, False otherwise
        """
        return self.top == -1

    def resize(self):
        """
        Resize the stack by doubling its capacity.
        """
        self.capacity *= 2

    def push(self, value):
        """
        Push a string onto the stack.
        
        :param value: The string to be pushed onto the stack
        """
        if self.is_full():
            self.resize()
        self.top += 1
        if self.top < len(self.data):
            self.data[self.top] = value
        else:
            self.data.append(value)
        print(f"Pushed {value} onto stack.")

    def pop(self):
        """
        Pop a string from the stack.
        
        :return: The popped string, or None if the stack is empty
        """
        if self.is_empty():
            print("Stack is EMPTY! Cannot pop.")
            return None
        popped_value = self.data[self.top]
        self.top -= 1
        print(f"Popped {popped_value} from stack.")
        return popped_value

    def top_value(self):
        """
        Get the top value without removing it.
        
        :return: The top value, or None if the stack is empty
        """
        if self.is_empty():
            print("Stack is EMPTY! No top value.")
            return None
        return self.data[self.top]

    def peek(self, n):
        """
        Peek a string at the n-th position from the top.
        
        :param n: The position from the top to peek at
        :return: The string at the n-th position, or None if invalid
        """
        if self.is_empty():
            print("Stack is EMPTY! No element to peek.")
            return None
        index = self.top - (n - 1)
        if index < 0 or index > self.top:
            print(f"Invalid peek({n}). Not enough elements.")
            return None
        return self.data[index]

    def display(self):
        """
        Display the contents of the stack.
        """
        if self.is_empty():
            print("Stack is EMPTY!")
            return
        print("Stack contents (top -> bottom):")
        for i in range(self.top, -1, -1):
            print(f"[{i + 1}]: {self.data[i]}")
        print()

    def destroy(self):
        """
        Destroy the stack and free all memory.
        """
        self.data = []
        self.top = -1
        self.capacity = 0
        print("Stack destroyed.")


if __name__ == "__main__":
    books = Stack(5)

    books.push("Mathematics")
    books.push("Calculus")
    books.push("Physics")
    books.push("Web Design")
    books.push("Data Structure")

    books.display()

    print(f"Top of stack: {books.top_value()}")
    print(f"Peek(3): {books.peek(2)}")

    books.pop()

    books.destroy()