
# CIRCULAR LINKED LIST

## Circular Linked List Introduction {#circular-introduction}

A **Circular Linked List** is a variation of linked list where the last node points back to the first node, forming a circle. Unlike linear linked lists, there's no NULL termination - the list forms a continuous loop.

### Key Characteristics:
- **No NULL termination**: Last node points to first node
- **Continuous traversal**: Can traverse indefinitely
- **Single entry point**: Usually maintained through head pointer
- **Efficient for cyclic operations**: Perfect for round-robin scheduling

### Visual Representation:
```
    ┌─────────────────────────────────────┐
    │                                     │
    ▼                                     │
[data|next] → [data|next] → [data|next] ──┘
    ↑                           ↑
   HEAD                        TAIL
```

### Types of Circular Linked Lists:
1. **Singly Circular**: Each node has one next pointer
2. **Doubly Circular**: Each node has both next and previous pointers

---

## Circular Linked List Structure {#circular-structure}

### Structure Definition:
```c
struct node {
    int data;               // Data field
    struct node* next;      // Pointer to next node
};
```

### Global Variables:
```c
struct node *nn;    // New node pointer
struct node *head;  // Points to first node
struct node *tail;  // Points to last node  
struct node *temp;  // Temporary pointer for traversal
struct node *prev;  // Previous node pointer
```

### Memory Layout Representation:
```
Memory Address:  [1000] [1004] [1008] [1012]
Node Structure:  [data] [next] [data] [next] ...

Example with 3 nodes:
Node 1: [10|1004] at address 1000
Node 2: [20|1008] at address 1004  
Node 3: [30|1000] at address 1008  (points back to Node 1)
```

---

## Circular Linked List Operations {#circular-operations}

### Key Differences from Linear Lists:

| Operation | Linear List | Circular List |
|-----------|-------------|---------------|
| Initialization | `tail->next = NULL` | `tail->next = head` |
| Traversal End | `temp != NULL` | `temp != head` (after first iteration) |
| Insertion | Simple link update | Must maintain circular property |
| Deletion | Handle NULL cases | Handle circular continuity |

### Basic Operations Overview:

1. **Insertion**: Always maintain `tail->next = head`
2. **Display**: Stop when we reach head again  
3. **Reversal**: Reverse all pointers while maintaining circularity
4. **Deletion**: Update links to preserve circular structure

---

## Circular Linked List Code Examples {#circular-code-examples}

### Basic Insertion and Display (Code from 1.c)

#### Insertion Function:
```c
void insert() {
    int d, val;
    for(int i = 1; i <= 4; i++) {
        printf("Enter %d node: ", i);
        scanf("%d", &val);
        
        // Create new node
        nn = (struct node*)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;
        
        if(head == NULL) {
            // First node case
            head = nn;
            tail = nn;
            tail->next = head;    // Make it circular
        } else {
            // Subsequent nodes
            tail->next = nn;      // Link from current tail
            tail = nn;            // Update tail
            tail->next = head;    // Maintain circular property
        }
    }
}
```

#### Step-by-Step Memory Representation:

**Step 1 - Insert First Node (10):**
```
Memory: [10|addr_of_10]
        ↑           ↓
       HEAD ←─────TAIL
```

**Step 2 - Insert Second Node (20):**
```
Memory: [10|addr_of_20] → [20|addr_of_10]
        ↑                 ↑           ↓
       HEAD              TAIL ←───────┘
```

**Step 3 - Insert Third Node (30):**
```
Memory: [10|addr_of_20] → [20|addr_of_30] → [30|addr_of_10]
        ↑                                   ↑           ↓
       HEAD                               TAIL ←────────┘
```

#### Display Function:
```c
void display() {
    temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
        if(temp == head) {
            break;           // Stop when we reach head again
        }
    }
    printf("%d ", temp->data);  // Print the head node data
}
```

**Display Process:**
1. Start at head
2. Print current node data
3. Move to next node
4. Check if we've reached head again
5. Break the loop to avoid infinite traversal

### Circular List Reversal (Code from 2.c)

