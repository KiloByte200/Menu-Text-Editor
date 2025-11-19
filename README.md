# Mini Text Editor (C++)

A simple console based text editor written in C++.  
This program lets you view, append, delete, and clear lines of text stored in a dynamic buffer.

The purpose of this project is to practice core C++ concepts:
- vectors and dynamic storage
- input validation with cin, clear, and ignore
- getline for multi word input
- modular functions
- basic program structure

---

## Features

### Current
- View all lines with line numbers
- Append a new line using getline
- Delete a line by number with input validation
- Clear all text
- Menu driven interface with safe input handling

### Planned
- Open text from a file
- Save the buffer to a file
- Insert a line at a specific position
- Replace an existing line
- Search for a substring
- Track file name and unsaved changes

---

## How to Compile

### Windows (MinGW)
```bash
g++ -std=c++17 main.cpp -o text_editor.exe
text_editor.exe