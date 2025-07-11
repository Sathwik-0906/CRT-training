# Queue Notes:

## 🎯 Introduction

A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. Think of it like a line of people waiting - the first person to join the line is the first to be served.

### Key Characteristics:
- **Linear**: Elements are arranged in a sequential order
- **FIFO**: First element added is the first to be removed
- **Two-ended Access**: Add at rear, remove from front
- **Dynamic**: Size can change during runtime

---

## 🏗️ Queue Fundamentals

### Abstract Data Type (ADT)
```
Queue ADT Operations:
├── enqueue(item)  → Add item to rear
├── dequeue()      → Remove and return front item
├── front()        → View front item without removing
├── rear()         → View rear item without removing
├── isEmpty()      → Check if queue is empty
├── size()         → Get number of elements
└── isFull()       → Check if queue is full (array implementation)
```

### Visual Representation
```
FIFO Operation Flow:

Front                           Rear
  ↓                              ↓
┌─────┬─────┬─────┬─────┬─────┐
│  1  │  3  │  7  │  5  │  9  │
└─────┴─────┴─────┴─────┴─────┘
  ↑                              ↑
Dequeue                      Enqueue
(Remove)                      (Add)

Direction: ← Remove    Add →
```

### Queue vs Stack Comparison
```
Stack (LIFO):                Queue (FIFO):
    ↑ Push                       ← Dequeue  Enqueue →
  ┌───┐                        ┌─────┬─────┬─────┐
  │ 3 │                        │  1  │  2  │  3  │
  │ 2 │                        └─────┴─────┴─────┘
  │ 1 │                         Front         Rear
  └───┘
    ↓ Pop
```

---

## 💾 Memory Management

### 1. Queue Memory Layout

#### Array-based Queue (Circular)
```
Linear Array Problem:
┌─────┬─────┬─────┬─────┬─────┐
│  ∅  │  ∅  │  3  │  7  │  5  │
└─────┴─────┴─────┴─────┴─────┘
              ↑           ↑
            Front       Rear
         (Wasted Space)

Circular Array Solution:
        Front(2)
           ↓
┌─────┬─────┬─────┬─────┬─────┐
│  9  │  1  │  3  │  7  │  5  │
└─────┴─────┴─────┴─────┴─────┘
  ↑                       ↑
Rear(0)                (Index 4)

Memory Efficiency: 100% utilization
```

#### Linked List Queue
```
Node Structure:
┌─────────┬─────────┐
│  Data   │  Next   │
└─────────┴─────────┘
  4 bytes   8 bytes (64-bit)

Queue Layout:
Front                           Rear
  ↓                              ↓
┌─────┐    ┌─────┐    ┌─────┐    ┌─────┐
│  1  │───→│  3  │───→│  7  │───→│  5  │───→ NULL
└─────┘    └─────┘    └─────┘    └─────┘

Memory: Non-contiguous, dynamic allocation
```

### 2. Memory Allocation Strategies

#### Static Allocation (Array-based)
```cpp
template<typename T, int SIZE>
class StaticQueue {
private:
    T arr[SIZE];        // Fixed size: SIZE * sizeof(T)
    int front;          // 4 bytes
    int rear;           // 4 bytes
    int count;          // 4 bytes
    
public:
    // Total Memory: SIZE * sizeof(T) + 12 bytes
    // Allocation: Stack/Data segment
    // Lifetime: Scope-based or program duration
};
```

#### Dynamic Allocation (Resizable Array)
```cpp
template<typename T>
class DynamicQueue {
private:
    T* arr;             // 8 bytes pointer
    int capacity;       // 4 bytes
    int front;          // 4 bytes
    int rear;           // 4 bytes
    int size;           // 4 bytes
    
public:
    // Array Memory: capacity * sizeof(T) (heap)
    // Object Memory: 24 bytes (stack/heap)
    // Growth Strategy: Double when full
};
```

#### Linked List Allocation
```cpp
template<typename T>
class LinkedQueue {
private:
    struct Node {
        T data;         // sizeof(T)
        Node* next;     // 8 bytes
        
        // Total per node: sizeof(T) + 8 + padding
        // Typically: sizeof(T) + 16 bytes
    };
    
    Node* frontPtr;     // 8 bytes
    Node* rearPtr;      // 8 bytes
    int size;           // 4 bytes
    
public:
    // Object Memory: 20 bytes
    // Node Memory: size * (sizeof(T) + 16) bytes
    // Allocation: Each node on heap
};
```

### 3. Memory Access Patterns

