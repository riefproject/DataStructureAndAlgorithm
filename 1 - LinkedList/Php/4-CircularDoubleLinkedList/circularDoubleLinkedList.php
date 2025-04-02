<?php

/**
 * Class representing a node in the circular doubly linked list.
 */
class Node {
    public $name;
    public $price;
    public $available;
    public $prev;
    public $next;

    /**
     * Create a node.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function __construct($name, $price, $available) {
        $this->name = $name;
        $this->price = $price;
        $this->available = $available;
        $this->prev = null; // Pointer to the previous node
        $this->next = null; // Pointer to the next node
    }
}

/**
 * Class representing a circular doubly linked list.
 */
class LinkedList {
    private $head;
    private $tail;
    private $size;

    /**
     * Create a linked list.
     */
    public function __construct() {
        $this->head = null; // Pointer to the head of the list
        $this->tail = null; // Pointer to the tail of the list
        $this->size = 0; // Size of the list
    }

    /**
     * Create a circular doubly linked list with the first node.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function createCircularDL($name, $price, $available) {
        $newNode = new Node($name, $price, $available);
        $newNode->next = $newNode;
        $newNode->prev = $newNode;
        $this->head = $newNode;
        $this->tail = $newNode;
        $this->size = 1;
    }

    /**
     * Add a node at the beginning of the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function addAtFirstNode($name, $price, $available) {
        if ($this->size === 0) {
            $this->createCircularDL($name, $price, $available);
            return;
        }
        $newNode = new Node($name, $price, $available);
        $newNode->next = $this->head;
        $newNode->prev = $this->tail;
        $this->head->prev = $newNode;
        $this->tail->next = $newNode;
        $this->head = $newNode;
        $this->size++;
    }

    /**
     * Add a node at the nth position in the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     * @param int $pos - The position to insert the node.
     */
    public function addAtNthNode($name, $price, $available, $pos) {
        if ($pos < 1 || $pos > $this->size + 1) {
            echo "Invalid position!\n";
            return;
        }
        if ($pos == 1) {
            $this->addAtFirstNode($name, $price, $available);
            return;
        }
        if ($pos == $this->size + 1) {
            $this->addAtLastNode($name, $price, $available);
            return;
        }
        $newNode = new Node($name, $price, $available);
        $current = $this->head;
        for ($i = 1; $i < $pos - 1; $i++) {
            $current = $current->next;
        }
        $newNode->next = $current->next;
        $newNode->prev = $current;
        $current->next->prev = $newNode;
        $current->next = $newNode;
        $this->size++;
    }

    /**
     * Add a node at the end of the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function addAtLastNode($name, $price, $available) {
        if ($this->size === 0) {
            $this->createCircularDL($name, $price, $available);
            return;
        }
        $newNode = new Node($name, $price, $available);
        $newNode->next = $this->head;
        $newNode->prev = $this->tail;
        $this->tail->next = $newNode;
        $this->head->prev = $newNode;
        $this->tail = $newNode;
        $this->size++;
    }

    /**
     * Update the first node in the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function updateFirstNode($name, $price, $available) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->head->name = $name;
        $this->head->price = $price;
        $this->head->available = $available;
    }

    /**
     * Update the nth node in the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     * @param int $pos - The position of the node to update.
     */
    public function updateNthNode($name, $price, $available, $pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Invalid position!\n";
            return;
        }
        $current = $this->head;
        for ($i = 1; $i < $pos; $i++) {
            $current = $current->next;
        }
        $current->name = $name;
        $current->price = $price;
        $current->available = $available;
    }

    /**
     * Update the last node in the list.
     * @param string $name - The name of the item.
     * @param int $price - The price of the item.
     * @param int $available - The availability of the item.
     */
    public function updateLastNode($name, $price, $available) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->tail->name = $name;
        $this->tail->price = $price;
        $this->tail->available = $available;
    }

    /**
     * Remove the first node from the list.
     */
    public function removeFirstNode() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $temp = $this->head;
        if ($this->size === 1) {
            $this->head = null;
            $this->tail = null;
        } else {
            $this->head = $this->head->next;
            $this->head->prev = $this->tail;
            $this->tail->next = $this->head;
        }
        $this->size--;
    }

    /**
     * Remove the nth node from the list.
     * @param int $pos - The position of the node to remove.
     */
    public function removeNthNode($pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Invalid position!\n";
            return;
        }
        if ($pos == 1) {
            $this->removeFirstNode();
            return;
        }
        if ($pos == $this->size) {
            $this->removeLastNode();
            return;
        }
        $current = $this->head;
        for ($i = 1; $i < $pos; $i++) {
            $current = $current->next;
        }
        $current->prev->next = $current->next;
        $current->next->prev = $current->prev;
        $this->size--;
    }

    /**
     * Remove the last node from the list.
     */
    public function removeLastNode() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $temp = $this->tail;
        if ($this->size === 1) {
            $this->head = null;
            $this->tail = null;
        } else {
            $this->tail = $this->tail->prev;
            $this->tail->next = $this->head;
            $this->head->prev = $this->tail;
        }
        $this->size--;
    }

    /**
     * Print all nodes in the circular doubly linked list.
     */
    public function printCircularDL() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $current = $this->head;
        do {
            echo "Name\t\t: " . $current->name . "\nPrice\t\t: " . $current->price . "\nAvailable\t: " . $current->available . "\n\n";
            $current = $current->next;
        } while ($current !== $this->head);
    }

    /**
     * Utility function to count the number of nodes in the list.
     * @return int The total number of nodes.
     */
    public function countNodes() {
        return $this->size;
    }
}

// Example usage
$list = new LinkedList();
$list->createCircularDL("Laptop", 20000000, 20);
$list->printCircularDL();
echo "==========\n\n";

$list->addAtFirstNode("Handphone", 5000000, 50);
$list->printCircularDL();
echo "==========\n\n";

$list->addAtLastNode("Mouse", 1200000, 100);
$list->addAtLastNode("Keyboard", 2250000, 100);
$list->addAtLastNode("Headphone", 1800000, 100);
$list->addAtLastNode("Monitor", 4200000, 100);
$list->printCircularDL();
echo "==========\n\n";

$list->removeFirstNode();
$list->printCircularDL();
echo "==========\n\n";

$list->removeLastNode();
$list->printCircularDL();
echo "==========\n\n";

$list->addAtNthNode("RTX 5090", 40000000, 15, 3);
$list->printCircularDL();
echo "==========\n\n";

$list->removeNthNode(4);
$list->printCircularDL();
echo "==========\n\n";

$list->updateFirstNode("Laptop", 19000000, 10);
$list->updateNthNode("Mouse", 1000000, 3, 2);
$list->updateLastNode("Headphone", 1900000, 5);
$list->printCircularDL();
echo "==========\n\n";

echo "Total nodes: " . $list->countNodes() . "\n";
?>