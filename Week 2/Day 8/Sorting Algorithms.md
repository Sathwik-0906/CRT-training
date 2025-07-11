# Sorting Algorithms Guide with Code
---

## 🎯 Introduction to Sorting {#introduction}

### **What is Sorting?**
**Real Definition:** Sorting is the process of arranging elements in a collection according to a specified order (ascending or descending) based on comparison criteria.

**Story Definition:** Imagine you're a librarian with thousands of books scattered randomly on tables. Sorting is like organizing these books alphabetically by title, by author, or by publication date so that anyone can find what they're looking for quickly and efficiently.

### **Classification of Sorting Algorithms**

| **Category** | **Types** | **Description** |
|--------------|-----------|-----------------|
| **Stability** | Stable / Unstable | Maintains relative order of equal elements |
| **Memory** | In-place / Out-of-place | Uses O(1) vs O(n) extra space |
| **Method** | Comparison / Non-comparison | Direct comparison vs property-based |

---

## 🫧 Bubble Sort {#bubble-sort}

### **Definition & Story**
**Real Definition:** A simple comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they're in the wrong order.

**Story:** Think of bubbles rising in a glass of soda. The largest bubble (element) slowly "bubbles up" to the top through repeated comparisons with its neighbors.

### **Algorithm Steps**
1. Compare adjacent elements
2. Swap if left > right (for ascending order)
3. Repeat for all elements
4. Continue until no swaps needed

### **Code Implementation**

```python
def bubble_sort(arr):
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        # Flag to optimize - if no swapping occurs, array is sorted
        swapped = False
        
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        # If no swapping occurred, array is sorted
        if not swapped:
            break
    
    return arr

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90]
print("Original array:", arr)
sorted_arr = bubble_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** 
  - Best Case: O(n) - already sorted
  - Average Case: O(n²)
  - Worst Case: O(n²) - reverse sorted
- **Space Complexity:** O(1) - in-place algorithm

### **Memory Management**
- Uses only a few variables for swapping
- No additional arrays needed
- Minimal memory overhead

### **Visual Representation**
```
Initial: [64, 34, 25, 12, 22, 11, 90]

Pass 1: [34, 25, 12, 22, 11, 64, 90] ← 64 bubbles up
Pass 2: [25, 12, 22, 11, 34, 64, 90] ← 34 bubbles up
Pass 3: [12, 22, 11, 25, 34, 64, 90] ← 25 bubbles up
Pass 4: [12, 11, 22, 25, 34, 64, 90] ← 22 bubbles up
Pass 5: [11, 12, 22, 25, 34, 64, 90] ← 12 bubbles up
```

---

## 🎯 Selection Sort {#selection-sort}

### **Definition & Story**
**Real Definition:** Finds the minimum element from the unsorted portion and places it at the beginning of the sorted portion.

**Story:** Like choosing players for a team by always picking the shortest person first. You scan everyone, find the shortest, put them in line, then find the next shortest from the remaining people.

### **Algorithm Steps**
1. Find minimum element in unsorted array
2. Swap with first element
3. Move boundary of sorted/unsorted portions
4. Repeat until array is sorted

### **Code Implementation**

```python
def selection_sort(arr):
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        # Find the minimum element in remaining unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr

# Example usage
arr = [64, 25, 12, 22, 11, 90]
print("Original array:", arr)
sorted_arr = selection_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** O(n²) for all cases
- **Space Complexity:** O(1) - in-place algorithm

### **Memory Management**
- Uses constant extra space
- Only needs variables for indexing and swapping
- No recursive calls or additional arrays

### **Visual Representation**
```
Initial: [64, 25, 12, 22, 11, 90]

Step 1: [11, 25, 12, 22, 64, 90] ← 11 selected and moved to front
Step 2: [11, 12, 25, 22, 64, 90] ← 12 selected from remaining
Step 3: [11, 12, 22, 25, 64, 90] ← 22 selected from remaining
Step 4: [11, 12, 22, 25, 64, 90] ← 25 already in position
Step 5: [11, 12, 22, 25, 64, 90] ← 64 already in position
```

---

## 📥 Insertion Sort {#insertion-sort}

### **Definition & Story**
**Real Definition:** Builds the final sorted array one element at a time by inserting each element into its correct position among the previously sorted elements.

**Story:** Like sorting playing cards in your hand. You pick up cards one by one and insert each new card into its correct position among the cards you've already sorted.

### **Algorithm Steps**
1. Start with second element (first is considered sorted)
2. Compare with elements in sorted portion
3. Shift larger elements to the right
4. Insert current element in correct position
5. Repeat for all elements

### **Code Implementation**

