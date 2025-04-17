
# 🧮 Sum Each Row in a Random Matrix

## 📄 Program Description

This C++ program does the following:

1. Prompts the user to enter the number of rows and columns for a 2D matrix.
2. Dynamically allocates memory for a 2D matrix.
3. Fills the matrix with random numbers between 1 and 100.
4. Displays the matrix.
5. Calculates the sum of each row and stores it in a 1D array.
6. Prints the sum of each row.
7. Frees the dynamically allocated memory at the end.

---

## 🧠 Functions Used

| Function | Description |
|---------|-------------|
| `readNumberPositive()` | Reads a positive integer from the user |
| `randomNumber_Fram_To(fram, to)` | Generates a random number between `fram` and `to` |
| `fillArray2TwoDeminonalInRandomNumber(matrix, row, column)` | Fills the matrix with random numbers |
| `summationEachRowInMatrix(matrix, row, column, arrayOfRows)` | Calculates the sum of each row and stores it in a 1D array |
| `printArray2Dimenional(matrix, row, column)` | Prints the 2D matrix |
| `print1DArray_AccordingPromt(message, arrayOfRows, size)` | Prints the sum of each row with a custom message |

---

## 🧾 Sample Output


---

## 🧹 Notes

- The program uses dynamic memory allocation, so it manually releases memory using `delete[]`.
- `srand((unsigned)time(0))` ensures random numbers are different in every run.

---

## 📦 Code Components

- Uses `int** matrix` to create a dynamically allocated 2D matrix.
- Uses `int* array1D` to store the sum of each row.
- Handles user interaction using `cin` and `cout`.

---

Let me know if you want it exported as a `.md` file or PDF 😄



## 🚀 How to Compile and Run the Program

### 📌 Step 1: Save the code to a file
Save your C++ code in a file named `sum_rows_matrix.cpp`.

### 📌 Step 2: Open your terminal or command prompt

### 📌 Step 3: Compile the code using `g++`
```bash
g++ sum_rows_matrix.cpp -o sum_matrix
```
### 📌 Step 4: Run the compiled program

```bash
./sum_matrix
```



