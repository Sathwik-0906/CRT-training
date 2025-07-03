# 📚 Arrays in Data Structures & Algorithms (DSA)

---

## 🔷 What is an Array?

### ✅ Technical Definition:
An **array** is a **linear data structure** that stores elements of the **same data type** in **contiguous memory locations**. Each element is accessed by an **index**, starting from 0.

### 📖 Story-Based Definition:
Think of an array like a **row of mailboxes**.  
Each mailbox has:
- A number (index)
- A message (value)

You can directly open mailbox 3 and check its letter — no need to open 0, 1, or 2. That’s how an array allows **direct access** using indexes.

---

## 🔹 Key Characteristics:

| Feature             | Description                                           |
|---------------------|-------------------------------------------------------|
| **Indexing**        | Starts from 0                                         |
| **Contiguous**      | Elements are stored next to each other in memory     |
| **Same Type**       | All elements must be of the same data type            |
| **Fixed Size**      | Size is decided when array is created (static array) |
| **Fast Access**     | O(1) access time using index                          |

---

## 🔹 Time Complexity Table:

| Operation         | Time Complexity |
|-------------------|-----------------|
| Access (arr[i])   | O(1)            |
| Update            | O(1)            |
| Traverse          | O(n)            |
| Search (linear)   | O(n)            |
| Search (binary)*  | O(log n)        |
| Insert/Delete     | O(n)            |

> *Binary search only works on sorted arrays.

---

## 🔷 Why Are Arrays Important in DSA?

Arrays are the **foundation** for many algorithms and advanced data structures. They are:
- 🧠 Easy to implement and understand.
- 🏃 Fast in access and iteration.
- 🏗️ Used in building structures like matrices, heaps, stacks, queues.
- 📊 Essential for solving problems using **two-pointer**, **sliding window**, **prefix sum**, etc.

---

## 🔷 Where Arrays Are Used in DSA?

| DSA Concept         | Use of Arrays                                  |
|---------------------|------------------------------------------------|
| **Searching**       | Linear Search, Binary Search                   |
| **Sorting**         | Bubble, Merge, Quick Sort                      |
| **Sliding Window**  | Max sum subarrays, Longest substring, etc.    |
| **Dynamic Programming** | Store subproblem results                |
| **Hashing**         | Frequency counting with count arrays           |
| **Graphs**          | Adjacency matrices                             |
| **Math Problems**   | Prefix sum, Sieve of Eratosthenes              |

---

## 📘 DSA-Based Analogy / Story

Imagine a **bus with 50 seats**, each numbered from 0 to 49.

- You want to track which seat is occupied.
- You use an array of size 50: `int seats[50];`
- When someone sits on seat 20 → `seats[20] = 1;`
- To check if seat 20 is taken → check `seats[20]`

You just built a **real-time occupancy tracker** using an array.

---

## 🔷 What is a Dynamic Array?

### ✅ Definition:
A **dynamic array** is a resizable array that can **grow or shrink** during runtime. It uses **heap memory** and allows:
- Flexible resizing
- Dynamic allocation of memory
- Similar index-based access as normal arrays

# 🧠 Heap Memory (Quick Notes)

---

## ✅ Definition

Heap memory is a part of RAM used for **dynamic memory allocation**.  
Memory in the heap is allocated at **runtime** and can **grow or shrink** as needed.

---

## 📖 Story Definition

Think of **heap memory** like a **guest house**:

- You can book rooms anytime.
- You decide how long you stay.
- But if you forget to check out → 🧠 **Memory leak**.

Unlike stack (automatic), heap gives you **manual control**.

---

## 🔹 Important Points

- Allocated using `malloc`, `calloc`, `realloc`, or `new`
- Must be **freed manually** (`free()` or `delete`)
- Used for **dynamic data structures**: arrays, lists, trees
- Slower than stack, but **flexible and large**
- Java & Python manage heap automatically via **Garbage Collection**

---

---

## 🔹 Static Array vs Dynamic Array

| Feature           | Static Array (`int arr[10]`) | Dynamic Array (`malloc`, `vector`, etc.) |
|-------------------|-------------------------------|-------------------------------------------|
| Size              | Fixed at compile time         | Flexible at runtime                       |
| Memory            | Stack                         | Heap                                      |
| Resize possible?  | ❌ No                         | ✅ Yes (using `realloc()` or internal logic) |
| Access speed      | O(1)                          | O(1)                                      |
| Used in C         | `int arr[10];`                | `malloc`, `realloc`                       |
| Used in C++       | `int arr[10];`                | `vector<int>`                             |
| Used in Python    | Not used                      | `list` (Python lists are dynamic arrays)  |

---

## 🔷 Dynamic Array Example in C:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    arr = (int *)malloc(n * sizeof(int));  // allocate array

    for (int i = 0; i < n; i++) arr[i] = i + 1;

    arr = (int *)realloc(arr, 10 * sizeof(int));  // resize

    for (int i = 5; i < 10; i++) arr[i] = i + 1;

    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

    free(arr);  // deallocate memory
    return 0;
}


---