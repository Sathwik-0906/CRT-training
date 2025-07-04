# 2D Arrays Explained: A Complete Guide for Interview Preparation

---

## 🏠 A Simple Story to Understand 2D Arrays

Imagine a **royal palace** where a **grand feast** is being hosted. The king invites many guests and arranges the dining hall with **rows of tables**, each with several **seats**.

To manage this, the king creates a **"Seating Plan"**. This plan has:

* **Rows** = Tables
* **Columns** = Seats at each table

The entire seating plan looks like a **grid**:

```
+----+----+----+----+
| 10 | 20 | 30 | 40 |   ← Table 0
+----+----+----+----+
| 50 | 60 | 70 | 80 |   ← Table 1
+----+----+----+----+
| 90 |100 |110 |120 |   ← Table 2
+----+----+----+----+
```

This **grid of rows and columns** is exactly what a **2D Array** is in programming.

---

## 📊 Definition

> A **2D array** (two-dimensional array) is an array of arrays. It stores data in **row-column** format, like a matrix or table.

Each element in a 2D array is accessed using two indices:

* First index = Row
* Second index = Column

---

## 📂 Syntax (C Language)

```c
int arr[3][4];  // Declares a 2D array with 3 rows and 4 columns
```

### Initialization

```c
int arr[3][4] = {
    {10, 20, 30, 40},
    {50, 60, 70, 80},
    {90, 100, 110, 120}
};
```

Accessing `arr[2][3]` will give `120`.

---

## 💡 Key Properties

| Property               | Description                              |
| ---------------------- | ---------------------------------------- |
| Fixed-size             | You must declare size at compile time    |
| Contiguous memory      | Stored in **row-major order**            |
| Access via two indices | `arr[i][j]` accesses row *i*, column *j* |

---

## 📊 Visual Representation in Memory (Row-Major Order)

If you initialize:

```c
int arr[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Memory Layout (Contiguous):

```
Index:   0   1   2   3   4   5
Value:   1   2   3   4   5   6
```

Access:

* `arr[0][0]` = 1
* `arr[0][1]` = 2
* `arr[1][0]` = 4

---

## ⏱️ Looping Through a 2D Array

```c
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        printf("%d ", arr[i][j]);
    }
    printf("\n");
}
```

---

## 📅 Use Cases of 2D Arrays

| Real-world Example      | How 2D Array Helps               |
| ----------------------- | -------------------------------- |
| Excel Sheets            | Rows and columns of data         |
| Chessboard or Game Grid | Board state with positions       |
| Images (grayscale)      | Pixel matrix                     |
| Seating Chart           | Track guests' positions          |
| Matrices in Math        | Matrix operations like transpose |

---

## 📈 2D Array vs 1D Array

| Feature       | 1D Array       | 2D Array         |
| ------------- | -------------- | ---------------- |
| Structure     | Linear list    | Table (grid)     |
| Access        | `arr[i]`       | `arr[i][j]`      |
| Visualization | Line           | Rows and columns |
| Storage       | Row-by-row (C) | Row-major format |

---

## 🔎 Bonus: 2D Arrays in Python

Python doesn't have built-in 2D arrays but supports lists of lists:

```python
arr = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

print(arr[1][2])  # Output: 6
```

---

## 📝 Final Summary

* A **2D array** is like a **grid** of rows and columns.
* Elements are accessed as `arr[row][column]`
* Stored in **row-major** order in memory.
* Common in games, matrices, seating plans, and tabular data.

---