#### Reversal Function:
```c
void rev() {
    struct node *cur, *next;
    prev = tail;        // Start prev from tail
    cur = head;         // Start cur from head
    
    while(cur) {
        next = cur->next;      // Store next node
        cur->next = prev;      // Reverse the link
        prev = cur;            // Move prev forward
        cur = next;            // Move cur forward
        
        if(cur == head) {      // Stop when we reach head again
            break;
        }
    }
    head = prev;               // Update head
    tail = cur;                // Update tail
}
```

#### Reversal Process Visualization:

**Original List:**
```
[A] → [B] → [C] → [D] ──┐
↑                       │
└───────────────────────┘
```

**Step-by-Step Reversal:**

**Step 1:** `prev = tail(D), cur = head(A)`
```
[A] ← [B] → [C] → [D] ──┐
↑                       │
└───────────────────────┘
```

**Step 2:** `cur = B, prev = A`
```
[A] ← [B] ← [C] → [D] ──┐
      ↑                 │
      └─────────────────┘
```

**Step 3:** `cur = C, prev = B`
```
[A] ← [B] ← [C] ← [D] ──┐
             ↑          │
             └──────────┘
```

**Final Result:**
```
[A] ← [B] ← [C] ← [D] ──┐
                  ↑     │
                 HEAD   │
                        │
[A] ──────────────────────┘
↑
TAIL
```

### Complete Working Example:

```c
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
} *nn, *head = NULL, *tail = NULL, *temp, *prev;

void insert() {
    int val;
    for(int i = 1; i <= 4; i++) {
        printf("Enter %d node: ", i);
        scanf("%d", &val);
        
        nn = (struct node*)malloc(sizeof(struct node));
        nn->data = val;
        nn->next = NULL;
        
        if(head == NULL) {
            head = nn;
            tail = nn;
            tail->next = head;
        } else {
            tail->next = nn;
            tail = nn;
            tail->next = head;
        }
    }
}

void display() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

void rev() {
    if(head == NULL || head->next == head) return;
    
    struct node *cur, *next;
    prev = tail;
    cur = head;
    
    do {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    } while(cur != head);
    
    head = prev;
    tail = cur;
}

int main() {
    insert();
    printf("Original list: ");
    display();
    
    rev();
    printf("Reversed list: ");
    display();
    
    return 0;
}
```

---

## Circular vs Linear Comparison {#circular-comparison}

### Feature Comparison:

| Feature | Linear Linked List | Circular Linked List |
|---------|-------------------|---------------------|
| **Termination** | NULL pointer | Points to head |
| **Traversal** | One direction, ends at NULL | Continuous loop |
| **Memory Usage** | Same per node | Same per node |
| **Implementation** | Simpler | Slightly complex |
| **Applications** | General purpose | Cyclic operations |

### Operation Complexity:

| Operation | Linear List | Circular List |
|-----------|-------------|---------------|
| Insertion at end | O(1) with tail pointer | O(1) with tail pointer |
| Insertion at beginning | O(1) | O(1) |
| Deletion at end | O(n) without tail | O(1) with tail |
| Deletion at beginning | O(1) | O(1) |
| Search | O(n) | O(n) |
| Traversal | O(n) | O(n) |

### Memory Management Comparison:

**Linear List Memory:**
```
Node1[data|next] → Node2[data|next] → Node3[data|NULL]
```

**Circular List Memory:**
```
Node1[data|next] → Node2[data|next] → Node3[data|next]
↑                                              ↓
└──────────────────────────────────────────────┘
```

---

## Circular Linked List Applications {#circular-applications}

### Real-World Applications:

1. **Round-Robin Scheduling**: 
   - Process scheduling in operating systems
   - Each process gets equal time slice
   
2. **Circular Buffers**:
   - Data streaming applications
   - Producer-consumer problems
   
3. **Game Development**:
   - Turn-based games
   - Circular menus
   
4. **Media Players**:
   - Playlist looping
   - Shuffle and repeat functionality

5. **Josephus Problem**:
   - Mathematical problem solving
   - Elimination algorithms

### Code Example - Josephus Problem:

