# 💳 Credit Card Authentication Tool

A simple C++ console application designed to authenticate credit card numbers using the Luhn algorithm. This tool reads card numbers from a file and verifies their validity, providing a straightforward demonstration of basic file handling and algorithm implementation in C++.

## 📋 Features

- **Luhn Algorithm Implementation**: Validates credit card numbers using the standard Luhn check.
- **File Input**: Reads a list of credit card numbers from a text file (`cards.txt`).
- **Console Output**: Displays the validity of each card number in the console.

## 🛠️ Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, `clang++`, or MSVC).
- A terminal or command prompt to compile and run the application.

### Compilation

To compile the application, use the following command:

```bash
g++ -std=c++11 -o CreditCardValidator Main.cpp Credit.cpp
