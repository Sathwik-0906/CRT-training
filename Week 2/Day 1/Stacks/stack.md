# Stack Data Structure

Stacks are a type of linear data structure that follow the **Last In, First Out (LIFO)** principle.

## 📌 Stack Operations

1. **Push** – Insert an element into the stack
2. **Pop** – Remove the top element
3. **Peek** – View the top element

---

## 🖼️ Stack Diagram

Below is an image representation of how a stack works:

![Stack Diagram](images/stack_diagram.png)

> **Figure 1:** A simple diagram showing stack operations

---

## 📜 Code Example (C Language)

```c
#define SIZE 4
int stack[SIZE];
int top = -1;

void push(int ele) {
    if (top == SIZE - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = ele;
}
---