```python
def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be inserted
        j = i - 1     # Index of the last element in sorted portion
        
        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Place key at its correct position
        arr[j + 1] = key
    
    return arr

# Example usage
arr = [5, 2, 4, 6, 1, 3]
print("Original array:", arr)
sorted_arr = insertion_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:**
  - Best Case: O(n) - already sorted
  - Average Case: O(n²)
  - Worst Case: O(n²) - reverse sorted
- **Space Complexity:** O(1) - in-place algorithm

### **Memory Management**
- Uses constant extra space
- No additional arrays required
- Efficient for small datasets

### **Visual Representation**
```
Initial: [5, 2, 4, 6, 1, 3]

Step 1: [2, 5, 4, 6, 1, 3] ← Insert 2 into sorted portion [5]
Step 2: [2, 4, 5, 6, 1, 3] ← Insert 4 into sorted portion [2, 5]
Step 3: [2, 4, 5, 6, 1, 3] ← 6 already in correct position
Step 4: [1, 2, 4, 5, 6, 3] ← Insert 1 at the beginning
Step 5: [1, 2, 3, 4, 5, 6] ← Insert 3 into correct position
```

---

## 🔀 Merge Sort {#merge-sort}

### **Definition & Story**
**Real Definition:** A divide-and-conquer algorithm that divides the array into two halves, recursively sorts both halves, then merges them back together.

**Story:** Like organizing a massive library by dividing it into smaller sections, sorting each section separately, then carefully merging the sorted sections back together while maintaining order.

### **Algorithm Steps**
1. Divide array into two halves
2. Recursively sort both halves
3. Merge the sorted halves
4. Base case: single element arrays are already sorted

### **Code Implementation**

```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    # Divide the array into two halves
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]
    
    # Recursively sort both halves
    left = merge_sort(left)
    right = merge_sort(right)
    
    # Merge the sorted halves
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    
    # Compare elements from both arrays and merge in sorted order
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    # Add remaining elements
    result.extend(left[i:])
    result.extend(right[j:])
    
    return result

# Example usage
arr = [38, 27, 43, 3, 9, 82, 10]
print("Original array:", arr)
sorted_arr = merge_sort(arr)
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** O(n log n) for all cases
- **Space Complexity:** O(n) - requires additional arrays for merging

### **Memory Management**
- Uses O(n) auxiliary space for temporary arrays
- Recursive calls use O(log n) stack space
- Not in-place due to merging process

### **Visual Representation**
```
Initial: [38, 27, 43, 3, 9, 82, 10]

Divide Phase:
[38, 27, 43, 3] | [9, 82, 10]
[38, 27] [43, 3] | [9, 82] [10]
[38] [27] [43] [3] | [9] [82] [10]

Conquer Phase:
[27, 38] [3, 43] | [9, 82] [10]
[3, 27, 38, 43] | [9, 10, 82]
[3, 9, 10, 27, 38, 43, 82]
```

---

## ⚡ Quick Sort {#quick-sort}

### **Definition & Story**
**Real Definition:** A divide-and-conquer algorithm that picks a pivot element and partitions the array around it, then recursively sorts the sub-arrays.

**Story:** Like organizing a group of people by height. You pick someone as a reference (pivot), ask everyone shorter to stand on the left and everyone taller on the right, then repeat this process for each group.

### **Algorithm Steps**
1. Choose a pivot element
2. Partition array around pivot
3. Recursively sort elements before pivot
4. Recursively sort elements after pivot

### **Code Implementation**

```python
def quick_sort(arr, low=0, high=None):
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        # Partition the array and get pivot index
        pivot_index = partition(arr, low, high)
        
        # Recursively sort elements before and after partition
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)
    
    return arr

def partition(arr, low, high):
    # Choose the rightmost element as pivot
    pivot = arr[high]
    
    # Index of smaller element (indicates right position of pivot)
    i = low - 1
    
    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    # Place pivot in correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Example usage
arr = [10, 7, 8, 9, 1, 5]
print("Original array:", arr)
sorted_arr = quick_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:**
  - Best Case: O(n log n) - good pivot selection
  - Average Case: O(n log n)
  - Worst Case: O(n²) - poor pivot selection
- **Space Complexity:** O(log n) - for recursion stack

### **Memory Management**
- In-place partitioning
- Recursive calls use stack space
- Space usage depends on recursion depth

### **Visual Representation**
```
Initial: [10, 7, 8, 9, 1, 5]
Pivot: 5

Partition: [1] [5] [10, 7, 8, 9]
          (<5)    (>5)

Recursively sort left: [1] (already sorted)
Recursively sort right: [10, 7, 8, 9] with pivot 9
                       [7, 8] [9] [10]
                       