```c
void josephus(int n, int k) {
    // Create circular list with n people
    struct node *head = NULL, *tail = NULL;
    
    for(int i = 1; i <= n; i++) {
        struct node *nn = (struct node*)malloc(sizeof(struct node));
        nn->data = i;
        nn->next = NULL;
        
        if(head == NULL) {
            head = tail = nn;
            tail->next = head;
        } else {
            tail->next = nn;
            tail = nn;
            tail->next = head;
        }
    }
    
    // Eliminate every kth person
    struct node *current = head;
    while(current->next != current) {
        for(int i = 1; i < k; i++) {
            current = current->next;
        }
        
        // Remove current node
        struct node *toDelete = current->next;
        current->next = toDelete->next;
        printf("Person %d eliminated\n", toDelete->data);
        free(toDelete);
    }
    
    printf("Survivor: %d\n", current->data);
}
```

---

## Memory Management in Circular Lists {#circular-memory}

### Memory Allocation Pattern:

```c
// Proper memory allocation
nn = (struct node*)malloc(sizeof(struct node));
if(nn == NULL) {
    printf("Memory allocation failed\n");
    return;
}

// Initialize all fields
nn->data = value;
nn->next = NULL;  // Always initialize to NULL first
```

### Memory Deallocation:

**Problem**: Cannot use simple linear traversal due to circular nature

**Solution**: Mark the starting point and stop when reached again

```c
void free_circular_list() {
    if(head == NULL) return;
    
    struct node *current = head;
    struct node *next;
    
    do {
        next = current->next;
        free(current);
        current = next;
    } while(current != head);
    
    head = NULL;
    tail = NULL;
}
```

### Memory Leak Prevention:

1. **Always free nodes**: Don't just reassign head pointer
2. **Handle empty lists**: Check for NULL before operations
3. **Break circular links**: Set next to NULL before freeing
4. **Use valgrind**: Check for memory leaks in testing

### Debug Memory Visualization:

```c
void debug_memory() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head;
    int count = 0;
    
    do {
        printf("Node %d: Address=%p, Data=%d, Next=%p\n", 
               count++, temp, temp->data, temp->next);
        temp = temp->next;
    } while(temp != head);
    
    printf("Total nodes: %d\n", count);
    printf("Head: %p, Tail: %p\n", head, tail);
    printf("Circular check: tail->next == head? %s\n", 
           (tail->next == head) ? "YES" : "NO");
}
```

### Common Memory Errors:

1. **Infinite loops**: Forgetting to check for head in traversal
2. **Memory leaks**: Not freeing all nodes before exit
3. **Dangling pointers**: Accessing freed memory
4. **Double free**: Freeing same memory twice

### Safe Programming Practices:

```c
// Safe insertion with error checking
struct node* safe_insert(int data) {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    
    if(nn == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    
    nn->data = data;
    nn->next = NULL;
    
    if(head == NULL) {
        head = tail = nn;
        nn->next = head;
    } else {
        tail->next = nn;
        tail = nn;
        tail->next = head;
    }
    
    return nn;
}

// Safe deletion with memory management
void safe_delete(int data) {
    if(head == NULL) return;
    
    struct node *current = head;
    struct node *prev = tail;
    
    do {
        if(current->data == data) {
            if(current == head && current == tail) {
                // Only one node
                head = tail = NULL;
            } else if(current == head) {
                // Deleting head
                head = current->next;
                tail->next = head;
            } else if(current == tail) {
                // Deleting tail
                tail = prev;
                tail->next = head;
            } else {
                // Deleting middle node
                prev->next = current->next;
            }
            
            free(current);
            return;
        }
        
        prev = current;
        current = current->next;
    } while(current != head);
}
```

---

## Summary and Best Practices

### Key Takeaways:

1. **Circular Lists** are perfect for cyclic operations and round-robin algorithms
2. **Memory Management** requires special attention due to circular nature
3. **Traversal** must be carefully controlled to avoid infinite loops
4. **Applications** include scheduling, games, and mathematical problems

### Best Practices:

1. **Always initialize** pointers to NULL
2. **Check for empty lists** before operations
3. **Use do-while loops** for traversal when appropriate
4. **Free memory properly** to avoid leaks
5. **Test edge cases** (empty list, single node, etc.)
6. **Debug with memory tools** like valgrind
7. **Document circular property** in code comments

### Performance Considerations:

- **Space**: Same as linear lists
- **Time**: Similar complexity but constant-time access to both ends
- **Memory Access**: May have better cache locality in some applications

Remember: **Circular linked lists are powerful but require careful implementation!** Always test thoroughly and manage memory properly.