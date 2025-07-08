# Doubly Linked List Notes

## 1. Introduction

A **Doubly Linked List** is a linear data structure where each node contains three parts:
- **Data**: The actual value stored in the node
- **Previous Pointer**: Points to the previous node in the sequence
- **Next Pointer**: Points to the next node in the sequence

### Visual Representation:
```
NULL ← [prev|data|next] ↔ [prev|data|next] ↔ [prev|data|next] → NULL
       ↑                                                      ↑
      HEAD                                                   TAIL
```

### Advantages:
- **Bidirectional traversal**: Can move forward and backward
- **Efficient deletion**: O(1) deletion when node reference is given
- **Better for certain algorithms**: Useful for applications requiring reverse traversal

### Disadvantages:
- **Extra memory**: Requires additional pointer for each node
- **Complex implementation**: More complex than singly linked lists
- **Increased overhead**: Extra memory and pointer maintenance

---

## 2. Structure Definition

```c
struct node {
    int data;                // Data field
    struct node* prev;       // Pointer to previous node
    struct node* next;       // Pointer to next node
};
```

### Global Variables Used:
```c
struct node *nn;     // New node pointer
struct node *head;   // Points to first node
struct node *tail;   // Points to last node
struct node *temp;   // Temporary pointer for traversal
struct node *cur;    // Current pointer
struct node *prev1;  // Previous pointer for operations
```

---

## 3. Basic Operations

### 3.1 Node Creation and Initialization

**Memory Allocation:**
```c
nn = (struct node*)malloc(sizeof(struct node));
nn->data = value;
nn->prev = NULL;
nn->next = NULL;
```

### 3.2 List Initialization and Insertion

**Code Example (from 1initialization.c):**
```c
void insert() {
    int d, val;
    printf("Enter the No of Node: ");
    scanf("%d", &d);
    
    for(int i = 1; i <= d; i++) {
        nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter the %d Node data: ", i);
        scanf("%d", &val);
        
        nn->prev = NULL;
        nn->data = val;
        nn->next = NULL;
        
        if(head == NULL) {
            head = nn;      // First node
            tail = nn;
        } else {
            nn->prev = tail;    // Link to previous
            tail->next = nn;    // Link from previous
            tail = nn;          // Update tail
        }
    }
}
```

**Step-by-Step Process:**
1. **First Node**: `head = tail = new_node`
2. **Subsequent Nodes**: 
   - Set `new_node->prev = tail`
   - Set `tail->next = new_node`
   - Update `tail = new_node`

### 3.3 Display (Forward Traversal)

**Code Example:**
```c
void display() {
    temp = head;
    while(temp) {
        printf("%d", temp->data);
        temp = temp->next;
        printf(" --> ");
    }
    printf("NULL\n");
}
```

**Output Format:** `1 --> 2 --> 3 --> NULL`

---

## 4. Code Examples and Implementations

### 4.1 Reversing a Doubly Linked List

#### Method 1: Pointer Reversal (from 2.c)
```c
void rev() {
    prev1 = NULL;
    cur = head;
    
    while (cur) {
        temp = cur->next;        // Store next node
        cur->next = prev1;       // Reverse next pointer
        cur->prev = temp;        // Reverse prev pointer
        prev1 = cur;             // Move prev1 forward
        cur = temp;              // Move cur forward
    }
    head = prev1;                // Update head
}
```

**Process Visualization:**
```
Original: NULL ← [1] ↔ [2] ↔ [3] → NULL

Step 1: NULL ← [1] → NULL    [2] ↔ [3] → NULL
Step 2: NULL ← [2] → [1] → NULL    [3] → NULL
Step 3: NULL ← [3] → [2] → [1] → NULL

Final: NULL ← [3] ↔ [2] ↔ [1] → NULL
```

#### Method 2: Backward Traversal (from 3.c)
```c
void rev() {
    temp = tail;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
```
*Note: This doesn't actually reverse the list, just prints in reverse order*

#### Method 3: Recursive Approach (from 4.c)
```c
void rev(struct node* head) {
    if(head) {
        // Uncomment for forward: printf("%d ", head->data);
        rev(head->next);
        printf("%d ", head->data);  // Prints in reverse order
    }
}
```

### 4.2 Insertion at Specific Position

**Code Example (from 5.c):**
```c
void addpos(int pos) {
    temp = head;
    
    // Navigate to position-1
    for(int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    
    cur = temp->next;  // Node after insertion point
    
    // Create new node
    nn = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Node data: ");
    scanf("%d", &val);
    
    // Set up links
    nn->prev = temp;
    nn->data = val;
    nn->next = cur;
    
    // Update adjacent nodes
    temp->next = nn;
    cur->prev = nn;
}
```

**Visual Process:**
```
Before: [A] ↔ [B] ↔ [C]
Insert X at position 2:
After:  [A] ↔ [X] ↔ [B] ↔ [C]
```

### 4.3 Insertion at Start and End

**Code Example (from 6.c):**

#### Insert at Start:
```c
void add_at_start() {
    int val;
    printf("\nEnter node at starting: ");
    scanf("%d", &val);
    
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->prev = NULL;
    nn->next = NULL;
    
    head->prev = nn;    // Current head points back to new node
    nn->next = head;    // New node points to current head
    head = nn;          // Update head
}
```

#### Insert at End:
```c
void add_at_end() {
    int val;
    printf("\nEnter node at end: ");
    scanf("%d", &val);
    
    nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->prev = NULL;
    nn->next = NULL;
    
    tail->next = nn;    // Current tail points to new node
    tail = nn;          // Update tail
}
```

