#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
private:
    vector<string> data;
    int capacity;

    void resize() {
        capacity *= 2;
        cout << "Stack resized." << endl;
    }

public:
    Stack(int capacity) : capacity(capacity) {
        data.reserve(capacity);
    }

    bool isFull() const {
        return data.size() == capacity;
    }

    bool isEmpty() const {
        return data.empty();
    }

    void push(const string& value) {
        if (isFull()) {
            resize();
        }
        data.push_back(value);
        cout << "Pushed " << value << " onto stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is EMPTY! Cannot pop." << endl;
            return;
        }
        string poppedValue = data.back();
        data.pop_back();
        cout << "Popped " << poppedValue << " from stack." << endl;
    }

    string topValue() const {
        if (isEmpty()) {
            cout << "Stack is EMPTY! No top value." << endl;
            return "";
        }
        return data.back();
    }

    string peek(int n) const {
        if (isEmpty()) {
            cout << "Stack is EMPTY! No element to peek." << endl;
            return "";
        }
        int index = data.size() - n;
        if (index < 0 || index >= data.size()) {
            cout << "Invalid peek(" << n << "). Not enough elements." << endl;
            return "";
        }
        return data[index];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Stack contents (top -> bottom):" << endl;
        for (int i = data.size() - 1; i >= 0; --i) {
            cout << "[" << i + 1 << "]: " << data[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Stack books(5);

    books.push("Mathematics");
    books.push("Calculus");
    books.push("Physics");
    books.push("Web Design");
    books.push("Data Structure");

    books.display();

    cout << "Top of stack: " << books.topValue() << endl;
    cout << "Peek(2): " << books.peek(2) << endl;

    books.pop();

    books.display();

    return 0;
}