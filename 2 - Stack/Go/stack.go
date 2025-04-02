package main

import (
    "fmt"
)

type Stack struct {
    data []string
    capacity int
}

func NewStack(capacity int) *Stack {
    return &Stack{
        data: make([]string, 0, capacity),
        capacity: capacity,
    }
}

func (s *Stack) IsFull() bool {
    return len(s.data) == s.capacity
}

func (s *Stack) IsEmpty() bool {
    return len(s.data) == 0
}

func (s *Stack) Push(value string) {
    if s.IsFull() {
        s.resize()
    }
    s.data = append(s.data, value)
    fmt.Printf("Pushed %s onto stack.\n", value)
}

func (s *Stack) Pop() {
    if s.IsEmpty() {
        fmt.Println("Stack is EMPTY! Cannot pop.")
        return
    }
    poppedValue := s.data[len(s.data)-1]
    s.data = s.data[:len(s.data)-1]
    fmt.Printf("Popped %s from stack.\n", poppedValue)
}

func (s *Stack) TopValue() string {
    if s.IsEmpty() {
        fmt.Println("Stack is EMPTY! No top value.")
        return ""
    }
    return s.data[len(s.data)-1]
}

func (s *Stack) Peek(n int) string {
    if s.IsEmpty() {
        fmt.Println("Stack is EMPTY! No element to peek.")
        return ""
    }
    index := len(s.data) - n
    if index < 0 || index >= len(s.data) {
        fmt.Printf("Invalid peek(%d). Not enough elements.\n", n)
        return ""
    }
    return s.data[index]
}

func (s *Stack) Display() {
    if s.IsEmpty() {
        fmt.Println("Stack is EMPTY!")
        return
    }
    fmt.Println("Stack contents (top -> bottom):")
    for i := len(s.data) - 1; i >= 0; i-- {
        fmt.Printf("[%d]: %s\n", i+1, s.data[i])
    }
    fmt.Println()
}

func (s *Stack) resize() {
    s.capacity *= 2
    fmt.Println("Stack resized.")
}

func main() {
    books := NewStack(5)

    books.Push("Mathematics")
    books.Push("Calculus")
    books.Push("Physics")
    books.Push("Web Design")
    books.Push("Data Structure")

    books.Display()

    fmt.Printf("Top of stack: %s\n", books.TopValue())
    fmt.Printf("Peek(2): %s\n", books.Peek(2))

    books.Pop()

    books.Display()
}