import java.util.ArrayList;

public class stack {
    private ArrayList<String> data;
    private int capacity;

    public stack(int capacity) {
        this.capacity = capacity;
        this.data = new ArrayList<>(capacity);
    }

    public boolean isFull() {
        return data.size() == capacity;
    }

    public boolean isEmpty() {
        return data.isEmpty();
    }

    public void push(String value) {
        if (isFull()) {
            resize();
        }
        data.add(value);
        System.out.println("Pushed " + value + " onto stack.");
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("stack is EMPTY! Cannot pop.");
            return;
        }
        String poppedValue = data.remove(data.size() - 1);
        System.out.println("Popped " + poppedValue + " from stack.");
    }

    public String topValue() {
        if (isEmpty()) {
            System.out.println("stack is EMPTY! No top value.");
            return null;
        }
        return data.get(data.size() - 1);
    }

    public String peek(int n) {
        if (isEmpty()) {
            System.out.println("stack is EMPTY! No element to peek.");
            return null;
        }
        int index = data.size() - n;
        if (index < 0 || index >= data.size()) {
            System.out.println("Invalid peek(" + n + "). Not enough elements.");
            return null;
        }
        return data.get(index);
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("stack is EMPTY!");
            return;
        }
        System.out.println("stack contents (top -> bottom):");
        for (int i = data.size() - 1; i >= 0; i--) {
            System.out.println("[" + (i + 1) + "]: " + data.get(i));
        }
        System.out.println();
    }

    private void resize() {
        capacity *= 2;
        System.out.println("stack resized.");
    }

    public static void main(String[] args) {
        stack books = new stack(5);

        books.push("Mathematics");
        books.push("Calculus");
        books.push("Physics");
        books.push("Web Design");
        books.push("Data Structure");

        books.display();

        System.out.println("Top of stack: " + books.topValue());
        System.out.println("Peek(2): " + books.peek(2));

        books.pop();

        books.display();
    }
}