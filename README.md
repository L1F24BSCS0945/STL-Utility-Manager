# STL Utility Manager

A simple menu-driven C++ console application that demonstrates different STL concepts, data structures, sorting, searching, and iterators.

The project implements common STL-style containers from scratch instead of directly using the standard STL containers.

## Features

* Vector Operations
* List Operations
* Stack Operations
* Queue Operations
* Map Operations
* Set Operations
* Sort Vector
* Search Vector
* Frequency Counter

## Data Structures

### MyVector

Custom dynamic array with:

* Insert at end
* Insert at position
* Delete by value
* Delete by position
* Access element by index
* Display elements

### MyList

Custom doubly linked list with:

* Insert at front
* Insert at back
* Delete from front
* Delete from back
* Delete by value
* Display elements

### MyStack

Linked-list based stack using **LIFO** (Last In, First Out).

* Push
* Pop
* Peek
* Display

### MyQueue

Linked-list based queue using **FIFO** (First In, First Out).

* Enqueue
* Dequeue
* Front
* Display

### MyMap

Custom key-value pair storage.

* Insert key-value pair
* Update existing key
* Delete by key
* Search by key
* Display sorted by key

### MySet

Custom set that does not allow duplicate values.

* Insert
* Delete
* Search
* Display sorted values

## Algorithms

The project also contains manually written algorithms:

* **Bubble Sort** – Sorts values in ascending or descending order
* **Linear Search** – Searches for a value in the vector
* **Binary Search** – Searches a sorted copy of the vector

## Frequency Counter

The Frequency Counter counts how many times each value appears in the vector and displays the results in sorted order.

Example:

```text
Value      Frequency
---------------------
10         2
20         3
30         1
```

## Iterators

The project uses pointer-based iterators with:

```cpp
begin()
end()
```

These are used with the custom sorting and searching functions.

## Input Validation

The program also includes input validation to handle:

* Invalid integer input
* Values outside the allowed range
* Empty text input

## Technologies Used

* C++
* Object-Oriented Programming
* Pointers
* Dynamic Memory
* Arrays
* Linked Lists
* Stack
* Queue
* Searching
* Sorting

## Project Files

```text
STL-Utility-Manager/
│
├── main.cpp
├── stlmanager.h
├── stlmanager.cpp
└── README.md
```

## How to Run

Compile the project using:

```bash
g++ -std=c++17 -Wall -Wextra -o stlapp main.cpp stlmanager.cpp
```

Run:

```bash
./stlapp
```

On Windows:

```bash
stlapp.exe
```

## Purpose

The purpose of this project is to understand how common STL-style data structures and algorithms work by implementing them manually using C++.
