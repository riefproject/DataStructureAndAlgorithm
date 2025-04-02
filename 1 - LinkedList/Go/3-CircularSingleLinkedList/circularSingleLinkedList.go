package main

import (
    "fmt"
)

// Node struct representing each element in the circular singly linked list
type Node struct {
    ID    string // Student ID
    Name  string // Student name
    Major string // Student major
    Next  *Node  // Pointer to the next node in the list
}

// LinkedList struct to manage the circular singly linked list
type LinkedList struct {
    Head *Node // Pointer to the head of the list
    Tail *Node // Pointer to the tail of the list
    Size int   // Size of the list
}

// NewLinkedList function to initialize an empty list
func NewLinkedList() *LinkedList {
    return &LinkedList{nil, nil, 0}
}

// CreateCircularSL function to create a circular singly linked list with the first node
func (list *LinkedList) CreateCircularSL(id, name, major string) {
    newNode := &Node{id, name, major, nil}
    newNode.Next = newNode
    list.Head = newNode
    list.Tail = newNode
    list.Size = 1
}

// AddAtFirstNode function to add a node at the beginning of the list
func (list *LinkedList) AddAtFirstNode(id, name, major string) {
    if list.Size == 0 {
        list.CreateCircularSL(id, name, major)
        return
    }
    newNode := &Node{id, name, major, list.Head}
    list.Tail.Next = newNode
    list.Head = newNode
    list.Size++
}

// AddAtNthNode function to add a node at the nth position in the list
func (list *LinkedList) AddAtNthNode(id, name, major string, pos int) {
    if pos < 1 || pos > list.Size+1 {
        fmt.Println("Invalid position!")
        return
    }
    if pos == 1 {
        list.AddAtFirstNode(id, name, major)
        return
    }
    if pos == list.Size+1 {
        list.AddAtLastNode(id, name, major)
        return
    }
    newNode := &Node{id, name, major, nil}
    cur := list.Head
    for i := 1; i < pos-1; i++ {
        cur = cur.Next
    }
    newNode.Next = cur.Next
    cur.Next = newNode
    list.Size++
}

// AddAtLastNode function to add a node at the end of the list
func (list *LinkedList) AddAtLastNode(id, name, major string) {
    if list.Size == 0 {
        list.CreateCircularSL(id, name, major)
        return
    }
    newNode := &Node{id, name, major, list.Head}
    list.Tail.Next = newNode
    list.Tail = newNode
    list.Size++
}

// UpdateFirstNode function to update the first node in the list
func (list *LinkedList) UpdateFirstNode(id, name, major string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    list.Head.ID = id
    list.Head.Name = name
    list.Head.Major = major
}

// UpdateNthNode function to update the nth node in the list
func (list *LinkedList) UpdateNthNode(id, name, major string, pos int) {
    if pos < 1 || pos > list.Size {
        fmt.Println("Invalid position!")
        return
    }
    cur := list.Head
    for i := 1; i < pos; i++ {
        cur = cur.Next
    }
    cur.ID = id
    cur.Name = name
    cur.Major = major
}

// UpdateLastNode function to update the last node in the list
func (list *LinkedList) UpdateLastNode(id, name, major string) {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    list.Tail.ID = id
    list.Tail.Name = name
    list.Tail.Major = major
}

// RemoveFirstNode function to remove the first node from the list
func (list *LinkedList) RemoveFirstNode() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    if list.Size == 1 {
        list.Head = nil
        list.Tail = nil
    } else {
        list.Head = list.Head.Next
        list.Tail.Next = list.Head
    }
    list.Size--
}

// RemoveNthNode function to remove the nth node from the list
func (list *LinkedList) RemoveNthNode(pos int) {
    if pos < 1 || pos > list.Size {
        fmt.Println("Invalid position!")
        return
    }
    if pos == 1 {
        list.RemoveFirstNode()
        return
    }
    cur := list.Head
    for i := 1; i < pos-1; i++ {
        cur = cur.Next
    }
    cur.Next = cur.Next.Next
    if pos == list.Size {
        list.Tail = cur
    }
    list.Size--
}

// RemoveLastNode function to remove the last node from the list
func (list *LinkedList) RemoveLastNode() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    if list.Size == 1 {
        list.Head = nil
        list.Tail = nil
    } else {
        cur := list.Head
        for cur.Next != list.Tail {
            cur = cur.Next
        }
        list.Tail = cur
        list.Tail.Next = list.Head
    }
    list.Size--
}

// PrintCircularSL function to print the circular singly linked list
func (list *LinkedList) PrintCircularSL() {
    if list.Size == 0 {
        fmt.Println("List is empty!")
        return
    }
    fmt.Printf("Number of Nodes: %d\n", list.CountNodes()) // Display the total number of nodes
    cur := list.Head
    i := 1
    for {
        fmt.Printf("Node %d\n", i)
        fmt.Printf("ID\t\t: %s\n", cur.ID)
        fmt.Printf("Name\t\t: %s\n", cur.Name)
        fmt.Printf("Major\t\t: %s\n\n", cur.Major)
        cur = cur.Next
        i++
        if cur == list.Head {
            break
        }
    }
}

// CountNodes utility function to count the number of nodes in the list
func (list *LinkedList) CountNodes() int {
    return list.Size // Return the total number of nodes
}

func main() {
    list := NewLinkedList()

    // Create the circular singly linked list with the first node
    list.CreateCircularSL("11223399", "Arief F-sa", "Computer Science")
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Add a node at the beginning of the list
    list.AddAtFirstNode("11223398", "Nisa Uswa", "Psychology")
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Add a node at the end of the list
    list.AddAtLastNode("11223400", "Pejeel", "Drop out")
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Remove the first node from the list
    list.RemoveFirstNode()
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Remove the last node from the list
    list.RemoveLastNode()
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Add nodes at the beginning and end of the list
    list.AddAtFirstNode("11223398", "Nisa Uswa", "Psychology")
    list.AddAtLastNode("11223400", "Pejeel", "Drop out")
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Add nodes at specific positions in the list
    list.AddAtNthNode("11223401", "dummy1", "Math", 3)
    list.AddAtNthNode("11223402", "dummy2", "Physics", 2)
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")

    // Remove the node at the specified position in the list
    list.RemoveNthNode(2)
    list.PrintCircularSL()
    fmt.Println("==========\n\n\n")
}