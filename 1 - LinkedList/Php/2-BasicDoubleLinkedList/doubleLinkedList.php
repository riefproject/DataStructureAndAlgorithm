<?php

/**
 * Class representing a node in the doubly linked list.
 */
class Node {
    public $name;
    public $username;
    public $email;
    public $password;
    public $prev;
    public $next;

    /**
     * Create a node.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function __construct($name, $username, $email, $password) {
        $this->name = $name;
        $this->username = $username;
        $this->email = $email;
        $this->password = $password;
        $this->prev = null; // Pointer to the previous node
        $this->next = null; // Pointer to the next node
    }
}

/**
 * Class representing a doubly linked list.
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
     * Create a doubly linked list with the first node.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function createDoubleLinkedList($name, $username, $email, $password) {
        $newNode = new Node($name, $username, $email, $password);
        $this->head = $newNode;
        $this->tail = $newNode;
        $this->size = 1;
    }

    /**
     * Add a node at the beginning of the list.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function addAtFirstNode($name, $username, $email, $password) {
        if ($this->size === 0) {
            $this->createDoubleLinkedList($name, $username, $email, $password);
            return;
        }
        $newNode = new Node($name, $username, $email, $password);
        $newNode->next = $this->head;
        $this->head->prev = $newNode;
        $this->head = $newNode;
        $this->size++;
    }

    /**
     * Add a node at the nth position in the list.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     * @param int $pos - The position to insert the node.
     */
    public function addAtNthNode($name, $username, $email, $password, $pos) {
        if ($pos < 1 || $pos > $this->size + 1) {
            echo "Invalid position!\n";
            return;
        }
        if ($pos == 1) {
            $this->addAtFirstNode($name, $username, $email, $password);
            return;
        }
        if ($pos == $this->size + 1) {
            $this->addAtLastNode($name, $username, $email, $password);
            return;
        }
        $newNode = new Node($name, $username, $email, $password);
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
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function addAtLastNode($name, $username, $email, $password) {
        if ($this->size === 0) {
            $this->createDoubleLinkedList($name, $username, $email, $password);
            return;
        }
        $newNode = new Node($name, $username, $email, $password);
        $newNode->prev = $this->tail;
        $this->tail->next = $newNode;
        $this->tail = $newNode;
        $this->size++;
    }

    /**
     * Update the first node in the list.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function updateFirstNode($name, $username, $email, $password) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->head->name = $name;
        $this->head->username = $username;
        $this->head->email = $email;
        $this->head->password = $password;
    }

    /**
     * Update the nth node in the list.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     * @param int $pos - The position of the node to update.
     */
    public function updateNthNode($name, $username, $email, $password, $pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Invalid position!\n";
            return;
        }
        $current = $this->head;
        for ($i = 1; $i < $pos; $i++) {
            $current = $current->next;
        }
        $current->name = $name;
        $current->username = $username;
        $current->email = $email;
        $current->password = $password;
    }

    /**
     * Update the last node in the list.
     * @param string $name - The name of the data.
     * @param string $username - The username associated with the data.
     * @param string $email - The email associated with the data.
     * @param string $password - The password associated with the data.
     */
    public function updateLastNode($name, $username, $email, $password) {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        $this->tail->name = $name;
        $this->tail->username = $username;
        $this->tail->email = $email;
        $this->tail->password = $password;
    }

    /**
     * Remove the first node from the list.
     */
    public function removeAtFirst() {
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
            $this->head->prev = null;
        }
        $this->size--;
    }

    /**
     * Remove the nth node from the list.
     * @param int $pos - The position of the node to remove.
     */
    public function removeAtNthNode($pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Invalid position!\n";
            return;
        }
        if ($pos == 1) {
            $this->removeAtFirst();
            return;
        }
        if ($pos == $this->size) {
            $this->removeAtLast();
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
    public function removeAtLast() {
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
            $this->tail->next = null;
        }
        $this->size--;
    }

    /**
     * Print all nodes in the doubly linked list.
     */
    public function printDoubleLinkedList() {
        if ($this->size === 0) {
            echo "List is empty!\n";
            return;
        }
        echo "Number of Nodes: " . $this->size . "\n";
        $current = $this->head;
        $i = 1;
        while ($current !== null) {
            echo "Node " . $i . "\n";
            echo "Name\t\t: " . $current->name . "\n";
            echo "Username\t: " . $current->username . "\n";
            echo "Email\t\t: " . $current->email . "\n";
            echo "Password\t: " . $current->password . "\n\n";
            $current = $current->next;
            $i++;
        }
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
$list->createDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->addAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->addAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->removeAtFirst();
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->removeAtLast();
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->addAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
$list->addAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
$list->addAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
$list->addAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
$list->addAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->addAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
$list->printDoubleLinkedList();
echo "==========\n\n";

$list->removeAtNthNode(6);
$list->printDoubleLinkedList();
echo "==========\n\n";
?>