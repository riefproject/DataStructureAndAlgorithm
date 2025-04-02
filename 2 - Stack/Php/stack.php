<?php

class Stack {
    private $data;
    private $capacity;

    public function __construct($capacity) {
        $this->capacity = $capacity;
        $this->data = [];
    }

    public function isFull() {
        return count($this->data) == $this->capacity;
    }

    public function isEmpty() {
        return count($this->data) == 0;
    }

    public function push($value) {
        if ($this->isFull()) {
            $this->resize();
        }
        array_push($this->data, $value);
        echo "Pushed $value onto stack.\n";
    }

    public function pop() {
        if ($this->isEmpty()) {
            echo "Stack is EMPTY! Cannot pop.\n";
            return;
        }
        $poppedValue = array_pop($this->data);
        echo "Popped $poppedValue from stack.\n";
    }

    public function topValue() {
        if ($this->isEmpty()) {
            echo "Stack is EMPTY! No top value.\n";
            return null;
        }
        return end($this->data);
    }

    public function peek($n) {
        if ($this->isEmpty()) {
            echo "Stack is EMPTY! No element to peek.\n";
            return null;
        }
        $index = count($this->data) - $n;
        if ($index < 0 || $index >= count($this->data)) {
            echo "Invalid peek($n). Not enough elements.\n";
            return null;
        }
        return $this->data[$index];
    }

    public function display() {
        if ($this->isEmpty()) {
            echo "Stack is EMPTY!\n";
            return;
        }
        echo "Stack contents (top -> bottom):\n";
        for ($i = count($this->data) - 1; $i >= 0; $i--) {
            echo "[" . ($i + 1) . "]: " . $this->data[$i] . "\n";
        }
        echo "\n";
    }

    private function resize() {
        $this->capacity *= 2;
        echo "Stack resized.\n";
    }
}

$books = new Stack(5);

$books->push("Mathematics");
$books->push("Calculus");
$books->push("Physics");
$books->push("Web Design");
$books->push("Data Structure");

$books->display();

echo "Top of stack: " . $books->topValue() . "\n";
echo "Peek(2): " . $books->peek(2) . "\n";

$books->pop();

$books->display();
?>