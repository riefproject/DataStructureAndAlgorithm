/**
 * Class representing a node in the circular singly linked list.
 */
class Node {
    /**
     * Create a node.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    constructor(id, name, major) {
        this.id = id;
        this.name = name;
        this.major = major;
        this.next = null; // Pointer to the next node
    }
}

/**
 * Class representing a circular singly linked list.
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
     * Create a circular singly linked list with the first node.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    createCircularSL(id, name, major) {
        const newNode = new Node(id, name, major);
        newNode.next = newNode;
        this.head = newNode;
        this.tail = newNode;
        this.size = 1;
    }

    /**
     * Add a node at the beginning of the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    addAtFirstNode(id, name, major) {
        if (this.size === 0) {
            this.createCircularSL(id, name, major);
            return;
        }
        const newNode = new Node(id, name, major);
        newNode.next = this.head;
        this.tail.next = newNode;
        this.head = newNode;
        this.size++;
    }

    /**
     * Add a node at the nth position in the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     * @param {number} pos - The position to insert the node.
     */
    addAtNthNode(id, name, major, pos) {
        if (pos < 1 || pos > this.size + 1) {
            console.log("Invalid position!");
            return;
        }
        if (pos === 1) {
            this.addAtFirstNode(id, name, major);
            return;
        }
        if (pos === this.size + 1) {
            this.addAtLastNode(id, name, major);
            return;
        }
        const newNode = new Node(id, name, major);
        let current = this.head;
        for (let i = 1; i < pos - 1; i++) {
            current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
        this.size++;
    }

    /**
     * Add a node at the end of the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    addAtLastNode(id, name, major) {
        if (this.size === 0) {
            this.createCircularSL(id, name, major);
            return;
        }
        const newNode = new Node(id, name, major);
        newNode.next = this.head;
        this.tail.next = newNode;
        this.tail = newNode;
        this.size++;
    }

    /**
     * Update the first node in the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    updateFirstNode(id, name, major) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        this.head.id = id;
        this.head.name = name;
        this.head.major = major;
    }

    /**
     * Update the nth node in the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     * @param {number} pos - The position of the node to update.
     */
    updateNthNode(id, name, major, pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Invalid position!");
            return;
        }
        let current = this.head;
        for (let i = 1; i < pos; i++) {
            current = current.next;
        }
        current.id = id;
        current.name = name;
        current.major = major;
    }

    /**
     * Update the last node in the list.
     * @param {string} id - The ID of the data.
     * @param {string} name - The name of the data.
     * @param {string} major - The major associated with the data.
     */
    updateLastNode(id, name, major) {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        this.tail.id = id;
        this.tail.name = name;
        this.tail.major = major;
    }

    /**
     * Remove the first node from the list.
     */
    removeFirstNode() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        const del = this.head;
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = this.head.next;
            this.tail.next = this.head;
        }
        this.size--;
    }

    /**
     * Remove the nth node from the list.
     * @param {number} pos - The position of the node to remove.
     */
    removeNthNode(pos) {
        if (pos < 1 || pos > this.size) {
            console.log("Invalid position!");
            return;
        }
        if (pos === 1) {
            this.removeFirstNode();
            return;
        }
        let current = this.head;
        for (let i = 1; i < pos - 1; i++) {
            current = current.next;
        }
        const del = current.next;
        current.next = del.next;
        if (del === this.tail) {
            this.tail = current;
        }
        this.size--;
    }

    /**
     * Remove the last node from the list.
     */
    removeLastNode() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        const del = this.tail;
        if (this.size === 1) {
            this.head = null;
            this.tail = null;
        } else {
            let current = this.head;
            while (current.next !== this.tail) {
                current = current.next;
            }
            this.tail = current;
            this.tail.next = this.head;
        }
        this.size--;
    }

    /**
     * Print all nodes in the circular singly linked list.
     */
    printCircularSL() {
        if (this.size === 0) {
            console.log("List is empty!");
            return;
        }
        console.log(`Number of Nodes: ${this.size}`);
        let current = this.head;
        let i = 1;
        do {
            console.log(`Node ${i}`);
            console.log(`ID\t\t: ${current.id}`);
            console.log(`Name\t\t: ${current.name}`);
            console.log(`Major\t\t: ${current.major}\n`);
            current = current.next;
            i++;
        } while (current !== this.head);
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
list.createCircularSL("11223399", "Arief F-sa", "Computer Science");
list.printCircularSL();
console.log("==========\n");

list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
list.printCircularSL();
console.log("==========\n");

list.addAtLastNode("11223400", "Pejeel", "Drop out");
list.printCircularSL();
console.log("==========\n");

list.removeFirstNode();
list.printCircularSL();
console.log("==========\n");

list.removeLastNode();
list.printCircularSL();
console.log("==========\n");

list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
list.addAtLastNode("11223400", "Pejeel", "Drop out");
list.printCircularSL();
console.log("==========\n");

list.addAtNthNode("11223401", "dummy1", "Math", 3);
list.addAtNthNode("11223402", "dummy2", "Physics", 2);
list.printCircularSL();
console.log("==========\n");

list.removeNthNode(2);
list.printCircularSL();
console.log("==========\n");