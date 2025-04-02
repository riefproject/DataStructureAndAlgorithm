package main

import (
    "fmt"
)

// Node struct representing each element in the doubly linked list
type Node struct {
    Name     string // Data title
    Username string // Author of the data
    Email    string // Author of the data
    Password string // Publication year of the data
    Prev     *Node  // Pointer to the previous data in the list
    Next     *Node  // Pointer to the next data in the list
}

// LinkedList struct to manage the doubly linked list
type LinkedList struct {
    Head *Node // Pointer to the head of the list
    Tail *Node // Pointer to the tail of the list
    Size int   // Size of the list
}

// NewLinkedList function to initialize an empty list
func NewLinkedList() *LinkedList {
    return &LinkedList{nil, nil, 0}
}

// CreateDoubleLinkedList function to create a doubly linked list with the first node
func (list *LinkedList) CreateDoubleLinkedList(name, username, email, password string) {
    newNode := &Node{name, username, email, password, nil, nil}
    list.Head = newNode
    list.Tail = newNode
    list.Size = 1
}

// AddAtFirstNode function to add a node at the beginning of the list
func (list *LinkedList) AddAtFirstNode(name, username, email, password string) {
    if list.Size == 0 {
        list.CreateDoubleLinkedList(name, username, email, password)
        return
    }
    newNode := &Node{name, username, email, password, nil, list.Head}
    list.Head.Prev = newNode
    list.Head = newNode
    list.Size++
}

// AddAtNthNode function to add a node at the nth position in the list
func (list *LinkedList) AddAtNthNode(name, username, email, password string, pos int) {
    if pos < 1 || pos > list.Size+1 {
        fmt.Println("Invalid position!")
        return
    }
    if pos == 1 {
        list.AddAtFirstNode(name, username, email, password)
        return
    }
    if pos == list.Size+1 {
        list.AddAtLastNode(name, username, email, password)
        return
    }
    newNode := &Node{name, username, email, password, nil, nil}
    cur := list.Head
    for i := 1; i < pos-1; i++ {
        cur = cur.Next
    }
    newNode.Next = cur.Next
    newNode.Prev = cur
    cur.Next.Prev = newNode
    cur.Next = newNode
    list.Size++
}

// AddAtLastNode function to add a node at the end of the list
func (list *LinkedList) AddAtLastNode(name, username, email, password string) {
    if list.Size == 0 {
        list.CreateDoubleLinkedList(name, username, email, password)
        return
    }
    newNode := &Node{name, username, email, password, list.Tail, nil}
    list.Tail.Next = newNode
    list.Tail = newNode
    list.Size++
}

// UpdateFirstNode function to update the first node in the list
func (list *LinkedList) UpdateFirstNode(name, username, email, password string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    list.Head.Name = name
    list.Head.Username = username
    list.Head.Email = email
    list.Head.Password = password
}

// UpdateNthNode function to update the nth node in the list
func (list *LinkedList) UpdateNthNode(name, username, email, password string, pos int) {
    if pos < 1 || pos > list.Size {
        fmt.Println("Invalid position!")
        return
    }
    cur := list.Head
    for i := 1; i < pos; i++ {
        cur = cur.Next
    }
    cur.Name = name
    cur.Username = username
    cur.Email = email
    cur.Password = password
}

// UpdateLastNode function to update the last node in the list
func (list *LinkedList) UpdateLastNode(name, username, email, password string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    list.Tail.Name = name
    list.Tail.Username = username
    list.Tail.Email = email
    list.Tail.Password = password
}

// RemoveAtFirst function to remove the first node from the list
func (list *LinkedList) RemoveAtFirst() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    if list.Size == 1 {
        list.Head = nil
        list.Tail = nil
    } else {
        list.Head = list.Head.Next
        list.Head.Prev = nil
    }
    list.Size--
}

// RemoveAtNthNode function to remove the nth node from the list
func (list *LinkedList) RemoveAtNthNode(pos int) {
    if pos < 1 || pos > list.Size {
        fmt.Println("Invalid position!")
        return
    }
    if pos == 1 {
        list.RemoveAtFirst()
        return
    }
    if pos == list.Size {
        list.RemoveAtLast()
        return
    }
    cur := list.Head
    for i := 1; i < pos; i++ {
        cur = cur.Next
    }
    cur.Prev.Next = cur.Next
    cur.Next.Prev = cur.Prev
    list.Size--
}

// RemoveAtLast function to remove the last node from the list
func (list *LinkedList) RemoveAtLast() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    if list.Size == 1 {
        list.Head = nil
        list.Tail = nil
    } else {
        list.Tail = list.Tail.Prev
        list.Tail.Next = nil
    }
    list.Size--
}

// PrintDoubleLinkedList function to print the doubly linked list
func (list *LinkedList) PrintDoubleLinkedList() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    fmt.Printf("Number of Nodes: %d\n", list.CountNodes()) // Display the total number of nodes
    cur := list.Head
    i := 1
    for cur != nil {
        fmt.Printf("Node %d\n", i)
        fmt.Printf("Name\t\t: %s\n", cur.Name)
        fmt.Printf("Username\t: %s\n", cur.Username)
        fmt.Printf("Email\t\t: %s\n", cur.Email)
        fmt.Printf("Password\t: %s\n\n", cur.Password)
        cur = cur.Next
        i++
    }
}

// CountNodes utility function to count the number of nodes in the list
func (list *LinkedList) CountNodes() int {
    return list.Size // Return the total number of nodes
}

func main() {
    list := NewLinkedList()

    // Create the doubly linked list with the first node
    list.CreateDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123")
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Add a node at the end of the list
    list.AddAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123")
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Add a node at the beginning of the list
    list.AddAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123")
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Remove the first node from the list
    list.RemoveAtFirst()
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Remove the last node from the list
    list.RemoveAtLast()
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Add multiple nodes at the beginning of the list
    list.AddAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123")
    list.AddAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123")
    list.AddAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123")
    list.AddAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123")
    list.AddAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123")
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Add a node at the nth position in the list
    list.AddAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5)
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")

    // Remove the nth node from the list
    list.RemoveAtNthNode(6)
    list.PrintDoubleLinkedList()
    fmt.Println("==========\n\n\n")
}