### 4.4 Deletion Operations

**Code Example (from 7.c):**

#### Delete at Start:
```c
void del_at_start() {
    printf("\nDel at starting.\n");
    temp = head->next;          // Store second node
    head->next->prev = NULL;    // Second node's prev = NULL
    head = temp;                // Update head
}
```

#### Delete at End:
```c
void del_at_end() {
    printf("\nDeleting at end.\n");
    temp = head;
    
    // Find second last node
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = NULL;  // Remove link to last node
    tail = temp;        // Update tail
}
```

---

## 5. Advanced Operations

### 5.1 Search Operation
```c
struct node* search(int key) {
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
```

### 5.2 Delete by Value
```c
void delete_by_value(int key) {
    temp = head;
    
    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if(temp == NULL) return;  // Not found
    
    // Handle different cases
    if(temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    
    if(temp->next) temp->next->prev = temp->prev;
    else tail = temp->prev;
    
    free(temp);
}
```

### 5.3 Count Nodes
```c
int count_nodes() {
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
```

### 5.4 Find Middle Node
```c
struct node* find_middle() {
    struct node* slow = head;
    struct node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

---

## 6. Memory Management

### 6.1 Memory Allocation
```c
nn = (struct node*)malloc(sizeof(struct node));
if(nn == NULL) {
    printf("Memory allocation failed\n");
    return;
}
```

### 6.2 Memory Deallocation
```c
void free_list() {
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}
```

### 6.3 Memory Leaks Prevention
- Always use `free()` for every `malloc()`
- Set pointers to NULL after freeing
- Check for NULL pointers before operations

---

## 7. Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Insertion at beginning | O(1) | O(1) |
| Insertion at end | O(1) | O(1) |
| Insertion at position | O(n) | O(1) |
| Deletion at beginning | O(1) | O(1) |
| Deletion at end | O(1) | O(1) |
| Deletion by value | O(n) | O(1) |
| Search | O(n) | O(1) |
| Traversal | O(n) | O(1) |
| Reverse | O(n) | O(1) |

---

## 8. Applications

### 8.1 Real-World Applications
- **Browser History**: Forward and backward navigation
- **Music Players**: Previous/next song functionality
- **Undo/Redo Operations**: In text editors
- **LRU Cache Implementation**: Doubly linked list + hash map
- **Memory Management**: Free block management in OS

### 8.2 Algorithm Applications
- **Deque Implementation**: Double-ended queue
- **Graph Algorithms**: Adjacency list representation
- **Database Systems**: B-tree implementations
- **Compiler Design**: Symbol table management

---

## 9. Comparison with Other Data Structures

### 9.1 Doubly vs Singly Linked List

| Feature | Doubly Linked List | Singly Linked List |
|---------|-------------------|-------------------|
| Memory per node | Higher (2 pointers) | Lower (1 pointer) |
| Traversal | Bidirectional | Unidirectional |
| Deletion | O(1) with node reference | O(n) without previous node |
| Implementation | More complex | Simpler |

### 9.2 Doubly Linked List vs Array

| Feature | Doubly Linked List | Array |
|---------|-------------------|--------|
| Memory allocation | Dynamic | Static/Dynamic |
| Access time | O(n) | O(1) |
| Insertion/Deletion | O(1) at known position | O(n) due to shifting |
| Memory overhead | Higher | Lower |
| Cache performance | Poor | Good |

---

## 10. Common Mistakes and Best Practices

### 10.1 Common Mistakes

1. **Not updating both pointers**:
   ```c
   // Wrong
   new_node->next = current->next;
   current->next = new_node;
   
   // Correct
   new_node->next = current->next;
   new_node->prev = current;
   if(current->next) current->next->prev = new_node;
   current->next = new_node;
   ```

2. **Not handling NULL pointers**:
   ```c
   // Wrong
   head->next->prev = NULL;
   
   // Correct
   if(head->next) head->next->prev = NULL;
   ```

3. **Memory leaks**:
   ```c
   // Wrong
   head = head->next;
   
   // Correct
   temp = head;
   head = head->next;
   free(temp);
   ```

4. **Not updating head/tail pointers**:
   ```c
   // Remember to update head when deleting first node
   // Remember to update tail when deleting last node
   ```

### 10.2 Best Practices

1. **Always check for NULL pointers**
2. **Initialize pointers to NULL**
3. **Use consistent naming conventions**
4. **Free allocated memory**
5. **Handle edge cases** (empty list, single node)
6. **Use proper error handling**
7. **Document your functions**
8. **Test with various scenarios**

### 10.3 Debugging Tips

1. **Print pointer values** during operations
2. **Use debugger** to step through code
3. **Draw diagrams** for complex operations
4. **Test edge cases** thoroughly
5. **Use static analysis tools** for memory leaks

---

## Sample Complete Program

Here's a complete program combining all operations:

```c
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
} *head = NULL, *tail = NULL;

void insert_at_end(int data) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->prev = NULL;
    nn->next = NULL;
    
    if(head == NULL) {
        head = tail = nn;
    } else {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

void display() {
    struct node* temp = head;
    printf("List: ");
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_display() {
    struct node* temp = tail;
    printf("Reverse: ");
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    
    display();
    reverse_display();
    
    return 0;
}
```

---

## Conclusion

Doubly linked lists provide powerful bidirectional traversal capabilities at the cost of extra memory. They're essential for applications requiring efficient insertion, deletion, and reverse traversal. Understanding their implementation and proper memory management is crucial for effective use in real-world applications.