# Binary Search Tree - Complete Study Notes

## Prerequisites and Foundation

### What You Should Know Before Starting
- **Basic Tree Concepts**: Nodes, edges, root, leaves, parent-child relationships
- **Binary Trees**: Understanding of binary tree structure and properties
- **Recursion**: Essential for BST operations and traversals
- **Big O Notation**: For analyzing time and space complexity
- **Pointers/References**: BST implementation relies on pointer manipulation

### Why Binary Search Trees?

**Problem with Linear Structures:**
- Arrays: Fast access O(1) but slow insertion/deletion O(n)
- Linked Lists: Fast insertion O(1) but slow search O(n)
- Need a structure that balances search, insertion, and deletion

**Problem with Regular Binary Trees:**
- No ordering property means search requires checking every node O(n)
- Cannot retrieve elements in sorted order efficiently

**BST Solution:**
- Combines fast search O(log n) with dynamic size
- Maintains sorted order naturally
- Efficient insertion and deletion O(log n)

## Definition and Properties

### Binary Search Tree Definition
A Binary Search Tree is a binary tree where for every node:
- All values in the left subtree are **less than** the node's value
- All values in the right subtree are **greater than** the node's value
- Both left and right subtrees are also valid BSTs

### BST Property Example
```
       50
     /    \
   30      70
  /  \    /  \
 20  40  60  80
```

**Verification:**
- Node 50: Left {20,30,40} < 50, Right {60,70,80} > 50 ✓
- Node 30: Left {20} < 30, Right {40} > 30 ✓
- Node 70: Left {60} < 70, Right {80} > 70 ✓

## BST Representations

### 1. Node-Based Representation (Most Common)
```python
class Node:
    def __init__(self, data):
        self.data = data        # Value stored in node
        self.left = None        # Pointer to left child
        self.right = None       # Pointer to right child
```

**Memory Layout:**
- Each node: 12-16 bytes (data + 2 pointers)
- Nodes scattered in memory (not contiguous)
- Dynamic allocation as needed

### 2. Array-Based Representation
For complete BSTs, we can use arrays:
- Root at index 0
- For node at index i:
  - Left child at index: 2i + 1
  - Right child at index: 2i + 2
  - Parent at index: (i - 1) // 2

**Example:**
```
Array: [50, 30, 70, 20, 40, 60, 80]
Tree:       50
          /    \
        30      70
       /  \    /  \
     20   40  60  80
```

**Advantages:**
- No extra memory for pointers
- Better cache locality
- Easy to implement

**Disadvantages:**
- Wastes space for incomplete trees
- Fixed size
- Insertion/deletion complex

### 3. Linked List Representation
Each node contains:
- Data value
- List of child nodes
- Parent reference (optional)

**Use Case:** When nodes can have varying number of children

## BST Operations in Detail

### 1. Search Operation

**Algorithm Steps:**
1. Start from root
2. Compare target with current node
3. If equal: Found
4. If target < current: Go left
5. If target > current: Go right
6. If reach None: Not found

**Recursive Implementation:**
```python
def search(root, key):
    if root is None or root.data == key:
        return root
    
    if key < root.data:
        return search(root.left, key)
    else:
        return search(root.right, key)
```

**Iterative Implementation:**
```python
def search_iterative(root, key):
    current = root
    while current is not None:
        if key == current.data:
            return current
        elif key < current.data:
            current = current.left
        else:
            current = current.right
    return None
```

**Time Complexity:** O(log n) average, O(n) worst case
**Space Complexity:** O(log n) recursive, O(1) iterative

### 2. Insertion Operation

**Algorithm Steps:**
1. If tree is empty, create root
2. Start from root
3. Compare new value with current node
4. Go left if smaller, right if larger
5. Insert when reaching None position

**Implementation:**
```python
def insert(root, key):
    if root is None:
        return Node(key)
    
    if key < root.data:
        root.left = insert(root.left, key)
    else:
        root.right = insert(root.right, key)
    
    return root
```

