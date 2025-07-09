#  Stack Notes:


## 🎯 Introduction

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. Think of it like a stack of plates - you can only add or remove plates from the top.

### Key Characteristics:
- **Linear**: Elements are arranged in a sequential order
- **LIFO**: Last element added is the first to be removed
- **Restricted Access**: Can only access the top element
- **Dynamic**: Size can change during runtime

---

## 🏗️ Stack Fundamentals

### Abstract Data Type (ADT)
```
Stack ADT Operations:
├── push(item)     → Add item to top
├── pop()          → Remove and return top item
├── peek()/top()   → View top item without removing
├── isEmpty()      → Check if stack is empty
├── size()         → Get number of elements
└── isFull()       → Check if stack is full (array implementation)
```

### Visual Representation
```
Stack Growth Direction: ↑

    │   │  ← Top (Stack Pointer)
    │ 5 │
    │ 3 │
    │ 7 │
    │ 1 │  ← Bottom
    └───┘
```

---

## 💾 Memory Management

### 1. Stack Memory Layout

#### Call Stack (System Stack)
```
High Memory Address
┌─────────────────┐
│  Stack Frame n  │ ← Stack Pointer (SP)
├─────────────────┤
│  Stack Frame 2  │
├─────────────────┤
│  Stack Frame 1  │
├─────────────────┤
│  Stack Frame 0  │ ← Base Pointer (BP)
└─────────────────┘
Low Memory Address
```

#### Stack Frame Structure
```
┌─────────────────┐
│ Return Address  │
├─────────────────┤
│ Previous BP     │
├─────────────────┤
│ Local Variables │
├─────────────────┤
│ Parameters      │
├─────────────────┤
│ Saved Registers │
└─────────────────┘
```

### 2. Memory Allocation Types

#### Static Allocation (Array-based Stack)
```cpp
class StaticStack {
private:
    int arr[MAX_SIZE];  // Fixed size allocated at compile time
    int top;            // Index of top element
    
public:
    // Memory allocated on stack/data segment
    // Size: MAX_SIZE * sizeof(int) + sizeof(int)
    // Lifetime: Program duration or scope
};
```

#### Dynamic Allocation (Linked List Stack)
```cpp
struct Node {
    int data;           // 4 bytes
    Node* next;         // 8 bytes (64-bit system)
};                      // Total: 12 bytes + padding = 16 bytes

class DynamicStack {
private:
    Node* top;          // 8 bytes pointer
    int size;           // 4 bytes
    
    // Each node allocated on heap
    // Memory grows/shrinks with operations
};
```

### 3. Memory Management Strategies

#### Garbage Collection Impact
```
Stack Memory Pattern:
┌─────────────────┐
│ Active Frames   │ ← Current execution
├─────────────────┤
│ Inactive Frames │ ← Waiting for return
├─────────────────┤
│ Free Space      │ ← Available for new frames
└─────────────────┘

Heap Memory Pattern (Dynamic Stack):
Node₁ → Node₂ → Node₃ → NULL
  ↑       ↑       ↑
  │       │       └─ Recently allocated
  │       └─ May be fragmented
  └─ Oldest allocation
```

#### Memory Efficiency Comparison
| Implementation | Memory Usage | Allocation Speed | Deallocation Speed |
|----------------|--------------|------------------|-------------------|
| Array-based    | O(n) fixed   | O(1)            | O(1)              |
| Linked List    | O(n) dynamic | O(1)            | O(1)              |
| Vector-based   | O(n) dynamic | Amortized O(1)  | O(1)              |

---

## 🔧 Stack Operations

### 1. Core Operations Implementation

#### Array-based Implementation
```cpp
class ArrayStack {
private:
    int* arr;
    int capacity;
    int top;
    
public:
    ArrayStack(int size) : capacity(size), top(-1) {
        arr = new int[capacity];
    }
    
    void push(int x) {
        if (top >= capacity - 1) {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = x;
    }
    
    int pop() {
        if (top < 0) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top--];
    }
    
    int peek() {
        if (top < 0) {
            throw underflow_error("Stack Empty");
        }
        return arr[top];
    }
};
```

#### Linked List Implementation
```cpp
class LinkedStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };
    Node* topNode;
    int size;
    
public:
    LinkedStack() : topNode(nullptr), size(0) {}
    
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }
    
    int pop() {
        if (!topNode) {
            throw underflow_error("Stack Empty");
        }
        Node* temp = topNode;
        int value = temp->data;
        topNode = topNode->next;
        delete temp;
        size--;
        return value;
    }
};
```

### 2. Advanced Operations

#### Bulk Operations
```cpp
void pushMultiple(vector<int>& items) {
    for (int item : items) {
        push(item);
    }
}

vector<int> popMultiple(int count) {
    vector<int> result;
    for (int i = 0; i < count && !isEmpty(); i++) {
        result.push_back(pop());
    }
    return result;
}
```

#### Stack Manipulation
```cpp
void reverse() {
    if (isEmpty()) return;
    
    int item = pop();
    reverse();
    insertAtBottom(item);
}

void insertAtBottom(int item) {
    if (isEmpty()) {
        push(item);
        return;
    }
    
    int temp = pop();
    insertAtBottom(item);
    push(temp);
}
```

---

## 🎯 Applications

