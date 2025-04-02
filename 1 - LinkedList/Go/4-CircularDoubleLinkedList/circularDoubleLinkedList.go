package main

import (
	"fmt"
)

// Node struct representing each element in the circular doubly linked list
type Node struct {
	Name      string // Item name
	Price     int    // Item price
	Available int    // Item availability
	Prev      *Node  // Pointer to the previous node in the list
	Next      *Node  // Pointer to the next node in the list
}

// LinkedList struct to manage the circular doubly linked list
type LinkedList struct {
	Head *Node // Pointer to the head of the list
	Tail *Node // Pointer to the tail of the list
	Size int   // Size of the list
}

// NewLinkedList function to initialize an empty list
func NewLinkedList() *LinkedList {
	return &LinkedList{nil, nil, 0}
}

// CreateCircularDL function to create a circular doubly linked list with the first node
func (list *LinkedList) CreateCircularDL(name string, price int, available int) {
	newNode := &Node{name, price, available, nil, nil}
	newNode.Next = newNode
	newNode.Prev = newNode
	list.Head = newNode
	list.Tail = newNode
	list.Size = 1
}

// AddAtFirstNode function to add a node at the beginning of the list
func (list *LinkedList) AddAtFirstNode(name string, price int, available int) {
	if list.Size == 0 {
		list.CreateCircularDL(name, price, available)
		return
	}
	newNode := &Node{name, price, available, list.Tail, list.Head}
	list.Head.Prev = newNode
	list.Tail.Next = newNode
	list.Head = newNode
	list.Size++
}

// AddAtNthNode function to add a node at the nth position in the list
func (list *LinkedList) AddAtNthNode(name string, price int, available int, pos int) {
	if pos < 1 || pos > list.Size+1 {
		fmt.Printf("Invalid position!")
		return
	}
	if pos == 1 {
		list.AddAtFirstNode(name, price, available)
		return
	}
	if pos == list.Size+1 {
		list.AddAtLastNode(name, price, available)
		return
	}
	newNode := &Node{name, price, available, nil, nil}
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
func (list *LinkedList) AddAtLastNode(name string, price int, available int) {
	if list.Size == 0 {
		list.CreateCircularDL(name, price, available)
		return
	}
	newNode := &Node{name, price, available, list.Tail, list.Head}
	list.Tail.Next = newNode
	list.Head.Prev = newNode
	list.Tail = newNode
	list.Size++
}

// UpdateFirstNode function to update the first node in the list
func (list *LinkedList) UpdateFirstNode(name string, price int, available int) {
	if list.Size == 0 {
		fmt.Printf("List is empty!")
		return
	}
	list.Head.Name = name
	list.Head.Price = price
	list.Head.Available = available
}

// UpdateNthNode function to update the nth node in the list
func (list *LinkedList) UpdateNthNode(name string, price int, available int, pos int) {
	if pos < 1 || pos > list.Size {
		fmt.Printf("Invalid position!")
		return
	}
	cur := list.Head
	for i := 1; i < pos; i++ {
		cur = cur.Next
	}
	cur.Name = name
	cur.Price = price
	cur.Available = available
}

// UpdateLastNode function to update the last node in the list
func (list *LinkedList) UpdateLastNode(name string, price int, available int) {
	if list.Size == 0 {
		fmt.Printf("List is empty!")
		return
	}
	list.Tail.Name = name
	list.Tail.Price = price
	list.Tail.Available = available
}

// RemoveFirstNode function to remove the first node from the list
func (list *LinkedList) RemoveFirstNode() {
	if list.Size == 0 {
		fmt.Printf("List is empty!")
		return
	}
	if list.Size == 1 {
		list.Head = nil
		list.Tail = nil
	} else {
		list.Head = list.Head.Next
		list.Head.Prev = list.Tail
		list.Tail.Next = list.Head
	}
	list.Size--
}

// RemoveNthNode function to remove the nth node from the list
func (list *LinkedList) RemoveNthNode(pos int) {
	if pos < 1 || pos > list.Size {
		fmt.Printf("Invalid position!")
		return
	}
	if pos == 1 {
		list.RemoveFirstNode()
		return
	}
	if pos == list.Size {
		list.RemoveLastNode()
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

// RemoveLastNode function to remove the last node from the list
func (list *LinkedList) RemoveLastNode() {
	if list.Size == 0 {
		fmt.Printf("List is empty!")
		return
	}
	if list.Size == 1 {
		list.Head = nil
		list.Tail = nil
	} else {
		list.Tail = list.Tail.Prev
		list.Tail.Next = list.Head
		list.Head.Prev = list.Tail
	}
	list.Size--
}

// PrintCircularDL function to print the circular doubly linked list
func (list *LinkedList) PrintCircularDL() {
	if list.Size == 0 {
		fmt.Printf("List is empty!")
		return
	}
	cur := list.Head
	for i := 0; i < list.Size; i++ {
		fmt.Printf("Name: %s, Price: %d, Available: %d\n", cur.Name, cur.Price, cur.Available)
		cur = cur.Next
	}
}

// CountNodes utility function to count the number of nodes in the list
func (list *LinkedList) CountNodes() int {
	return list.Size // Return the total number of nodes
}

func main() {
	list := NewLinkedList()

	// Create the circular doubly linked list with the first node
	list.CreateCircularDL("Laptop", 20000000, 20)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Add a node at the beginning of the list
	list.AddAtFirstNode("Handphone", 5000000, 50)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Add nodes at the end of the list
	list.AddAtLastNode("Mouse", 1200000, 100)
	list.AddAtLastNode("Keyboard", 2250000, 100)
	list.AddAtLastNode("Headphone", 1800000, 100)
	list.AddAtLastNode("Monitor", 4200000, 100)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Remove the first node from the list
	list.RemoveFirstNode()
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Remove the last node from the list
	list.RemoveLastNode()
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Add a node at the nth position in the list
	list.AddAtNthNode("RTX 5090", 40000000, 15, 3)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Remove the nth node from the list
	list.RemoveNthNode(4)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Update the first node in the list
	list.UpdateFirstNode("Laptop", 19000000, 10)
	// Update the nth node in the list
	list.UpdateNthNode("Mouse", 1000000, 3, 2)
	// Update the last node in the list
	list.UpdateLastNode("Headphone", 1900000, 5)
	list.PrintCircularDL()
	fmt.Printf("==========\n\n\n")

	// Print the total number of nodes in the list
	fmt.Printf("Total nodes: %d\n", list.CountNodes())
}
