
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

* ✅ Use **hash maps** for fast lookup (`O(1)`) Instead of Brute Force.
* 🔁 Avoid **unnecessary nested loops**.
* 🔍 Prefer **binary search** on sorted data over linear search.
* ⚙️ Choose efficient algorithms (e.g., **Merge Sort** > Bubble Sort).

---

## 🧠 Final Takeaways

* Time Complexity helps build **scalable and optimized code**.
* Always consider **input size** and **efficiency**.
* Prefer algorithms with **O(log n)**, **O(n)**, or **O(n log n)** when possible.

---


Let’s simplify the idea **step by step**, like you're explaining it to your younger self 👇

---

### 🧠 First, understand this:

* **Time Complexity** → how *long* your code takes to run
* **Memory Usage** → how much *space* (RAM) your code uses

Now here’s a super simple story to understand how both are connected 👇

---

### 📖 **Story: You and the Exam Hall**

You are solving math problems in an exam hall.

---

#### 🔴 **Slow Student (O(n²))**

* You solve problems one by one, but for every question…

  * You write long steps
  * You draw lots of diagrams
  * You keep using new pages for rough work
* 🕒 Takes a lot of time
* 🧠 Fills up your memory (you use many answer sheets)

➡️ Because you're slow (bad **time complexity**), you use more **memory** (pages/space).

---

#### 🟢 **Smart Student (O(n))**

* You know tricks and shortcuts
* You do calculations quickly in your head
* You don’t need extra pages for rough work
* 🕒 Takes less time
* 🧠 Uses less memory

➡️ Since you solve faster (good **time complexity**), you don’t need much **memory**.

---

### Accurate Rule:

> **Better time complexity often comes at the cost of more memory usage.**
> You use **extra space** (like Hash Maps, DP tables, caches) to **avoid repeating work**.

---

### 🔄 Time-Space Trade-off

| Scenario                      | Time         | Space         | Tool Used         |
| ----------------------------- | ------------ | ------------- | ----------------- |
| Brute-force search            | Slow (O(n²)) | Low (O(1))    | Nested loops      |
| Using Hash Map (lookup/cache) | Fast (O(n))  | Medium (O(n)) | Dictionary / Set  |
| Dynamic Programming (memo)    | Fast (O(n))  | High (O(n))   | Memoization Table |

---

### ✅ Good Time Often Needs More Space:

* **Two Sum** problem → Faster using Hash Map (uses extra space).
* **Fibonacci DP** → Recursion is slow but saves memory; DP is fast but uses a table.
* **Sorting** → Merge Sort is fast but uses extra space; In-place sorts (like QuickSort) save memory but can be slower/worse in edge cases.

---

### ❌ Counter-example:

* Sometimes bad time complexity doesn’t even save memory:

  ```python
  for i in range(len(arr)):
      for j in range(len(arr)):
          if arr[i] == arr[j]:
              ...
  ```

  * Time: O(n²)
  * Space: O(1) — but still bad performance overall.

---



### Conclusion:

> Faster algorithms **often use more memory** to reduce time — this is called a **time-space trade-off**.
> **Good time ≠ low memory**, and **bad time ≠ good memory** — it's all about how smartly you optimize both.

---