Final: [1, 5, 7, 8, 9, 10]
```

---

## 🏔️ Heap Sort {#heap-sort}

### **Definition & Story**
**Real Definition:** Uses a binary heap data structure to sort elements by repeatedly extracting the maximum (or minimum) element.

**Story:** Like a tournament where the strongest player always rises to the top. You organize players in a hierarchy where each parent is stronger than their children, crown the champion, remove them, reorganize, and repeat.

### **Algorithm Steps**
1. Build a max heap from the array
2. Extract maximum element (root)
3. Place it at the end of sorted portion
4. Restore heap property
5. Repeat until heap is empty

### **Code Implementation**

```python
def heap_sort(arr):
    n = len(arr)
    
    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        # Move current root to end
        arr[0], arr[i] = arr[i], arr[0]
        
        # Call heapify on the reduced heap
        heapify(arr, i, 0)
    
    return arr

def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    left = 2 * i + 1     # left child
    right = 2 * i + 2    # right child
    
    # If left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    # If right child exists and is greater than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        
        # Recursively heapify the affected sub-tree
        heapify(arr, n, largest)

# Example usage
arr = [4, 10, 3, 5, 1]
print("Original array:", arr)
sorted_arr = heap_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** O(n log n) for all cases
- **Space Complexity:** O(1) - in-place algorithm

### **Memory Management**
- Uses array representation of heap
- No additional arrays needed
- Constant space complexity

### **Visual Representation**
```
Initial: [4, 10, 3, 5, 1]

Build Max Heap:
       10
      /  \
     5    3
    / \
   4   1
Array: [10, 5, 3, 4, 1]

Extract Max (10): [1, 5, 3, 4] | [10]
Heapify: [5, 4, 3, 1] | [10]
Extract Max (5): [1, 4, 3] | [5, 10]
Continue until sorted: [1, 3, 4, 5, 10]
```

---

## 🔢 Counting Sort {#counting-sort}

### **Definition & Story**
**Real Definition:** A non-comparison based algorithm that counts the occurrences of each distinct element and uses this information to place elements in sorted order.

**Story:** Like counting votes in an election. You count how many votes each candidate got, then announce the results in order. No need to compare individual votes - just count and arrange.

### **Algorithm Steps**
1. Find the range of input values
2. Create a count array
3. Count occurrences of each element
4. Modify count array to store actual positions
5. Build output array using count array

### **Code Implementation**

```python
def counting_sort(arr):
    # Find the range of input
    max_val = max(arr)
    min_val = min(arr)
    range_val = max_val - min_val + 1
    
    # Create count array
    count = [0] * range_val
    output = [0] * len(arr)
    
    # Count occurrences of each element
    for num in arr:
        count[num - min_val] += 1
    
    # Modify count array to store actual positions
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    
    # Build output array
    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i] - min_val] - 1] = arr[i]
        count[arr[i] - min_val] -= 1
    
    return output

# Example usage
arr = [4, 2, 2, 8, 3, 3, 1]
print("Original array:", arr)
sorted_arr = counting_sort(arr)
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** O(n + k), where k is the range of input
- **Space Complexity:** O(k) - for count array

### **Memory Management**
- Requires additional space for count array
- Space depends on range of input values
- Efficient when range is small

### **Visual Representation**
```
Initial: [4, 2, 2, 8, 3, 3, 1]
Range: 1 to 8

Count Array: [0, 1, 2, 2, 1, 0, 0, 0, 1]
Index:       [0, 1, 2, 3, 4, 5, 6, 7, 8]
            (count of each number)

Position Array: [0, 1, 3, 5, 6, 6, 6, 6, 7]
               (cumulative positions)

Final: [1, 2, 2, 3, 3, 4, 8]
```

---

## 📊 Radix Sort {#radix-sort}

### **Definition & Story**
**Real Definition:** A non-comparison sorting algorithm that sorts integers by processing individual digits from least significant to most significant.

**Story:** Like sorting a deck of cards by organizing them first by suit, then by rank within each suit. You sort by the rightmost digit first, then by the next digit, and so on.

### **Algorithm Steps**
1. Find the maximum number to determine digit count
2. Sort by each digit using counting sort
3. Start from least significant digit
4. Move to more significant digits

### **Code Implementation**

```python
def radix_sort(arr):
    # Find the maximum number to know number of digits
    max_num = max(arr)
    
    # Do counting sort for every digit
    exp = 1
    while max_num // exp > 0:
        counting_sort_for_radix(arr, exp)
        exp *= 10
    
    return arr

