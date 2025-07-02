
# 📘 Day 1: Time Complexity

Welcome to **Day 1** of my DSA Learning Journey!  
Today’s topic is **Time Complexity** – a key concept for evaluating algorithm performance.

---

## 🧠 What is Time Complexity?

**Time Complexity** measures how the time taken by an algorithm increases as the input size (`n`) grows.  
It is represented using **Big O notation** (e.g., `O(1)`, `O(n)`, `O(n²)`).

Why it's important:
- 🔍 Helps compare algorithms
- ⚙️ Optimizes code
- 📈 Predicts scalability

---

## 🧮 Common Time Complexities

| Big O Notation | Name         | Description                                    | Example                           |
|----------------|--------------|------------------------------------------------|-----------------------------------|
| `O(1)`         | Constant     | Time is always the same                        | Accessing an element `arr[0]`     |
| `O(log n)`     | Logarithmic  | Input size is halved in each step              | Binary Search                     |
| `O(n)`         | Linear       | Time grows proportionally with input           | Loop through an array             |
| `O(n log n)`   | Linearithmic | Slightly more than linear                      | Merge Sort, Quick Sort            |
| `O(n²)`        | Quadratic    | Nested loops                                   | Bubble Sort, comparing all pairs  |
| `O(2ⁿ)`        | Exponential  | Time doubles with each input                   | Naive recursive Fibonacci         |
| `O(n!)`        | Factorial    | All permutations                               | Traveling Salesman Problem        |

---

## 📖 Visual Story: Meera in a Library

Imagine **Meera** in a huge library. Her actions represent various time complexities:

- 📗 `O(1)` – Picks the **first book** instantly.
- 📘 `O(n)` – Scans **every book** before choosing.
- 📕 `O(log n)` – Uses **binary search** through sorted shelves.
- 📙 `O(n²)` – Compares **every book with every other** to find the best.

---

## 🧪 Code Examples

```python
# O(1) – Constant Time
def get_first(arr):
    return arr[0]

# O(n) – Linear Time
def print_all(arr):
    for item in arr:
        print(item)

# O(log n) – Logarithmic Time (Binary Search)
def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

# O(n²) – Quadratic Time
def all_pairs(arr):
    for i in arr:
        for j in arr:
            print(i, j)
````

---

## 🧩 Tips to Reduce Time Complexity

* ✅ Use **hash maps** for fast lookup (`O(1)`).
* 🔁 Avoid **unnecessary nested loops**.
* 🔍 Prefer **binary search** on sorted data over linear search.
* ⚙️ Choose efficient algorithms (e.g., **Merge Sort** > Bubble Sort).

---

## 🧠 Final Takeaways

* Time Complexity helps build **scalable and optimized code**.
* Always consider **input size** and **efficiency**.
* Prefer algorithms with **O(log n)**, **O(n)**, or **O(n log n)** when possible.

---