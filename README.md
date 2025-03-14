# Bothways - Linked List Integer Addition

## Overview
Bothways is a C++ program that demonstrates the implementation of a doubly-linked list data structure to represent and perform arithmetic on large integers. The program takes two positive integers as input, stores them digit by digit in linked lists, and then adds them together.

## Features
- Custom implementation of a doubly-linked list
- Representation of integers as linked lists (one node per digit)
- Support for addition of arbitrarily large integers
- Memory-safe implementation with proper resource management

## How It Works
1. The program prompts the user to input two positive integers.
2. Each integer is stored in a `LLInteger` object, with each digit stored in a separate node.
3. The digits are stored in order from most significant to least significant.
4. Addition is performed digit by digit, starting from the least significant digit (tail of the list).
5. Carries are properly handled during the addition process.
6. The result is displayed to the user.

## Technical Details
- Uses a doubly-linked list implementation for efficient traversal in both directions
- Written in C++ with object-oriented design principles
- Includes proper memory management with constructors and destructors
- Input validation to ensure only positive integers are processed

## Usage
1. Compile the program:
   ```
   g++ -o bothways Bothways.cpp
   ```
2. Run the executable:
   ```
   ./bothways
   ```
3. Follow the prompts to enter two positive integers
4. The program will display the sum of the two integers

## Example
```
Program to add two linkedlist based integers
-------------------------------------------
Enter positive integer to be added: 12345
Enter positive integer to be added: 6789
The sum is: 19134
```

## Requirements
- C++ compiler with C++11 support or higher
- Standard C++ libraries

## Future Improvements
- Implement subtraction, multiplication, and division operations
- Add support for negative integers
- Create a more robust input parsing system
- Implement a test suite for verification
- Add command-line argument support for batch processing
