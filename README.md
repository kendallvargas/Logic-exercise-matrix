# 🧮 Logical Exercise with Matrices and Vectors - Problem Solving

## 📋 Requirements

We are working with an **accumulated investments matrix** defined by:
1. A number of investors categorized by their level of education (CI).
2. A number of processed months (CM).

The matrix dimensions are **CI x CM**, where:
- Rows represent the levels of education.
- Columns represent the processed months.

### 🗂️ User Menu

The program will prompt the user to input:

1. **Number of Education Levels**  
   - Must validate that this number is between **1 and 7**, as defined below:

   | ID  | Education Level          |
   |------|--------------------------|
   | 1    | Primary                  |
   | 2    | Secondary                |
   | 3    | Technical                |
   | 4    | University Bachelor's    |
   | 5    | Bachelor's Degree        |
   | 6    | Master's Degree          |
   | 7    | Doctorate                |

2. **Number of Processed Months**  
   - Must validate that this value is between **1 and 12**.

### 📊 Main Menu Options

The program will display the following menu:

**"Investment Statistics Menu"**

1. 🌀 **Initialize Matrices**  
2. 💰 **Present Investment Data by Education Level**  
3. 📅 **Present Investment Data by Processed Months**  
4. 🚪 **Exit**  



### 📌 Details of Each Menu Option

#### 1️⃣ **Initialize Matrices**
- **Task**:  
  - Initialize the **investments matrix**, with **random values between 1 and 800**, representing accumulated investment amounts.
  - Initialize the **investor matrix**, with **random values between 1 and 30**, representing the number of investors associated with each investment in the first matrix.

- **Output**:  
  Once initialized, both matrices are displayed on the screen.



#### 2️⃣ **Present Investment Data by Education Level**
- **Task**:
  1. Display both matrices.
  2. Traverse the investments matrix and sum up all investments per education level.
  3. Traverse the investor matrix and sum up the investors per education level.

- **Output**:  
  A report showing the total investments and number of investors by education level.



#### 3️⃣ **Present Investment Data by Processed Months**
- **Task**:
  1. Display both matrices.
  2. Traverse the investments matrix and sum up all investments per processed month.
  3. Traverse the investor matrix and sum up the investors per processed month.

- **Output**:  
  A report showing the total investments and number of investors by processed month.



#### 4️⃣ **Exit**
- **Task**:  
  End the program. 👋