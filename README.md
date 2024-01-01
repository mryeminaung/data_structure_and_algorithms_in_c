# ECE 3060 - Data Structures and Algorithms in C

## Introduction

This repository contains the code files developed throughout the semester for the ECE 3060 course on Data Structures and Algorithms in C. Below is a detailed list of implemented data structures and algorithms along with additional implementation details for each.

## Data Structures

### Arrays

- **Description:** Implementation of basic array operations.
- **Files:** `array_operations.c`, `array_operations.h`
- **Functions:**
  - `initialize_array`: Initializes an array with a given size.
  - `insert_element`: Inserts an element at a specified position in the array.
  - `delete_element`: Deletes an element at a specified position in the array.
  - `search_element`: Searches for an element in the array.
  - `display_array`: Displays the elements of the array.

### Linked List

- **Singly Linked List:**

  - **Description:** Implementation and manipulation of singly linked lists.
  - **Files:** `singly_linked_list.c`, `singly_linked_list.h`
  - **Functions:**
    - `create_node`: Creates a new node.
    - `insert_at_beginning`: Inserts a node at the beginning of the list.
    - `insert_at_end`: Inserts a node at the end of the list.
    - `delete_at_position`: Deletes a node at a specified position.
    - `search_element`: Searches for an element in the list.
    - `display_list`: Displays the elements of the list.

- **Doubly Linked List:**

  - **Description:** Implementation and manipulation of doubly linked lists.
  - **Files:** `doubly_linked_list.c`, `doubly_linked_list.h`
  - **Functions:**
    - `create_node`: Creates a new node.
    - `insert_at_beginning`: Inserts a node at the beginning of the list.
    - `insert_at_end`: Inserts a node at the end of the list.
    - `delete_at_position`: Deletes a node at a specified position.
    - `search_element`: Searches for an element in the list.
    - `display_list`: Displays the elements of the list.

- **Circular Linked List:**
  - **Description:** Implementation and manipulation of circular linked lists.
  - **Files:** `circular_linked_list.c`, `circular_linked_list.h`
  - **Functions:**
    - `create_node`: Creates a new node.
    - `insert_at_beginning`: Inserts a node at the beginning of the list.
    - `insert_at_end`: Inserts a node at the end of the list.
    - `delete_at_position`: Deletes a node at a specified position.
    - `search_element`: Searches for an element in the list.
    - `display_list`: Displays the elements of the list.

### Stack

- **Description:** Implementation of a stack data structure.
- **Files:** `stack.c`, `stack.h`
- **Functions:**
  - `initialize_stack`: Initializes an empty stack.
  - `push`: Pushes an element onto the stack.
  - `pop`: Pops an element from the stack.
  - `is_empty`: Checks if the stack is empty.
  - `display_stack`: Displays the elements of the stack.

### Queue

- **Linear Queue:**

  - **Description:** Implementation of linear queue operations.
  - **Files:** `linear_queue.c`, `linear_queue.h`
  - **Functions:**
    - `initialize_queue`: Initializes an empty queue.
    - `enqueue`: Adds an element to the rear of the queue.
    - `dequeue`: Removes an element from the front of the queue.
    - `is_empty`: Checks if the queue is empty.
    - `display_queue`: Displays the elements of the queue.

- **Priority Queue:**
  - **Description:** Implementation of a priority queue.
  - **Files:** `priority_queue.c`, `priority_queue.h`
  - **Functions:**
    - `initialize_priority_queue`: Initializes an empty priority queue.
    - `enqueue`: Adds an element to the priority queue based on priority.
    - `dequeue`: Removes the highest-priority element from the queue.
    - `is_empty`: Checks if the priority queue is empty.
    - `display_priority_queue`: Displays the elements of the priority queue.

## Sorting Techniques

- **Bubble Sort:**

  - **Description:** Implementation of the bubble sort algorithm.
  - **Files:** `bubble_sort.c`, `bubble_sort.h`
  - **Functions:**
    - `bubble_sort`: Sorts an array using the bubble sort algorithm.

- **Selection Sort:**
  - **Description:** Implementation of the selection sort algorithm.
  - **Files:** `selection_sort.c`, `selection_sort.h`
  - **Functions:**
    - `selection_sort`: Sorts an array using the selection sort algorithm.

## Searching Techniques

- **Linear Search:**

  - **Description:** Implementation of linear search on arrays.
  - **Files:** `linear_search.c`, `linear_search.h`
  - **Functions:**
    - `linear_search`: Searches for an element in an array using linear search.

- **Binary Search:**
  - **Description:** Implementation of binary search on sorted arrays.
  - **Files:** `binary_search.c`, `binary_search.h`
  - **Functions:**
    - `binary_search`: Searches for an element in a sorted array using binary search.

## Hierarchical Data Structures

- **General Trees:**

  - **Description:** Implementation and manipulation of general tree structures.
  - **Files:** `general_tree.c`, `general_tree.h`
  - **Functions:**
    - `create_node`: Creates a new node.
    - `insert_child`: Inserts a child node to a parent node.
    - `delete_node`: Deletes a node from the tree.
    - `traverse_tree`: Traverses the tree in various orders (pre-order, in-order, post-order).

- **Binary Trees:**

  - **Description:** Implementation and manipulation of binary tree structures.
  - **Files:** `binary_tree.c`, `binary_tree.h`
  - **Functions:**
    - `create_node`: Creates a new node.
    - `insert_left`: Inserts a left child node.
    - `insert_right`: Inserts a right child node.
    - `delete_node`: Deletes a node from the tree.
    - `traverse_tree`: Traverses the binary tree in various orders.

- **Binary Search Trees:**
  - **Description:** Implementation and manipulation of binary search trees.
  - **Files:** `binary_search_tree.c`, `binary_search_tree.h`
  - **Functions:**
    - `insert_node`: Inserts a node into the binary search tree.
    - `delete_node`: Deletes a node from the binary search tree.
    - `search_element`: Searches for an element in the binary search tree.
    - `traverse_tree`: Traverses the binary search tree in various orders.

## Graph as a Data Structure

- **Description:** Implementation of basic graph operations.
- **Files:** `graph.c`, `graph.h`
- **Functions:**
  - `add_vertex`: Adds a vertex to the graph.
  - `add_edge`: Adds an edge between two vertices.
  - `remove_vertex`: Removes a vertex from the graph.
  - `remove_edge`: Removes an edge between two vertices.
  - `display_graph`: Displays the adjacency matrix or adjacency list representation of the graph.

## Problem Solving

- **Description:** After every session, problem-solving exercises are provided to reinforce the concepts covered in the respective session. Solutions to these problems can be found in the corresponding directories.

Feel free to explore the code files and use them as a reference for your studies. If you have any questions or suggestions, please don't hesitate to reach out.

Happy coding!
