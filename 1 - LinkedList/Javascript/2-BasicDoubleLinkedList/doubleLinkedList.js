/**
 * Class representing a node in the doubly linked list.
 */
class Node {
    /**
     * Create a node.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    constructor(name, username, email, password) {
        this.name = name;
        this.username = username;
        this.email = email;
        this.password = password;
        this.prev = null; // Pointer to the previous node
        this.next = null; // Pointer to the next node
    }
}

/**
 * Class representing a doubly linked list.
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
     * Create a doubly linked list with the first node.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    createDoubleLinkedList(name, username, email, password) {
        const newNode = new Node(name, username, email, password);
        this.head = newNode;
        this.tail = newNode;
        this.size = 1;
    }

    /**
     * Add a node at the beginning of the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    addAtFirstNode(name, username, email, password) {
        if (this.size === 0) {
            this.createDoubleLinkedList(name, username, email, password);
            return;
        }
        const newNode = new Node(name, username, email, password);
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
        this.size++;
    }

    /**
     * Add a node at the nth position in the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     * @param {number} pos - The position to insert the node.
     */
    addAtNthNode(name, username, email, password, pos) {
        if (pos < 1 || pos > this.size + 1) {
            console.log("Invalid position!");
            return;
        }
        if (pos === 1) {
            this.addAtFirstNode(name, username, email, password);
            return;
        }
        if (pos === this.size + 1) {
            this.addAtLastNode(name, username, email, password);
            return;
        }
        const newNode = new Node(name, username, email, password);
        let current = this.head;
        for (let i = 1; i < pos - 1; i++) {
            current = current.next;
        }
        newNode.next = current.next;
        newNode.prev = current;
        current.next.prev = newNode;
        current.next = newNode;
        this.size++;
    }

    /**
     * Add a node at the end of the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    addAtLastNode(name, username, email, password) {
        if (this.size === 0) {
            this.createDoubleLinkedList(name, username, email, password);
            return;
        }
        const newNode = new Node(name, username, email, password);
        newNode.prev = this.tail;
        this.tail.next = newNode;
        this.tail = newNode;
        this.size++;
    }

    /**
     * Update the first node in the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    updateFirstNode(name, username, email, password) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        this.head.name = name;
        this.head.username = username;
        this.head.email = email;
        this.head.password = password;
    }

    /**
     * Update the nth node in the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     * @param {number} pos - The position of the node to update.
     */
    updateNthNode(name, username, email, password, pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Invalid position!");
            return;
        }
        let current = this.head;
        for (let i = 1; i < pos; i++) {
            current = current.next;
        }
        current.name = name;
        current.username = username;
        current.email = email;
        current.password = password;
    }

    /**
     * Update the last node in the list.
     * @param {string} name - The name of the data.
     * @param {string} username - The username associated with the data.
     * @param {string} email - The email associated with the data.
     * @param {string} password - The password associated with the data.
     */
    updateLastNode(name, username, email, password) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        this.tail.name = name;
        this.tail.username = username;
        this.tail.email = email;
        this.tail.password = password;
    }

    /**
     * Remove the first node from the list.
     */
    removeAtFirst() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
        }
        this.size--;
    }

    /**
     * Remove the nth node from the list.
     * @param {number} pos - The position of the node to remove.
     */
    removeAtNthNode(pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Invalid position!");
            return;
        }
        if (pos === 1) {
            this.removeAtFirst();
            return;
        }
        if (pos === this.size) {
            this.removeAtLast();
            return;
        }
        let current = this.head;
        for (let i = 1; i < pos; i++) {
            current = current.next;
        }
        current.prev.next = current.next;
        current.next.prev = current.prev;
        this.size--;
    }

    /**
     * Remove the last node from the list.
     */
    removeAtLast() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.tail = this.tail.prev;
            this.tail.next = null;
        }
        this.size--;
    }

    /**
     * Print all nodes in the doubly linked list.
     */
    printDoubleLinkedList() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        console.log(`Number of Nodes: ${this.size}`);
        let current = this.head;
        let i = 1;
        while (current) {
            console.log(`Node ${i}`);
            console.log(`Name\t\t: ${current.name}`);
            console.log(`Username\t: ${current.username}`);
            console.log(`Email\t\t: ${current.email}`);
            console.log(`Password\t: ${current.password}\n`);
            current = current.next;
            i++;
        }
    }

    /**
     * Utility function to count the number of nodes in the list.
     * @returns {number} The total number of nodes.
     */
    countNodes() {
        return this.size;
    }
}

// Example usage
const list = new LinkedList();
list.createDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
list.printDoubleLinkedList();
console.log("==========\n");

list.addAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
list.printDoubleLinkedList();
console.log("==========\n");

list.addAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
list.printDoubleLinkedList();
console.log("==========\n");

list.removeAtFirst();
list.printDoubleLinkedList();
console.log("==========\n");

list.removeAtLast();
list.printDoubleLinkedList();
console.log("==========\n");

list.addAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
list.addAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
list.addAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
list.addAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
list.addAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
list.printDoubleLinkedList();
console.log("==========\n");

list.addAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
list.printDoubleLinkedList();
console.log("==========\n");

list.removeAtNthNode(6);
list.printDoubleLinkedList();
console.log("==========\n");