**Time Complexity:** O(log n) average, O(n) worst case
**Space Complexity:** O(log n) for recursion stack

### 3. Deletion Operation

**Three Cases:**

**Case 1: Leaf Node (No Children)**
```python
# Simply remove the node
if node.left is None and node.right is None:
    return None
```

**Case 2: One Child**
```python
# Replace node with its child
if node.left is None:
    return node.right
elif node.right is None:
    return node.left
```

**Case 3: Two Children**
```python
# Replace with inorder successor
successor = find_min(node.right)
node.data = successor.data
node.right = delete(node.right, successor.data)
```

**Complete Deletion Implementation:**
```python
def delete(root, key):
    if root is None:
        return root
    
    if key < root.data:
        root.left = delete(root.left, key)
    elif key > root.data:
        root.right = delete(root.right, key)
    else:
        # Node to be deleted found
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        
        # Node has two children
        successor = find_min(root.right)
        root.data = successor.data
        root.right = delete(root.right, successor.data)
    
    return root
```

## BST Traversals

### 1. Inorder Traversal (Left → Root → Right)
**Special Property:** Gives elements in sorted order for BST

```python
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)
```

**Output for example BST:** 20 30 40 50 60 70 80

### 2. Preorder Traversal (Root → Left → Right)
```python
def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)
```

**Output for example BST:** 50 30 20 40 70 60 80

### 3. Postorder Traversal (Left → Right → Root)
```python
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")
```

**Output for example BST:** 20 40 30 60 80 70 50

### 4. Level Order Traversal
```python
from collections import deque

def level_order(root):
    if not root:
        return
    
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node.data, end=" ")
        
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
```

**Output for example BST:** 50 30 70 20 40 60 80

## Time and Space Complexity Analysis

### Time Complexities

**Best Case (Balanced Tree):**
- Search: O(log n)
- Insertion: O(log n)
- Deletion: O(log n)
- Traversal: O(n)

**Average Case:**
- Search: O(log n)
- Insertion: O(log n)
- Deletion: O(log n)
- Traversal: O(n)

**Worst Case (Skewed Tree):**
- Search: O(n)
- Insertion: O(n)
- Deletion: O(n)
- Traversal: O(n)

### Space Complexities

**Storage:** O(n) for n nodes
**Recursion Stack:** O(h) where h is height
- Best case: O(log n)
- Worst case: O(n)

### Why Worst Case is O(n)?
When elements are inserted in sorted order:
```
1
 \
  2
   \
    3
     \
      4
       \
        5
```
Tree becomes a linked list, height = n-1

## Memory Management

### Dynamic Memory Allocation
- Nodes created during insertion
- Memory allocated from heap
- Pointers connect nodes

### Memory Deallocation
- Important during deletion
- Prevent memory leaks
- Automatic in Python (garbage collection)

### Memory Optimization Strategies
1. **Use Iterative Approaches:** Reduce stack usage
2. **Memory Pools:** For frequent allocation/deallocation
3. **Compact Representations:** Arrays for complete trees
4. **Reference Counting:** Track node usage

## Advanced BST Properties

### Height Calculation
```python
def height(root):
    if root is None:
        return -1  # or 0 depending on definition
    return 1 + max(height(root.left), height(root.right))
```

### Node Count
```python
def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)
```

### Leaf Count
```python
def count_leaves(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    return count_leaves(root.left) + count_leaves(root.right)
```

### BST Validation
```python
def is_valid_bst(root, min_val=float('-inf'), max_val=float('inf')):
    if root is None:
        return True
    
    if root.data <= min_val or root.data >= max_val:
        return False
    
    return (is_valid_bst(root.left, min_val, root.data) and
            is_valid_bst(root.right, root.data, max_val))
```

## Practical Applications

### 1. Database Indexing
- **B-Trees:** Generalized BSTs for disk storage
- **Fast Lookups:** O(log n) record retrieval
- **Range Queries:** Efficient range scans

