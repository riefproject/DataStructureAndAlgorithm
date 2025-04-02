class Stack {
    constructor(capacity) {
        this.data = [];
        this.capacity = capacity;
    }

    isFull() {
        return this.data.length === this.capacity;
    }

    isEmpty() {
        return this.data.length === 0;
    }

    push(value) {
        if (this.isFull()) {
            this.resize();
        }
        this.data.push(value);
        console.log(`Pushed ${value} onto stack.`);
    }

    pop() {
        if (this.isEmpty()) {
            console.log("Stack is EMPTY! Cannot pop.");
            return;
        }
        const poppedValue = this.data.pop();
        console.log(`Popped ${poppedValue} from stack.`);
    }

    topValue() {
        if (this.isEmpty()) {
            console.log("Stack is EMPTY! No top value.");
            return null;
        }
        return this.data[this.data.length - 1];
    }

    peek(n) {
        if (this.isEmpty()) {
            console.log("Stack is EMPTY! No element to peek.");
            return null;
        }
        const index = this.data.length - n;
        if (index < 0 || index >= this.data.length) {
            console.log(`Invalid peek(${n}). Not enough elements.`);
            return null;
        }
        return this.data[index];
    }

    display() {
        if (this.isEmpty()) {
            console.log("Stack is EMPTY!");
            return;
        }
        console.log("Stack contents (top -> bottom):");
        for (let i = this.data.length - 1; i >= 0; i--) {
            console.log(`[${i + 1}]: ${this.data[i]}`);
        }
        console.log();
    }

    resize() {
        this.capacity *= 2;
        console.log("Stack resized.");
    }
}

const books = new Stack(5);

books.push("Mathematics");
books.push("Calculus");
books.push("Physics");
books.push("Web Design");
books.push("Data Structure");

books.display();

console.log(`Top of stack: ${books.topValue()}`);
console.log(`Peek(2): ${books.peek(2)}`);

books.pop();

books.display();