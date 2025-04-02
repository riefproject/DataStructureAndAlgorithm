<?php

/**
 * Class representing a node in the circular singly linked list.
 */
class Node {
    public $id;
    public $name;
    public $major;
    public $next;

    /**
     * Create a node.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function __construct($id, $name, $major) {
        $this->id = $id;
        $this->name = $name;
        $this->major = $major;
        $this->next = null; // Pointer to the next node
    }
}

/**
 * Class representing a circular singly linked list.
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
     * Create a circular singly linked list with the first node.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function createCircularSL($id, $name, $major) {
        $newNode = new Node($id, $name, $major);
        $newNode->next = $newNode;
        $this->head = $newNode;
        $this->tail = $newNode;
        $this->size = 1;
    }

    /**
     * Add a node at the beginning of the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function addAtFirstNode($id, $name, $major) {
        if ($this->size === 0) {
            $this->createCircularSL($id, $name, $major);
            return;
        }
        $newNode = new Node($id, $name, $major);
        $newNode->next = $this->head;
        $this->tail->next = $newNode;
        $this->head = $newNode;
        $this->size++;
    }

    /**
     * Add a node at the nth position in the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     * @param int $pos - The position to insert the node.
     */
    public function addAtNthNode($id, $name, $major, $pos) {
        if ($pos < 1 || $pos > $this->size + 1) {
            echo "Invalid position!\n";
            return;
        }
        if ($pos == 1) {
            $this->addAtFirstNode($id, $name, $major);
            return;
        }
        if ($pos == $this->size + 1) {
            $this->addAtLastNode($id, $name, $major);
            return;
        }
        $newNode = new Node($id, $name, $major);
        $current = $this->head;
        for ($i = 1; $i < $pos - 1; $i++) {
            $current = $current->next;
        }
        $newNode->next = $current->next;
        $current->next = $newNode;
        $this->size++;
    }

    /**
     * Add a node at the end of the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function addAtLastNode($id, $name, $major) {
        if ($this->size === 0) {
            $this->createCircularSL($id, $name, $major);
            return;
        }
        $newNode = new Node($id, $name, $major);
        $newNode->next = $this->head;
        $this->tail->next = $newNode;
        $this->tail = $newNode;
        $this->size++;
    }

    /**
     * Update the first node in the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function updateFirstNode($id, $name, $major) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->head->id = $id;
        $this->head->name = $name;
        $this->head->major = $major;
    }

    /**
     * Update the nth node in the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     * @param int $pos - The position of the node to update.
     */
    public function updateNthNode($id, $name, $major, $pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Invalid position!\n";
            return;
        }
        $current = $this->head;
        for ($i = 1; $i < $pos; $i++) {
            $current = $current->next;
        }
        $current->id = $id;
        $current->name = $name;
        $current->major = $major;
    }

    /**
     * Update the last node in the list.
     * @param string $id - The ID of the data.
     * @param string $name - The name of the data.
     * @param string $major - The major associated with the data.
     */
    public function updateLastNode($id, $name, $major) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->tail->id = $id;
        $this->tail->name = $name;
        $this->tail->major = $major;
    }

    /**
     * Remove the first node from the list.
     */
    public function removeFirstNode() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $del = $this->head;
        if ($this->size === 1) {
            $this->head = null;
            $this->tail = null;
        } else {
            $this->head = $this->head->next;
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
        $current = $this->head;
        for ($i = 1; $i < $pos - 1; $i++) {
            $current = $current->next;
        }
        $del = $current->next;
        $current->next = $del->next;
        if ($del == $this->tail) {
            $this->tail = $current;
        }
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
        $del = $this->tail;
        if ($this->size === 1) {
            $this->head = null;
            $this->tail = null;
        } else {
            $current = $this->head;
            while ($current->next !== $this->tail) {
                $current = $current->next;
            }
            $this->tail = $current;
            $this->tail->next = $this->head;
        }
        $this->size--;
    }

    /**
     * Print all nodes in the circular singly linked list.
     */
    public function printCircularSL() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        echo "Number of Nodes: " . $this->size . "\n";
        $current = $this->head;
        $i = 1;
        do {
            echo "Node " . $i . "\n";
            echo "ID\t\t: " . $current->id . "\n";
            echo "Name\t\t: " . $current->name . "\n";
            echo "Major\t\t: " . $current->major . "\n\n";
            $current = $current->next;
            $i++;
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
$list->createCircularSL("11223399", "Arief F-sa", "Computer Science");
$list->printCircularSL();
echo "==========\n\n";

$list->addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
$list->printCircularSL();
echo "==========\n\n";

$list->addAtLastNode("11223400", "Pejeel", "Drop out");
$list->printCircularSL();
echo "==========\n\n";

$list->removeFirstNode();
$list->printCircularSL();
echo "==========\n\n";

$list->removeLastNode();
$list->printCircularSL();
echo "==========\n\n";

$list->addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
$list->addAtLastNode("11223400", "Pejeel", "Drop out");
$list->printCircularSL();
echo "==========\n\n";

$list->addAtNthNode("11223401", "dummy1", "Math", 3);
$list->addAtNthNode("11223402", "dummy2", "Physics", 2);
$list->printCircularSL();
echo "==========\n\n";

$list->removeNthNode(2);
$list->printCircularSL();
echo "==========\n\n";
?>