### 2. Expression Trees
- **Operators:** Internal nodes
- **Operands:** Leaf nodes
- **Evaluation:** Postorder traversal

### 3. File Systems
- **Directory Structure:** Hierarchical organization
- **Fast Navigation:** O(log n) file access
- **Sorted Listing:** Inorder traversal

### 4. Compiler Symbol Tables
- **Variable Storage:** Identifier lookup
- **Scope Management:** Nested symbol tables
- **Fast Access:** O(log n) symbol resolution

### 5. Priority Queues
- **Binary Heaps:** Special BSTs
- **Efficient Operations:** Insert, extract-min/max
- **Task Scheduling:** Operating system applications

## BST Variants and Extensions

### 1. Self-Balancing BSTs
**AVL Trees:**
- Height-balanced
- Rotation operations
- Guaranteed O(log n) operations

**Red-Black Trees:**
- Color-based balancing
- Relaxed height constraints
- Used in many libraries

### 2. Threaded BSTs
- Additional pointers for efficient traversal
- Eliminates recursion/stack for traversal
- Space-time tradeoff

### 3. Persistent BSTs
- Immutable versions
- Share structure between versions
- Functional programming applications

## Common Problems and Solutions

### Problem 1: Unbalanced Trees
**Issue:** Degraded performance O(n)
**Solution:** Use self-balancing BSTs

### Problem 2: Memory Leaks
**Issue:** Deleted nodes not deallocated
**Solution:** Proper cleanup in deletion

### Problem 3: Stack Overflow
**Issue:** Deep recursion on skewed trees
**Solution:** Iterative implementations

### Problem 4: Duplicate Values
**Issue:** Unclear handling of equal values
**Solution:** Define clear duplicate policy

## Best Practices and Guidelines

### Design Decisions
1. **Duplicate Policy:** Allow, ignore, or count duplicates
2. **Balancing:** Consider self-balancing for critical applications
3. **Error Handling:** Implement proper null checks
4. **Testing:** Test with various input patterns

### Implementation Tips
1. **Base Cases:** Always handle null/empty cases
2. **Iterative Alternatives:** Use for deep trees
3. **Memory Management:** Proper cleanup
4. **Code Clarity:** Clear variable names and comments

### Performance Optimization
1. **Keep Balanced:** Maintain tree balance
2. **Cache Results:** Store frequently accessed values
3. **Minimize Recursion:** Use iterative approaches
4. **Memory Locality:** Consider cache-friendly layouts

## Common Mistakes to Avoid

1. **Incorrect BST Property:** Not maintaining ordering constraint
2. **Memory Leaks:** Forgetting to deallocate nodes
3. **Null Pointer Errors:** Not checking for null nodes
4. **Infinite Recursion:** Incorrect base cases
5. **Duplicate Handling:** Inconsistent duplicate policies
6. **Stack Overflow:** Deep recursion on large trees

## Summary and Key Takeaways

**BST Strengths:**
- Efficient search, insertion, deletion O(log n) average
- Natural sorted order through inorder traversal
- Dynamic size with efficient memory usage
- Foundation for advanced data structures

**BST Weaknesses:**
- Worst-case O(n) performance when unbalanced
- Memory overhead for pointers
- Complex implementation compared to arrays
- Requires balancing for guaranteed performance

**When to Use BSTs:**
- Need efficient search with dynamic insertions/deletions
- Require sorted data access
- Range queries are common
- Memory usage is reasonable

**When to Avoid BSTs:**
- Need guaranteed O(1) operations (use hash tables)
- Data is mostly static (use sorted arrays)
- Memory is severely constrained
- Simple linear access patterns

Binary Search Trees are fundamental data structures that provide an excellent balance between search efficiency and dynamic operations. Understanding their properties, implementations, and trade-offs is crucial for any programmer working with hierarchical data or requiring efficient search operations.