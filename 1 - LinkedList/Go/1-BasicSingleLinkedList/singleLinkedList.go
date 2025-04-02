package main

import (
    "fmt"
)

// Node struct representing each element in the singly linked list
type Node struct {
    Title  string // Book title
    Author string // Author of the book
    Year   string // Publication year of the book
    Next   *Node  // Pointer to the next book in the list
}

// LinkedList struct to manage the singly linked list
type LinkedList struct {
    Head *Node // Pointer to the head of the list
    Tail *Node // Pointer to the tail of the list
    Size int   // Size of the list
}

// NewLinkedList function to initialize an empty list
func NewLinkedList() *LinkedList {
    return &LinkedList{nil, nil, 0}
}

// AddNode function to add a node at the end of the linked list
func (list *LinkedList) AddNode(title, author, year string) {
    newBook := &Node{title, author, year, nil} // Create a new node

    if list.Head == nil { // If the list is empty
        list.Head = newBook
        list.Tail = newBook
    } else {
        list.Tail.Next = newBook
        list.Tail = newBook
    }

    list.Size++
}

// AddAtFirstNode function to add a node at the beginning of the linked list
func (list *LinkedList) AddAtFirstNode(title, author, year string) {
    newBook := &Node{title, author, year, nil} // Create a new node

    newBook.Next = list.Head
    list.Head = newBook

    if list.Size == 0 {
        list.Tail = newBook
    }

    list.Size++
}

// AddAtNthNode function to add a node at a specified position in the linked list
func (list *LinkedList) AddAtNthNode(title, author, year string, pos int) {
    if pos < 1 || pos > list.Size+1 { // Validate position
        fmt.Println("Position out of range")
        return
    }
    if pos == 1 { // If adding at the first position
        list.AddAtFirstNode(title, author, year)
        return
    }
    if pos == list.Size+1 { // If adding at the last position
        list.AddNode(title, author, year)
        return
    }

    newBook := &Node{title, author, year, nil} // Create a new node

    // Find the position before where the new book will be inserted
    cur := list.Head
    for i := 1; i < pos-1; i++ {
        cur = cur.Next
    }

    // Insert the new book into the linked list at the specified position
    newBook.Next = cur.Next
    cur.Next = newBook

    list.Size++
}

// UpdateFirstNode function to update the details of the first node in the linked list
func (list *LinkedList) UpdateFirstNode(title, author, year string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }

    // Update book details
    list.Head.Title = title
    list.Head.Author = author
    list.Head.Year = year
}

// UpdateNthNode function to update the details of the nth node in the linked list
func (list *LinkedList) UpdateNthNode(title, author, year string, pos int) {
    if pos < 1 || pos > list.Size { // Validate position
        fmt.Println("Position out of range")
        return
    }
    if pos == 1 { // If updating the first node
        list.UpdateFirstNode(title, author, year)
        return
    }
    if pos == list.Size { // If updating the last node
        list.UpdateLastNode(title, author, year)
        return
    }

    // Normal update at the nth position
    cur := list.Head
    for i := 1; i < pos; i++ { // Traverse to the nth node
        cur = cur.Next
    }

    // Update book details
    cur.Title = title
    cur.Author = author
    cur.Year = year
}

// UpdateLastNode function to update the details of the last node in the linked list
func (list *LinkedList) UpdateLastNode(title, author, year string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }

    // Update book details
    list.Tail.Title = title
    list.Tail.Author = author
    list.Tail.Year = year
}

// RemoveAtFirst function to remove the first node from the linked list
func (list *LinkedList) RemoveAtFirst() {
    if list.Size == 0 {
        return // If the list is empty, do nothing
    }

    list.Head = list.Head.Next // Update the head pointer to the next node

    if list.Size == 1 {
        list.Tail = nil
    }

    list.Size--
}

// RemoveAtNthNode function to remove the nth node from the linked list
func (list *LinkedList) RemoveAtNthNode(pos int) {
    if pos < 1 || pos > list.Size { // Validate position
        fmt.Println("Position out of range")
        return
    }
    if pos == 1 { // If removing the first node
        list.RemoveAtFirst()
        return
    }
    if pos == list.Size { // If removing the last node
        list.RemoveAtLast()
        return
    }

    // Normal removal of the nth node
    cur := list.Head
    var before *Node
    for i := 1; i < pos; i++ {
        before = cur // Keep track of the node before the one to be deleted
        cur = cur.Next
    }

    before.Next = cur.Next // Bypass the node to be deleted

    list.Size--
}

// RemoveAtLast function to remove the last node from the linked list
func (list *LinkedList) RemoveAtLast() {
    if list.Size == 0 {
        return // If the list is empty, do nothing
    }

    if list.Size == 1 { // If there's only one node
        list.Head = nil
        list.Tail = nil
        list.Size--
        return
    }

    // Find the second last node
    cur := list.Head
    for cur.Next != list.Tail {
        cur = cur.Next
    }

    list.Tail = cur // Update the tail pointer
    list.Tail.Next = nil

    list.Size--
}

// PrintSingleLinkedList function to print all nodes in the linked list
func (list *LinkedList) PrintSingleLinkedList() {
    fmt.Printf("Number of Nodes: %d\n", list.Size) // Display the total number of nodes
    cur := list.Head
    i := 1
    for cur != nil {
        fmt.Printf("NODE %d\n", i)                // Print node number
        fmt.Printf("Title\t: %s\n", cur.Title)    // Print the title of the book
        fmt.Printf("Author\t: %s\n", cur.Author)  // Print the author of the book
        fmt.Printf("Year\t: %s\n\n", cur.Year)    // Print the publication year of the book
        cur = cur.Next                            // Move to the next node
        i++
    }
}

// CountNodes utility function to count the number of nodes in the linked list
func (list *LinkedList) CountNodes() int {
    return list.Size // Return the total number of nodes
}

func main() {
    list := NewLinkedList()

    // Adding and printing nodes to demonstrate linked list operations
    list.AddNode("Introduction to C", "Arief", "2022")
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")

    list.AddAtFirstNode("Chemistry", "Wijaya", "2019")
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")

    list.AddNode("Physics", "Nisa", "2024")
    list.AddNode("Introduction to Python", "Arief", "2023")
    list.AddAtNthNode("F1 For Child", "Anomali", "2000", 2)
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")

    // Removing nodes and updating information to show dynamic modifications
    list.RemoveAtFirst()
    list.PrintSingleLinkedList()
    list.UpdateFirstNode("Introduction to C++", "Arief", "2022")
    fmt.Println("=========\n")

    list.RemoveAtLast()
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")

    list.RemoveAtNthNode(2)
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")

    list.AddNode("Introduction to Kotlin", "Arief", "2023")
    list.UpdateNthNode("Math", "Nisa", "2024", 2)
    list.PrintSingleLinkedList()
    fmt.Println("=========\n")
}