#### Cache Performance Analysis
```
Array-based Queue (Good Cache Locality):
Memory Layout:
┌─────┬─────┬─────┬─────┬─────┬─────┐
│  1  │  2  │  3  │  4  │  5  │  6  │
└─────┴─────┴─────┴─────┴─────┴─────┘
Cache Line: [1][2][3][4] [5][6][X][X]

Linked Queue (Poor Cache Locality):
Node₁ (Addr: 0x1000) → Node₂ (Addr: 0x2000) → Node₃ (Addr: 0x3000)
Cache Miss on each access if nodes are scattered
```

#### Memory Fragmentation
```
Linked List Memory Pattern:
Heap Memory: [Node₁][Free][Node₂][Free][Free][Node₃]
                ↑          ↑                    ↑
           Allocated   Fragmented            Allocated

Array Memory Pattern:
Heap Memory: [Queue Array Block][Free Space]
                      ↑
                Contiguous Block
```

---

## 🔧 Queue Operations & Implementation

### 1. Array-Based Queue Implementation
```cpp
template<typename T>
class ArrayQueue {
private:
    T* arr;
    int capacity;
    int front;
    int rear;
    int size;
    
public:
    ArrayQueue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new T[capacity];
    }
    
    ~ArrayQueue() {
        delete[] arr;
    }
    
    // Basic Queue Operations
    void enqueue(const T& item) {
        if (isFull()) {
            throw overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;  // Circular increment
        arr[rear] = item;
        size++;
    }
    
    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        T item = arr[front];
        front = (front + 1) % capacity;  // Circular increment
        size--;
        return item;
    }
    
    T frontItem() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }
    
    T rearItem() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[rear];
    }
    
    // Utility Operations
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
    int getSize() const { return size; }
    
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue: ";
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
```

### 2. Linked List Queue Implementation
```cpp
template<typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& item) : data(item), next(nullptr) {}
    };
    
    Node* frontPtr;
    Node* rearPtr;
    int size;
    
public:
    LinkedQueue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}
    
    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    // Basic Queue Operations
    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        size++;
    }
    
    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        
        Node* temp = frontPtr;
        T item = temp->data;
        frontPtr = frontPtr->next;
        
        if (frontPtr == nullptr) {
            rearPtr = nullptr;  // Queue became empty
        }
        
        delete temp;
        size--;
        return item;
    }
    
    T front() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return frontPtr->data;
    }
    
    T rear() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return rearPtr->data;
    }
    
    // Utility Operations
    bool isEmpty() const { return frontPtr == nullptr; }
    int getSize() const { return size; }
    
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Queue: ";
        Node* current = frontPtr;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
```

### 3. Dynamic Array Queue Implementation
```cpp
template<typename T>
class DynamicQueue {
private:
    T* arr;
    int capacity;
    int front;
    int size;
    
    void resize() {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];
        
        // Copy elements maintaining order
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }
        
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
    }
    
public:
    DynamicQueue(int initialCapacity = 4) 
        : capacity(initialCapacity), front(0), size(0) {
        arr = new T[capacity];
    }
    
    ~DynamicQueue() {
        delete[] arr;
    }
    
    // Basic Queue Operations
    void enqueue(const T& item) {
        if (size == capacity) {
            resize();
        }
        
        int rear = (front + size) % capacity;
        arr[rear] = item;
        size++;
    }
    
    T dequeue() {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        
        T item = arr[front];
        front = (front + 1) % capacity;
        size--;
        
        // Optional: Shrink if too much unused space
        if (size > 0 && size <= capacity / 4) {
            shrink();
        }
        
        return item;
    }
    
    T frontItem() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        return arr[front];
    }
    
    T rearItem() const {
        if (isEmpty()) {
            throw underflow_error("Queue is empty");
        }
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
    
    // Utility Operations
    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    
private:
    void shrink() {
        int newCapacity = max(4, capacity / 2);
        T* newArr = new T[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }
        
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        front = 0;
    }
};
```

---

## 📊 Performance Analysis

### Time Complexity Comparison
| Operation | Array Queue | Linked Queue | Circular Queue | Priority Queue |
|-----------|-------------|--------------|----------------|----------------|
| Enqueue   | O(1)*       | O(1)         | O(1)           | O(log n)       |
| Dequeue   | O(1)*       | O(1)         | O(1)           | O(log n)       |
| Front     | O(1)        | O(1)         | O(1)           | O(1)           |
| Search    | O(n)        | O(n)         | O(n)           | O(n)           |
| Size      | O(1)        | O(1)         | O(1)           | O(1)           |