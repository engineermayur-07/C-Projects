<div align="center">

<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=28&pause=1000&color=00C9A7&center=true&vCenter=true&width=600&lines=📦+Inventory+Management+System;Built+with+C%2B%2B+%26+Linked+Lists" alt="Typing SVG" />

<br>

**A terminal-based inventory control system built in C++ using Linked Lists**

<br>

[![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-6C63FF?style=for-the-badge)](https://github.com)
[![Status](https://img.shields.io/badge/Status-Active-00C9A7?style=for-the-badge)](https://github.com)

<br>

*Efficient inventory tracking — powered by Data Structures*

</div>

---

## <img src="https://img.shields.io/badge/-%F0%9F%93%96%20About%20The%20Project-1a1a2e?style=for-the-badge&labelColor=0077B6&color=0096C7" />

**Inventory Management System** is a command-line application written in C++ that allows businesses or individuals to manage their product inventory efficiently. The system handles stock addition, selling, restocking, and viewing — all backed by a **singly linked list** data structure and persisted to a **CSV file** across sessions.

Built as a practical application of core **Data Structures and File I/O** concepts covered in the B.Tech CSE curriculum.

---

## <img src="https://img.shields.io/badge/-%E2%9C%A8%20Features-1a1a2e?style=for-the-badge&labelColor=7B2D8B&color=9B59B6" />

| # | Feature | Description |
|---|---|---|
| 1 | ➕ Add new products | Register a product with a unique ID, name, and initial quantity |
| 2 | 🛒 Sell products | Deduct sold units with validation against available stock |
| 3 | 📥 Restock products | Add incoming units to an existing product |
| 4 | 👁️ View inventory | Display all products in a formatted table |
| 5 | 💾 Persistent storage | Auto load/save inventory data from `inventory.csv` |
| 6 | 🚫 Duplicate prevention | Blocks products with an existing name or ID |
| 7 | ✅ Input validation | Rejects negative quantities, zero-unit sales, and overselling |
| 8 | 🔒 Auto-save on exit | Unsaved changes are written to disk before program exits |

---

## <img src="https://img.shields.io/badge/-%F0%9F%97%82%EF%B8%8F%20Data%20Structure-1a1a2e?style=for-the-badge&labelColor=C0392B&color=E74C3C" />

The core of the system is a **singly linked list** where each node represents one product:

```
HEAD → [ ID: 101 | "Rice"  | Qty: 200 ]
              ↓
       [ ID: 102 | "Sugar" | Qty:  50 ]
              ↓
            NULL
```

```cpp
struct node {
    int product_id;
    string product_name;
    int quantity;
    struct node *next;
};
```

> New nodes are inserted at the **head** for O(1) insertion. Search traverses the list linearly — O(n).

---

## <img src="https://img.shields.io/badge/-%F0%9F%9B%A0%EF%B8%8F%20Tech%20Stack-1a1a2e?style=for-the-badge&labelColor=117A65&color=1ABC9C" />

| Component | Technology |
|---|---|
| Language | C++ (Standard: C++17) |
| Data Structure | Singly Linked List |
| Persistence | CSV file I/O (`fstream`) |
| String Parsing | `stringstream` |
| Build | g++ / any standard C++ compiler |

---

## <img src="https://img.shields.io/badge/-%F0%9F%93%81%20Project%20Structure-1a1a2e?style=for-the-badge&labelColor=1A5276&color=2980B9" />

```
InventoryManagementSystem/
│
├── main.cpp              # Full program — linked list, file I/O, menu
└── inventory.csv         # Auto-generated data file (created on first save)
```

> **Note:** The program reads/writes to `InventoryManagementSystem/inventory.csv`. Ensure the folder exists, or update the path in `write_data()` and `load_data()` to match your environment.

---

## <img src="https://img.shields.io/badge/-%F0%9F%9A%80%20Getting%20Started-1a1a2e?style=for-the-badge&labelColor=6E2FBF&color=8E44AD" />

### Prerequisites

- A C++ compiler: `g++`, `clang++`, or MSVC
- C++17 support or later

### Compile & Run

```bash
# 1. Clone the repository
git clone https://github.com/engineermayur-07/Inventory-Management-System.git
cd Inventory-Management-System

# 2. Compile
g++ -std=c++17 -o inventory main.cpp

# 3. Run
./inventory         # Linux / macOS
inventory.exe       # Windows
```

---

## <img src="https://img.shields.io/badge/-%F0%9F%96%A5%EF%B8%8F%20Program%20Flow-1a1a2e?style=for-the-badge&labelColor=784212&color=A04000" />

```
On startup   →  load_data()     reads inventory.csv into the linked list

Main Menu    →  1. View Inventory         — display all products
             →  2. Add New Product        — register product (validates name + ID uniqueness)
             →  3. Sell Product           — deduct stock (validates quantity availability)
             →  4. Restock Product        — add units to existing product
             →  5. Save Changes           — write linked list back to CSV
             →  6. Exit                   — auto-save and terminate

On exit      →  write_data()    saves all nodes back to inventory.csv
```

---

## <img src="https://img.shields.io/badge/-%F0%9F%93%8B%20Menu%20Walkthrough-1a1a2e?style=for-the-badge&labelColor=0B6E4F&color=148F77" />

### 1️⃣ View Inventory
Prints all products in a formatted three-column table:
```
--------- INVENTORY ----------

 Product ID          Product         Quantity
 101                 Rice            200
 102                 Sugar           50
 103                 Wheat Flour     150
```

### 2️⃣ Add New Product
Prompts for name, ID, and quantity. Validates:
- Product name is not already registered
- Product ID is not already in use
- Quantity is non-negative

### 3️⃣ Sell Product
Prompts for product name and units sold. Validates:
- Product exists in inventory
- Quantity sold does not exceed current stock
- Quantity is positive

### 4️⃣ Restock Product
Prompts for product name and units to add. Validates:
- Product exists in inventory
- Restock quantity is positive

### 5️⃣ Save Changes
Writes the entire linked list to `inventory.csv`:
```
product_id,product_name,quantity
101,Rice,200
102,Sugar,50
103,Wheat Flour,150
```

### 6️⃣ Exit
Auto-saves all changes before termination.

---

## <img src="https://img.shields.io/badge/-%F0%9F%93%84%20CSV%20File%20Format-1a1a2e?style=for-the-badge&labelColor=1C5985&color=2471A3" />

The persistence file `inventory.csv` uses a simple three-column format:

```csv
product_id,product_name,quantity
101,Rice,200
102,Sugar,50
103,Wheat Flour,150
```

The **header row is skipped** on load. Each subsequent row is parsed via `stringstream` and inserted into the linked list as a new node.

---

## <img src="https://img.shields.io/badge/-%E2%9A%A0%EF%B8%8F%20Known%20Limitations-1a1a2e?style=for-the-badge&labelColor=7D6608&color=B7950B" />

- No delete feature — products cannot be removed from the inventory
- Linear search O(n) — performance degrades with very large inventories
- Single-user only — no concurrent access or multi-session support
- No authentication layer
- CSV path is hardcoded — adjust in `write_data()` and `load_data()` if needed

---

## <img src="https://img.shields.io/badge/-%F0%9F%94%AE%20Future%20Improvements-1a1a2e?style=for-the-badge&labelColor=4A235A&color=7D3C98" />

- [ ] Delete / discontinue product feature
- [ ] Low stock alerts (threshold-based warnings)
- [ ] Search by product ID from the menu
- [ ] Category-based product grouping
- [ ] Export summary report to formatted text or PDF
- [ ] Replace linear search with a hash map for O(1) lookups
- [ ] GUI frontend using Qt or a web interface

---

## <img src="https://img.shields.io/badge/-%F0%9F%A4%9D%20Contributing-1a1a2e?style=for-the-badge&labelColor=1A5276&color=154360" />

Contributions and suggestions are welcome!

1. Fork the repository
2. Create a branch: `git checkout -b feature/your-feature`
3. Commit: `git commit -m "Add your feature"`
4. Push: `git push origin feature/your-feature`
5. Open a Pull Request

---

## <img src="https://img.shields.io/badge/-%F0%9F%91%A4%20Developer-1a1a2e?style=for-the-badge&labelColor=1B4F72&color=21618C" />

<table>
  <tr>
    <td align="center">
      <b>Mayur B. Gund</b><br>
      SY B.Tech Computer Science Engineering<br>
      Sanjivani College of Engineering, Shirdi<br><br>
      <a href="https://linkedin.com/in/mgund1920">
        <img src="https://img.shields.io/badge/LinkedIn-mgund1920-0077B5?style=flat&logo=linkedin&logoColor=white"/>
      </a>&nbsp;
      <a href="mailto:mgund1920@gmail.com">
        <img src="https://img.shields.io/badge/Gmail-mgund1920@gmail.com-D14836?style=flat&logo=gmail&logoColor=white"/>
      </a>&nbsp;
      <a href="https://github.com/engineermayur-07">
        <img src="https://img.shields.io/badge/GitHub-engineermayur--07-181717?style=flat&logo=github&logoColor=white"/>
      </a>
    </td>
  </tr>
</table>

---

 

<div align="center">

<img src="https://img.shields.io/badge/Built%20with-C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
&nbsp;
<img src="https://img.shields.io/badge/Powered%20by-Data%20Structures-E74C3C?style=for-the-badge" />

<br><br>

*⭐ If you found this project useful, consider giving it a star!*

</div>