### 1. Expression Evaluation

#### Infix to Postfix Conversion
```cpp
string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
    
    return postfix;
}
```

### 2. Balanced Parentheses
```cpp
bool isBalanced(string s) {
    stack<char> brackets;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) return false;
            
            char top = brackets.top();
            brackets.pop();
            
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return brackets.empty();
}
```

### 3. Function Call Management
```cpp
class CallStack {
private:
    struct StackFrame {
        string functionName;
        map<string, int> localVariables;
        int returnAddress;
        
        StackFrame(string name, int addr) : 
            functionName(name), returnAddress(addr) {}
    };
    
    stack<StackFrame> frames;
    
public:
    void enterFunction(string name, int returnAddr) {
        frames.push(StackFrame(name, returnAddr));
    }
    
    void exitFunction() {
        if (!frames.empty()) {
            frames.pop();
        }
    }
    
    void setVariable(string name, int value) {
        if (!frames.empty()) {
            frames.top().localVariables[name] = value;
        }
    }
};
```

---

## 🚀 Advanced Topics


### 1. Stack with Queue Operations
```cpp
class StackWithQueue {
private:
    queue<int> q1, q2;
    
public:
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if (q1.empty()) throw underflow_error("Stack Empty");
        
        // Move all elements except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        int result = q1.front();
        q1.pop();
        
        // Swap queues
        swap(q1, q2);
        
        return result;
    }
    
    int top() {
        if (q1.empty()) throw underflow_error("Stack Empty");
        
        int result = pop();
        push(result);
        return result;
    }
};
```

---

## 📊 Performance Analysis

### Time Complexity
| Operation | Array Implementation | Linked List Implementation |
|-----------|---------------------|---------------------------|
| Push      | O(1)                | O(1)                      |
| Pop       | O(1)                | O(1)                      |
| Peek/Top  | O(1)                | O(1)                      |
| Search    | O(n)                | O(n)                      |
| Size      | O(1)                | O(1) with counter         |

### Space Complexity
| Implementation | Space Complexity | Memory Overhead |
|----------------|------------------|-----------------|
| Array-based    | O(n)            | Minimal         |
| Linked List    | O(n)            | ~33% (pointers) |
| Vector-based   | O(n)            | ~25% (capacity) |

### Cache Performance
```
Array Implementation:
┌─────┬─────┬─────┬─────┐
│  1  │  2  │  3  │  4  │  ← Contiguous memory (better cache locality)
└─────┴─────┴─────┴─────┘

Linked List Implementation:
┌─────┐    ┌─────┐    ┌─────┐
│  1  │───→│  2  │───→│  3  │  ← Scattered memory (poor cache locality)
└─────┘    └─────┘    └─────┘
```

---

## ⚠️ Common Pitfalls

### 1. Stack Overflow
```cpp
// Dangerous: No bounds checking
void recursiveFunction(int n) {
    if (n <= 0) return;
    
    int largeArray[10000];  // Large local variables
    recursiveFunction(n - 1);  // Deep recursion
}

// Safe: Iterative approach
void iterativeFunction(int n) {
    stack<int> workStack;
    workStack.push(n);
    
    while (!workStack.empty()) {
        int current = workStack.top();
        workStack.pop();
        
        if (current > 0) {
            workStack.push(current - 1);
        }
    }
}
```

### 2. Memory Leaks
```cpp
// Dangerous: Memory leak in linked list implementation
void badPop() {
    if (topNode) {
        topNode = topNode->next;  // Lost reference to old node
    }
}

// Safe: Proper cleanup
int goodPop() {
    if (!topNode) throw underflow_error("Stack Empty");
    
    Node* temp = topNode;
    int value = temp->data;
    topNode = topNode->next;
    delete temp;  // Properly deallocate
    return value;
}
```

`

---

## 🎯 Practice Problems

### 1. Next Greater Element
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            result[i] = st.top();
        }
        
        st.push(nums[i]);
    }
    
    return result;
}
```

### 2. Largest Rectangle in Histogram
```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    
    for (int i = 0; i <= heights.size(); i++) {
        int h = (i == heights.size()) ? 0 : heights[i];
        
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        st.push(i);
    }
    
    return maxArea;
}
```

### 3. Valid Parentheses with Multiple Types
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    
    for (char c : s) {
        if (pairs.find(c) == pairs.end()) {
            // Opening bracket
            st.push(c);
        } else {
            // Closing bracket
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}
```

---

## 🎓 Summary

### Key Takeaways:
1. **LIFO Principle**: Last In, First Out access pattern
2. **O(1) Operations**: Push, pop, and peek are constant time
3. **Memory Efficiency**: Array-based for space, linked for flexibility
4. **Wide Applications**: Expression evaluation, function calls, undo operations
5. **Thread Safety**: Requires synchronization in concurrent environments

### Best Practices:
- Always check for underflow/overflow conditions
- Use appropriate implementation based on use case
- Consider memory allocation patterns
- Handle exceptions gracefully
- Profile for performance-critical applications

### Common Use Cases:
- **Compilers**: Expression parsing and evaluation
- **Operating Systems**: Function call management
- **Browsers**: Back button functionality
- **Text Editors**: Undo/redo operations
- **Algorithms**: DFS, backtracking, and parsing

---
