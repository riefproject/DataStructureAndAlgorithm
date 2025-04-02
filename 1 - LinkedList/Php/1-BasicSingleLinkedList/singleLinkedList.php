<?php

/**
 * Class representing a node in the singly linked list.
 */
class Node {
    public $title;
    public $author;
    public $year;
    public $next;

    /**
     * Create a node.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     */
    public function __construct($title, $author, $year) {
        $this->title = $title;
        $this->author = $author;
        $this->year = $year;
        $this->next = null; // Pointer to the next node
    }
}

/**
 * Class representing a singly linked list.
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
     * Add a node at the end of the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     */
    public function addNode($title, $author, $year) {
        $newBook = new Node($title, $author, $year);

        if ($this->head === null) {
            $this->head = $newBook;
            $this->tail = $newBook;
        } else {
            $this->tail->next = $newBook;
            $this->tail = $newBook;
        }

        $this->size++;
    }

    /**
     * Add a node at the beginning of the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     */
    public function addAtFirstNode($title, $author, $year) {
        $newBook = new Node($title, $author, $year);

        if ($this->head === null) {
            $this->head = $newBook;
            $this->tail = $newBook;
        } else {
            $newBook->next = $this->head;
            $this->head = $newBook;
        }

        $this->size++;
    }

    /**
     * Add a node at a specified position in the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     * @param int $pos - The position to insert the node.
     */
    public function addAtNthNode($title, $author, $year, $pos) {
        if ($pos < 1 || $pos > $this->size + 1) {
            echo "Position out of range\n";
            return;
        }

        if ($pos == 1) {
            $this->addAtFirstNode($title, $author, $year);
            return;
        }

        if ($pos == $this->size + 1) {
            $this->addNode($title, $author, $year);
            return;
        }

        $newBook = new Node($title, $author, $year);
        $current = $this->head;

        for ($i = 1; $i < $pos - 1; $i++) {
            $current = $current->next;
        }

        $newBook->next = $current->next;
        $current->next = $newBook;

        $this->size++;
    }

    /**
     * Update the details of the first node in the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     */
    public function updateFirstNode($title, $author, $year) {
        if ($this->size == 0) {
            echo "List is empty!\n";
            return;
        }

        $this->head->title = $title;
        $this->head->author = $author;
        $this->head->year = $year;
    }

    /**
     * Update the details of the nth node in the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     * @param int $pos - The position of the node to update.
     */
    public function updateNthNode($title, $author, $year, $pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Position out of range\n";
            return;
        }

        if ($pos == 1) {
            $this->updateFirstNode($title, $author, $year);
            return;
        }

        $current = $this->head;

        for ($i = 1; $i < $pos; $i++) {
            $current = $current->next;
        }

        $current->title = $title;
        $current->author = $author;
        $current->year = $year;
    }

    /**
     * Update the details of the last node in the linked list.
     * @param string $title - The title of the book.
     * @param string $author - The author of the book.
     * @param string $year - The publication year of the book.
     */
    public function updateLastNode($title, $author, $year) {
        if ($this->size == 0) {
            echo "List is empty!\n";
            return;
        }

        $this->tail->title = $title;
        $this->tail->author = $author;
        $this->tail->year = $year;
    }

    /**
     * Remove the first node from the linked list.
     */
    public function removeAtFirst() {
        if ($this->size == 0) {
            return;
        }

        $this->head = $this->head->next;

        if ($this->size == 1) {
            $this->tail = null;
        }

        $this->size--;
    }

    /**
     * Remove the nth node from the linked list.
     * @param int $pos - The position of the node to remove.
     */
    public function removeAtNthNode($pos) {
        if ($pos < 1 || $pos > $this->size) {
            echo "Position out of range\n";
            return;
        }

        if ($pos == 1) {
            $this->removeAtFirst();
            return;
        }

        $current = $this->head;
        $before = null;

        for ($i = 1; $i < $pos; $i++) {
            $before = $current;
            $current = $current->next;
        }

        $before->next = $current->next;

        if ($pos == $this->size) {
            $this->tail = $before;
        }

        $this->size--;
    }

    /**
     * Remove the last node from the linked list.
     */
    public function removeAtLast() {
        if ($this->size == 0) {
            return;
        }

        if ($this->size == 1) {
            $this->head = null;
            $this->tail = null;
            $this->size--;
            return;
        }

        $current = $this->head;

        while ($current->next !== $this->tail) {
            $current = $current->next;
        }

        $this->tail = $current;
        $this->tail->next = null;
        $this->size--;
    }

    /**
     * Print all nodes in the singly linked list.
     */
    public function printSingleLinkedList() {
        echo "Number of Nodes: " . $this->size . "\n";
        $current = $this->head;
        $i = 1;

        while ($current !== null) {
            echo "NODE " . $i . "\n";
            echo "Title\t: " . $current->title . "\n";
            echo "Author\t: " . $current->author . "\n";
            echo "Year\t: " . $current->year . "\n\n";
            $current = $current->next;
            $i++;
        }
    }

    /**
     * Utility function to count the number of nodes in the linked list.
     * @return int The total number of nodes.
     */
    public function countNodes() {
        return $this->size;
    }
}

// Example usage
$list = new LinkedList();
$list->addNode("Introduction to C", "Arief", "2022");
$list->printSingleLinkedList();
echo "=========\n\n";

$list->addAtFirstNode("Chemistry", "Wijaya", "2019");
$list->printSingleLinkedList();
echo "=========\n\n";

$list->addNode("Physics", "Nisa", "2024");
$list->addNode("Introduction to Python", "Arief", "2023");
$list->addAtNthNode("F1 For Child", "Anomali", "2000", 2);
$list->printSingleLinkedList();
echo "=========\n\n";

$list->removeAtFirst();
$list->printSingleLinkedList();
$list->updateFirstNode("Introduction to C++", "Arief", "2022");
echo "=========\n\n";

$list->removeAtLast();
$list->printSingleLinkedList();
echo "=========\n\n";

$list->removeAtNthNode(2);
$list->printSingleLinkedList();
echo "=========\n\n";

$list->addNode("Introduction to Kotlin", "Arief", "2023");
$list->updateNthNode("Math", "Nisa", "2024", 2);
$list->printSingleLinkedList();
echo "=========\n\n";
?>