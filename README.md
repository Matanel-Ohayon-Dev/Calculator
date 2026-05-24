# 🧮 C++ Expression Calculator

A recursive descent expression parser and calculator built in C++. Parses and evaluates arithmetic expressions with correct operator precedence and support for nested parentheses.

---

## Features

- Supports `+`, `-`, `*`, `/` operators
- Correct operator precedence (`*` and `/` before `+` and `-`)
- Arbitrarily nested parentheses
- Input validation with descriptive error messages
- Division by zero protection
- Clean memory management

---

## How It Works

The calculator works in two phases:

**1. Tokenization (`read_input`)**  
The raw input string is scanned character by character and converted into a flat list of `numop` tokens — each representing either a number or an operator. Parenthesis balance is validated at this stage.

**2. Parsing & Evaluation**  
Tokens are evaluated using a classic recursive descent grammar:

```
expression → term (('+' | '-') term)*
term       → factor (('*' | '/') factor)*
factor     → number | '(' expression ')'
```

This naturally enforces operator precedence without any explicit priority table.

---

## Project Structure

```
.
├── calculator.hpp   # Class declarations (Calculator, numop)
└── calculator.cpp   # Full implementation
```

### Key Classes

**`numop`** — Represents a single token: either a number (`double`) or an operator (`char`).

**`Calculator`** — Main class responsible for input reading, tokenization, parsing, and evaluation.

| Method | Description |
|---|---|
| `read_input()` | Reads and tokenizes the expression from stdin |
| `parser()` | Entry point for recursive descent evaluation |
| `expression()` | Handles `+` and `-` |
| `term()` | Handles `*` and `/` |
| `factor()` | Handles numbers and parenthesized sub-expressions |
| `calculate()` | Dispatches to `add`, `subtract`, `multiply`, `divide` |
| `print_result()` | Prints the formatted result |
| `reset()` | Frees token memory and clears state |

---

## Getting Started

### Prerequisites

- A C++11 (or later) compatible compiler (e.g., `g++`, `clang++`)

### Build

```bash
g++ -std=c++11 -o calculator calculator.cpp
```

### Run

```bash
./calculator
```

You will be prompted to enter an arithmetic expression:

```
Enter equation:
3 + 5 * (2 - 8)
3 + 5 * (2 - 8) = -27.000000
the result is: -27.000000
```

---

## Error Handling

The calculator throws a `std::runtime_error` for the following cases:

| Error | Trigger |
|---|---|
| `Division by zero!` | Denominator evaluates to `0` |
| `Unmatched Parentheses!` | Mismatched `(` / `)` |
| `Invalid input!` | Unknown character or misplaced operator |

---

## Example Expressions

```
2 + 3              → 5
10 / 2 * 3         → 15
(1 + 2) * (3 + 4)  → 21
100 / (5 * 4)      → 5
```

---

## Limitations

- Supports **integer input only** (no decimal point in input)
- No support for unary minus (e.g., `-5` as a standalone term)
- No exponentiation or modulo operators

---

## License

This project is for educational purposes. Feel free to use and modify it.