def counting_sort_for_radix(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    
    # Count occurrences of each digit
    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1
    
    # Change count[i] to actual position
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    # Build output array
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1
    
    # Copy output array to arr
    for i in range(n):
        arr[i] = output[i]

# Example usage
arr = [170, 45, 75, 90, 2, 802, 24, 66]
print("Original array:", arr)
sorted_arr = radix_sort(arr.copy())
print("Sorted array:", sorted_arr)
```

### **Complexity Analysis**
- **Time Complexity:** O(d × (n + k)), where d is number of digits
- **Space Complexity:** O(n + k) - for counting sort subroutine

### **Memory Management**
- Uses auxiliary arrays for counting sort
- Space complexity depends on base used
- Efficient for integers with limited digits

### **Visual Representation**
```
Initial: [170, 45, 75, 90, 2, 802, 24, 66]

Sort by 1s place: [170, 90, 2, 802, 24, 45, 75, 66]
Sort by 10s place: [2, 802, 24, 45, 66, 170, 75, 90]
Sort by 100s place: [2, 24, 45, 66, 75, 90, 170, 802]
```

---

## 📊 Comparison Summary {#comparison-summary}

### **Complexity Comparison Table**

| **Algorithm** | **Best Case** | **Average Case** | **Worst Case** | **Space** | **Stable** | **In-Place** |
|---------------|---------------|------------------|----------------|-----------|------------|--------------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ No | ✅ Yes |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ Yes | ✅ Yes |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ Yes | ❌ No |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ No | ✅ Yes |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ No | ✅ Yes |
| **Counting Sort** | O(n + k) | O(n + k) | O(n + k) | O(k) | ✅ Yes | ❌ No |
| **Radix Sort** | O(d(n + k)) | O(d(n + k)) | O(d(n + k)) | O(n + k) | ✅ Yes | ❌ No |

### **Performance Characteristics**

```
🐌 Slow (O(n²)): Bubble, Selection, Insertion
⚡ Fast (O(n log n)): Merge, Quick, Heap
🚀 Super Fast (O(n)): Counting, Radix (special cases)
```

---

## 💾 Memory Management {#memory-management}

### **Stack Memory Usage**
- **Recursive algorithms** (Quick Sort, Merge Sort) use stack space
- **Stack overflow** risk with deep recursion
- **Iterative versions** available to reduce stack usage

### **Heap Memory Usage**
- **Out-of-place algorithms** require additional arrays
- **Memory allocation** overhead for large datasets
- **Garbage collection** considerations

### **Cache Performance**
- **Sequential access** patterns are cache-friendly
- **Random access** patterns cause cache misses
- **Locality of reference** affects real-world performance

### **Memory-Optimized Strategies**
1. **Hybrid approaches** for different data sizes
2. **In-place variants** to minimize memory usage
3. **External sorting** for data larger than memory
4. **Parallel processing** for multi-core systems

---

## 🎯 When to Use Each Algorithm {#when-to-use}

### **📏 Small Datasets (n < 50)**
- **Insertion Sort**: Simple and efficient for small arrays
- **Selection Sort**: When memory writes are costly

### **📊 Medium Datasets (50 < n < 1000)**
- **Quick Sort**: Good average performance
- **Merge Sort**: When stability is required

### **📈 Large Datasets (n > 1000)**
- **Merge Sort**: Guaranteed O(n log n) performance
- **Heap Sort**: When worst-case performance matters
- **Quick Sort**: With good pivot selection strategy

### **🔧 Special Cases**
- **Nearly sorted data**: Insertion Sort (O(n) best case)
- **Limited range integers**: Counting Sort
- **Large integers**: Radix Sort
- **Memory constraints**: Heap Sort (O(1) space)
- **Stability required**: Merge Sort or Insertion Sort

### **💡 Implementation Tips**

#### **General Guidelines**
1. **Choose appropriate algorithm** based on data characteristics
2. **Consider memory constraints** and available space
3. **Test with different data patterns** (sorted, reverse, random)
4. **Profile and benchmark** with real data

#### **Performance Optimization**
- **Avoid unnecessary comparisons** in inner loops
- **Use efficient pivot selection** for Quick Sort
- **Implement iterative versions** to reduce stack usage
- **Consider cache-friendly implementations**
- **Use hybrid approaches** (e.g., Introsort combines Quick Sort and Heap Sort)

---

## 🎉 Conclusion

This comprehensive guide provides you with:
- ✅ **Complete implementations** of all major sorting algorithms
- ✅ **Time and space complexity** analysis
- ✅ **Memory management** considerations
- ✅ **Visual representations** for better understanding
- ✅ **Practical guidance** on when to use each algorithm

Each algorithm has its strengths and ideal use cases. Understanding these characteristics will help you make informed decisions in your programming projects!

---