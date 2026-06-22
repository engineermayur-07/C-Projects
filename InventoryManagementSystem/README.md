<div align="center">

# 📦 Inventory Management System

**A terminal-based inventory control system built in C++ using Linked Lists**

[![C++](https://img.shields.io/badge/C++-17-00599C?style=flat&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-informational?style=flat)](https://github.com)

*Efficient inventory tracking — powered by Data Structures*

</div>

---

## 📖 About The Project

**Inventory Management System** is a command-line application written in C++ that allows businesses or individuals to manage their product inventory efficiently. The system handles stock addition, selling, restocking, and viewing — all backed by a **singly linked list** data structure and persisted to a **CSV file** across sessions.

Built as a practical application of core Data Structures and File I/O concepts covered in the B.Tech CSE curriculum.

---

## ✨ Features

- **Add new products** — register a product with a unique ID, name, and initial quantity
- **Sell products** — deduct sold units from stock with validation against available quantity
- **Restock products** — add incoming stock units to an existing product
- **View inventory** — display all products in a formatted table (Product ID, Name, Quantity)
- **Persistent storage** — all inventory data is saved to and loaded from `inventory.csv` automatically
- **Duplicate prevention** — blocks addition of products with an existing name or ID
- **Input validation** — rejects negative quantities, zero-unit sales, and overselling
- **Auto-save on exit** — unsaved changes are written to disk before the program exits

---

## 🗂️ Data Structure

The core of the system is a **singly linked list** where each node represents one product:

```
HEAD → [ ID: 101 | "Rice" | Qty: 200 ] → [ ID: 102 | "Sugar" | Qty: 50 ] → NULL
```

```cpp
struct node {
    int product_id;
    string product_name;
    int quantity;
    struct node *next;
};
```

New nodes are inserted at the **head** of the list for O(1) insertion. Search operations traverse the list linearly — O(n).

---

## 🛠️ Tech Stack

| Component | Technology |
|---|---|
| Language | C++ (Standard: C++17) |
| Data Structure | Singly Linked List |
| Persistence | CSV file I/O (`fstream`) |
| String Parsing | `stringstream` |
| Build | g++ / any standard C++ compiler |

---

## 📁 Project Structure

```
InventoryManagementSystem/
│
├── main.cpp              # Full program — linked list, file I/O, menu
└── inventory.csv         # Auto-generated data file (created on first save)
```

> **Note:** The program reads from and writes to `InventoryManagementSystem/inventory.csv`. Make sure the folder exists before running, or the CSV path is adjusted to your environment.

---

## 🚀 Getting Started

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

## 🖥️ Program Flow

```
On startup   →  load_data() reads inventory.csv into the linked list

Main Menu    →  1. View Inventory         — display all products
             →  2. Add New Product        — register new product (validates name + ID uniqueness)
             →  3. Sell Product           — deduct stock (validates quantity availability)
             →  4. Restock Product        — add units to existing product
             →  5. Save Changes           — write linked list back to CSV
             →  6. Exit                   — auto-save and terminate

On exit      →  write_data() saves all nodes to inventory.csv
```

---

## 📋 Menu Walkthrough

### 1. View Inventory
Prints all products in a formatted three-column table:
```
---------- INVENTORY ----------

 Product ID          Product         Quantity
 101                 Rice            200
 102                 Sugar           50
```

### 2. Add New Product
Prompts for name, ID, and quantity. Validates:
- Product name is not already registered
- Product ID is not already in use
- Quantity is non-negative

### 3. Sell Product
Prompts for product name and units sold. Validates:
- Product exists in inventory
- Quantity sold does not exceed current stock
- Quantity is positive

### 4. Restock Product
Prompts for product name and units to add. Validates:
- Product exists in inventory
- Restock quantity is positive

### 5. Save Changes
Writes the entire linked list to `inventory.csv` in the format:
```
product_id,product_name,quantity
101,Rice,200
102,Sugar,50
```

---

## 📄 CSV File Format

The persistence file `inventory.csv` uses a simple three-column format:

```
product_id,product_name,quantity
101,Rice,200
102,Sugar,50
103,Wheat Flour,150
```

The header row is skipped on load. Each subsequent row is parsed via `stringstream` and inserted into the linked list as a new node.

---

## ⚠️ Known Limitations

- No deletion feature — products cannot be removed from the inventory (planned for future)
- Linear search O(n) — performance degrades with very large inventories (a hash map or BST would improve this)
- Single-user — no concurrent access or multi-session support
- Plain-text password — no authentication layer
- CSV path is hardcoded — adjust `InventoryManagementSystem/inventory.csv` in `write_data()` and `load_data()` if running from a different working directory

---

## 🔮 Future Improvements

- [ ] Delete / discontinue product feature
- [ ] Low stock alerts (threshold-based warnings)
- [ ] Search by product ID from the menu
- [ ] Category-based product grouping
- [ ] Export summary report to PDF or formatted text
- [ ] Replace linear search with a hash map for O(1) lookups
- [ ] GUI frontend using Qt or a web interface

---

## 🤝 Contributing

Contributions and suggestions are welcome!

1. Fork the repository
2. Create a branch: `git checkout -b feature/your-feature`
3. Commit: `git commit -m "Add your feature"`
4. Push: `git push origin feature/your-feature`
5. Open a Pull Request

---

## 👤 Developer

<table>
  <tr>
    <td align="center" width="100%">
      <b>Mayur B. Gund</b><br>
      SY B.Tech Computer Science Engineering<br>
      Sanjivani College of Engineering<br><br>
      <a href="https://linkedin.com/in/mgund1920">linkedin.com/in/mgund1920</a><br>
      <a href="mailto:mgund1920@gmail.com">mgund1920@gmail.com</a><br>
      <a href="https://github.com/engineermayur-07">github.com/engineermayur-07</a>
    </td>
  </tr>
</table>

---

 

<div align="center">
  <i>Built with C++ — Powered by Data Structures</i>
</div>
