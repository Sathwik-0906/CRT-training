## 🧠 What is Recursion?

> **Recursion is when a function calls itself to solve a smaller version of a problem.**

It keeps calling itself until it hits a point where it **stops** — this is called the **base case**.

---

### 🔁 Think of it like:

> “To solve a big problem, break it into smaller problems… and use the same steps again.”

---

## 📖 Story: 📦 Boxes Inside Boxes

Imagine you have a big box 📦.

* You open it, and inside it is **another box**.
* You open that one… and it has **another box**.
* You keep opening until you find the **smallest box** with a **gift** inside.

Once you find the gift (your **base case**), you start closing all the boxes.

> This is exactly what recursion does:
> Open smaller problems until it reaches the solution, then builds back up.

---

## ✅ Structure of Recursion

```python
def recursive_function(params):
    if base_case:
        return result
    else:
        # smaller problem
        return recursive_function(smaller_input)
```

---

## 🧪 Example: Factorial of a Number

🧮 `factorial(5)` = 5 × 4 × 3 × 2 × 1 = 120

```python
def factorial(n):
    if n == 1:  # base case
        return 1
    else:
        return n * factorial(n - 1)  # recursive case
```

### How it works:

* `factorial(5)`
  → `5 * factorial(4)`
  → `5 * 4 * factorial(3)`
  → `5 * 4 * 3 * factorial(2)`
  → `5 * 4 * 3 * 2 * factorial(1)`
  → `5 * 4 * 3 * 2 * 1 = 120`

---

## ⚠️ Key Points

* Every recursion must have a **base case** to stop it.
* Without a base case, it causes **infinite calls** → stack overflow.
* You can always convert recursion to a loop.

---

## ✅ When to Use Recursion

* When the problem can be broken into similar subproblems
* Examples:

  * Factorials
  * Fibonacci numbers
  * Tree/graph traversal
  * Backtracking (e.g., Sudoku, maze solving)

---
