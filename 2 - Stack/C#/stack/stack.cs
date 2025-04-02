using System;
using System.Collections.Generic;

public class Stack
{
    private List<string> data;
    private int capacity;

    public Stack(int capacity)
    {
        this.capacity = capacity;
        this.data = new List<string>(capacity);
    }

    public bool IsFull()
    {
        return data.Count == capacity;
    }

    public bool IsEmpty()
    {
        return data.Count == 0;
    }

    public void Push(string value)
    {
        if (IsFull())
        {
            Resize();
        }
        data.Add(value);
        Console.WriteLine($"Pushed {value} onto stack.");
    }

    public void Pop()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is EMPTY! Cannot pop.");
            return;
        }
        string poppedValue = data[data.Count - 1];
        data.RemoveAt(data.Count - 1);
        Console.WriteLine($"Popped {poppedValue} from stack.");
    }

    public string TopValue()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is EMPTY! No top value.");
            return null;
        }
        return data[data.Count - 1];
    }

    public string Peek(int n)
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is EMPTY! No element to peek.");
            return null;
        }
        int index = data.Count - n;
        if (index < 0 || index >= data.Count)
        {
            Console.WriteLine($"Invalid peek({n}). Not enough elements.");
            return null;
        }
        return data[index];
    }

    public void Display()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is EMPTY!");
            return;
        }
        Console.WriteLine("Stack contents (top -> bottom):");
        for (int i = data.Count - 1; i >= 0; i--)
        {
            Console.WriteLine($"[{i + 1}]: {data[i]}");
        }
        Console.WriteLine();
    }

    private void Resize()
    {
        capacity *= 2;
        Console.WriteLine("Stack resized.");
    }

    public static void Main(string[] args)
    {
        Stack books = new Stack(5);

        books.Push("Mathematics");
        books.Push("Calculus");
        books.Push("Physics");
        books.Push("Web Design");
        books.Push("Data Structure");

        books.Display();

        Console.WriteLine($"Top of stack: {books.TopValue()}");
        Console.WriteLine($"Peek(2): {books.Peek(2)}");

        books.Pop();

        books.Display();
    }
}