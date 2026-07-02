# Datalog Parser / Scanner

## Overview
This is a C++ program that implements a **lexical analyzer (Scanner)** and a **recursive descent parser** for a simplified Datalog language. 

The program reads an input file containing Datalog statements divided into four sections:
- **Schemes**
- **Facts**
- **Rules**
- **Queries**

It tokenizes the input, parses it according to a specific context-free grammar, collects all string constants into a **Domain**, and produces a detailed output report.

This project was originally developed as a programming assignment (likely for a Compilers / Programming Languages course).

## Features
- Full lexical analysis supporting keywords, identifiers, strings, punctuation, and comments.
- Recursive descent parser with proper grammar handling for lists and nested structures.
- Automatic collection and sorting of string constants (Domain).
- Robust token representation and error reporting.
- Clean, object-oriented design with separate classes for each major component.

## Project Structure

```
.
├── main.cpp
├── Scanner.cpp / Scanner.h
├── Parser.cpp   / Parser.h
├── Token.cpp    / Token.h
├── Predicate.cpp / Predicate.h
├── Parameter.cpp / Parameter.h
├── Rule.cpp     / Rule.h
└── README.md
```

### Class Responsibilities
- **`Scanner`**: Reads characters, recognizes tokens (IDs, strings, punctuation, keywords, comments), handles line numbers.
- **`Token`**: Immutable token container with type, description, and line number.
- **`Parser`**: Recursive descent parser that builds abstract representations of Schemes, Facts, Rules, and Queries.
- **`Predicate`**: Represents `name(param1, param2, ...)`.
- **`Parameter`**: Can be either an ID (variable) or a STRING literal.
- **`Rule`**: Represents `head :- body1, body2, ... .`

## Supported Grammar

### Top-Level Structure
```
datalogProgram → SCHEMES COLON schemeList FACTS COLON factList RULES COLON ruleList QUERIES COLON queryList
```

### Detailed Elements
- **Scheme**: `ID ( ID, ID, ... )`
- **Fact**: `ID ( STRING, STRING, ... ).`
- **Rule**: `headPredicate :- predicate, predicate, ... .`
- **Query**: `predicate ?`
- **Predicate**: `ID ( Parameter, Parameter, ... )`
- **Parameter**: `ID | STRING`

**Keywords** (case-sensitive): `Schemes`, `Facts`, `Rules`, `Queries`

**Comments**: Single-line starting with `#` (ignored).

**Strings**: Enclosed in single quotes `'...'`. Cannot contain newlines.

## How to Build and Run

### Prerequisites
- C++11 compatible compiler (g++, clang++, etc.)

### Compilation
```bash
# Compile all source files
g++ -std=c++11 *.cpp -o datalog_parser

# Or with warnings
g++ -std=c++11 -Wall -Wextra *.cpp -o datalog_parser
```

### Usage
```bash
./datalog_parser <input_file> <output_file>
```

**Example:**
```bash
./datalog_parser input.txt output.txt
```

## Testing

1. Create test input files with various cases (valid, invalid, edge cases).
2. Run the program and inspect the output.
3. Compare against expected results.

### Example Input File (`input.txt`)
```datalog
Schemes:
  parent(x,y).
  grandparent(x,z).

Facts:
  parent("Bob","Alice").
  parent("Alice","Charlie").

Rules:
  ancestor(x,y) :- parent(x,y).
  ancestor(x,z) :- parent(x,y), ancestor(y,z).

Queries:
  ancestor("Bob",x)?
  grandparent("Bob",y)?
```

### Expected Output Structure
- `Success!` (or `Failure!` + token info)
- Counts for each section
- Pretty-printed representations
- Sorted Domain of all string constants

## Error Handling
- On syntax error: Outputs `Failure!` followed by the token that caused the failure.
- String errors (unterminated, newlines inside strings) are detected during scanning.
- Invalid characters produce an error.

## Known Limitations
- No semantic analysis (variable binding, rule evaluation, query answering).
- Stops at the **first** syntax error.
- Limited error recovery.
- Assumes input file exists and is readable.
- No support for complex string escaping.

## Future Improvements (Ideas)
- Implement a full Datalog interpreter (join operations, fixpoint evaluation).
- Better error messages with context.
- Support for more Datalog features (negation, built-ins).
- Unit tests for Scanner and Parser.

## Original Author
msteve22 (September 2014)

## License
This project is for educational purposes. Feel free to use and modify.

---

*Last updated: July 2026*
