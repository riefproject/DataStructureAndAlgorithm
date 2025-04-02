/**
 * Class representing a node in the linked list.
 */
class Node {
    /**
     * Create a node.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     */
    constructor(title, author, year) {
        this.title = title;
        this.author = author;
        this.year = year;
        this.next = null; // Pointer to the next node
    }
}

/**
 * Class representing a singly linked list.
 */
class LinkedList {
    /**
     * Create a linked list.
     */
    constructor() {
        this.head = null; // Pointer to the head of the list
        this.tail = null; // Pointer to the tail of the list
        this.size = 0; // Size of the list
    }

    /**
     * Add a node at the end of the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     */
    addNode(title, author, year) {
        const newBook = new Node(title, author, year);

        if (!this.head) {
            this.head = newBook;
            this.tail = newBook;
        } else {
            this.tail.next = newBook;
            this.tail = newBook;
        }

        this.size++;
    }

    /**
     * Add a node at the beginning of the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     */
    addAtFirstNode(title, author, year) {
        const newBook = new Node(title, author, year);

        if (!this.head) {
            this.head = newBook;
            this.tail = newBook;
        } else {
            newBook.next = this.head;
            this.head = newBook;
        }

        this.size++;
    }

    /**
     * Add a node at a specified position in the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     * @param {number} pos - The position to insert the node.
     */
    addAtNthNode(title, author, year, pos) {
        if (pos < 1 || pos > this.size + 1) {
            console.log("Position out of range");
            return;
        }

        if (pos === 1) {
            this.addAtFirstNode(title, author, year);
            return;
        }

        if (pos === this.size + 1) {
            this.addNode(title, author, year);
            return;
        }

        const newBook = new Node(title, author, year);
        let current = this.head;

        for (let i = 1; i < pos - 1; i++) {
            current = current.next;
        }

        newBook.next = current.next;
        current.next = newBook;

        this.size++;
    }

    /**
     * Update the details of the first node in the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     */
    updateFirstNode(title, author, year) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }

        this.head.title = title;
        this.head.author = author;
        this.head.year = year;
    }

    /**
     * Update the details of the nth node in the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     * @param {number} pos - The position of the node to update.
     */
    updateNthNode(title, author, year, pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Position out of range");
            return;
        }

        if (pos === 1) {
            this.updateFirstNode(title, author, year);
            return;
        }

        let current = this.head;

        for (let i = 1; i < pos; i++) {
            current = current.next;
        }

        current.title = title;
        current.author = author;
        current.year = year;
    }

    /**
     * Update the details of the last node in the linked list.
     * @param {string} title - The title of the book.
     * @param {string} author - The author of the book.
     * @param {string} year - The publication year of the book.
     */
    updateLastNode(title, author, year) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }

        this.tail.title = title;
        this.tail.author = author;
        this.tail.year = year;
    }

    /**
     * Remove the first node from the linked list.
     */
    removeAtFirst() {
        if (this.size === 0) return;

        this.head = this.head.next;

        if (this.size === 1) {
            this.tail = null;
        }

        this.size--;
    }

    /**
     * Remove the nth node from the linked list.
     * @param {number} pos - The position of the node to remove.
     */
    removeAtNthNode(pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Position out of range");
            return;
        }

        if (pos === 1) {
            this.removeAtFirst();
            return;
        }

        let current = this.head;
        let before = null;

        for (let i = 1; i < pos; i++) {
            before = current;
            current = current.next;
        }

        before.next = current.next;

        if (pos === this.size) {
            this.tail = before;
        }

        this.size--;
    }

    /**
     * Remove the last node from the linked list.
     */
    removeAtLast() {
        if (this.size === 0) return;

        if (this.size === 1) {
            this.head = this.tail = null;
            this.size--;
            return;
        }

        let current = this.head;

        while (current.next !== this.tail) {
            current = current.next;
        }

        current.next = null;
        this.tail = current;
        this.size--;
    }

    /**
     * Print all nodes in the linked list.
     */
    printSingleLinkedList() {
        console.log(`Number of Nodes: ${this.size}`);
        let current = this.head;
        let i = 1;

        while (current) {
            console.log(`NODE ${i}`);
            console.log(`Title\t: ${current.title}`);
            console.log(`Author\t: ${current.author}`);
            console.log(`Year\t: ${current.year}\n`);
            current = current.next;
            i++;
        }
    }

    /**
     * Utility function to count the number of nodes in the linked list.
     * @returns {number} The total number of nodes.
     */
    countNodes() {
        return this.size;
    }
}

// Example usage
const list = new LinkedList();
list.addNode("Introduction to C", "Arief", "2022");
list.printSingleLinkedList();
console.log("=========\n");

list.addAtFirstNode("Chemistry", "Wijaya", "2019");
list.printSingleLinkedList();
console.log("=========\n");

list.addNode("Physics", "Nisa", "2024");
list.addNode("Introduction to Python", "Arief", "2023");
list.addAtNthNode("F1 For Child", "Anomali", "2000", 2);
list.printSingleLinkedList();
console.log("=========\n");

list.removeAtFirst();
list.printSingleLinkedList();
list.updateFirstNode("Introduction to C++", "Arief", "2022");
console.log("=========\n");

list.removeAtLast();
list.printSingleLinkedList();
console.log("=========\n");

list.removeAtNthNode(2);
list.printSingleLinkedList();
console.log("=========\n");

list.addNode("Introduction to Kotlin", "Arief", "2023");
list.updateNthNode("Math", "Nisa", "2024", 2);
list.printSingleLinkedList();
console.log("=========\n");