# Welcome to Red-Black Tree Implementation 👋

This is a C++ project implementing a **Red-Black Tree (Árvore Rubro-Negra)**, a fundamental self-balancing binary search tree data structure. This project is designed to efficiently store and manage ordered data, ensuring that search, insertion, and deletion operations maintain optimal performance, even with large datasets.

## About the Project

Red-Black Trees are widely used in computing because they guarantee that the tree remains balanced, preventing worst-case scenarios that can make standard binary search trees slow. This implementation showcases the core logic behind these complex yet highly efficient data structures.

### Features

  * **Self-Balancing:** Automatically rebalances the tree after insertions and deletions to maintain its logarithmic height ($O(\\log n)$), ensuring efficient operations.
  * **Node Coloring:** Implements the red and black coloring rules to maintain tree properties, crucial for balance.
  * **Rotations & Color Flips:** Includes the necessary rotation (left, right, double left, double right) and color flip operations to rebalance the tree.
  * **Insertion (`insere`):** Adds new integer values to the tree while preserving its Red-Black properties.
  * **Deletion (`remove`):** Removes existing integer values from the tree, handling various node configurations and rebalancing the tree afterwards.
  * **Search (`buscar`):** Efficiently locates a specific integer value within the tree.
  * **In-order Traversal (`imprimir`):** Prints all elements in the tree in ascending order.

### Core Concepts

The project relies on strict rules to maintain balance and efficiency:

  * Every node is either red or black.
  * The root is black.
  * Every leaf (NULL/nullptr) is black.
  * If a node is red, then both its children are black.
  * All simple paths from a node to descendant leaves contain the same number of black nodes.

## How it Works

The project is structured around the `ArvorePV` class, which manages the tree's operations and nodes.

1.  **Node Representation:** Each node (`No`) stores an integer `val`, pointers to its `esq` (left child) and `dir` (right child), and a `cor` (color - red or black).
2.  **Insertion Logic:** When a new node is `insere`d, it's initially marked **red**. If this violates any Red-Black properties (e.g., a red parent with a red child), the `balancear` method is called.
3.  **Deletion Logic:** The `remove` method handles different scenarios (leaf node, one child, two children) and, crucially, also calls `balancear` to re-establish tree properties after a node is removed.
4.  **Balance Operations:** The `balancear` method orchestrates the rebalancing using helper functions:
      * **`rotesq` (Left Rotation) & `rotdir` (Right Rotation):** Adjust tree structure.
      * **`rot2esq` (Double Left Rotation) & `rot2dir` (Double Right Rotation):** More complex rotations for specific imbalance cases.
      * **`TrocaCor` (Color Flip):** Changes node colors to resolve violations.
5.  **Search & Traversal:** The `buscar` method efficiently finds elements, and `imprimir` performs an in-order traversal to list elements sorted.

## Getting Started

To compile and run this project, you will need a C++ compiler.

### Compilation

Navigate to the project's root directory in your terminal and compile the source files. Assuming your main file is `main.cpp` and your class implementations are in `Arvore Preta Vermelha.cpp` (or `ArvorePV.cpp`), you might use:

```bash
g++ -o main main.cpp "Arvore Preta Vermelha.cpp" -std=c++11
```

  * `-o main`: Specifies the output executable name as `main`.
  * `main.cpp "Arvore Preta Vermelha.cpp"`: Includes your source files.
      * *Note: If your file name has spaces, remember to put it in quotes like `"Arvore Preta Vermelha.cpp"`.*
      * *Consider renaming files without spaces (e.g., `ArvorePV.cpp`) for easier compilation.*
  * `-std=c++11`: Ensures compatibility with C++11 features (you can use `c++17` or `c++20` for newer standards if desired).

### Execution

After successful compilation, run the executable:

```bash
./main
```

The `main.cpp` file contains example insertions and deletions to demonstrate the tree's functionality.

## License

This project is licensed under the [MIT License](https://www.google.com/search?q=LICENSE).

**Copyright (c) 2025 Ryan Pablo Coelho Luiz**

For more details on the terms of use, please refer to the `LICENSE` file in the root of this repository.

## Author

This project was conceived and developed by:

**MonkeyShock**
GitHub: (https://github.com/MonkeyShock)
