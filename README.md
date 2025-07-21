# 🛠️ sys-tools-suite

**Author:** Mateo Day  
**Course:** COMP 206 – Introduction to Software Systems  
**Institution:** McGill University  
**Project:** Final Assignment Submission

---

## 📘 Overview

`sys-tools-suite` is a compact, functional set of command-line utilities written in **C** and **Bash**. The project was created as the final assignment for COMP 206 at McGill University, showcasing the practical application of systems programming concepts including string manipulation, file I/O, shell scripting, Makefiles, debugging with GDB, and basic Git workflows.

Each script or program in this suite was designed to solve a particular problem: cleaning up poorly formatted files, converting CSV files into HTML tables, or analyzing Zoom meeting attendance logs.

---

## 📁 Contents

| File                | Type        | Description |
|---------------------|-------------|-------------|
| `zoomrecs.c` / `zoomrecs.h` | C Source/Header | Parses Zoom attendance logs and filters entries based on criteria |
| `csv2html.sh`       | Bash Script | Converts a CSV file into a basic HTML table |
| `fixformat.sh`      | Bash Script | Cleans up text formatting issues like inconsistent spacing |
| `labapp.c`          | C Source    | Lab assignment demonstrating string processing and pointer manipulation |
| `makefile`          | Makefile    | Automates the build process for C programs |
| `gdb.txt`           | Text File   | Notes on debugging using GDB |
| `git.txt`           | Text File   | Snapshot of Git commit history (for submission tracking) |

---

## 🧠 Purpose

This suite was built to demonstrate the following core concepts of systems programming:

- Memory-safe string manipulation in C
- File parsing and standard I/O in Unix-based systems
- Automation using shell scripts and Makefiles
- Debugging with `gdb`
- Git version control workflows

---

## 🧪 Usage

### 🧰 Compile the C Programs

Use the included `makefile` to build:

```bash
make
```

Or manually:

```bash
gcc -o zoomrecs zoomrecs.c
./zoomrecs
```

> The program reads a Zoom meeting log and filters entries. You can modify the input source inside `zoomrecs.c` or extend it to read files dynamically.

---

### 📄 Run the Bash Scripts

#### 1. `csv2html.sh`
Converts a CSV file into an HTML table.

```bash
bash csv2html.sh input.csv output.html
```

Example:
```bash
bash csv2html.sh students.csv students.html
```

#### 2. `fixformat.sh`
Cleans up formatting in a text file (extra spaces, inconsistent indentation, etc.)

```bash
bash fixformat.sh messy.txt cleaned.txt
```

---

## 📌 Notes

- The scripts include input validation for argument counts.
- C programs can be extended to read from files or accept command-line arguments with minor modification.
- The Zoom parser currently expects logs in a specific format. You can adjust parsing logic in `zoomrecs.c` to fit real-world input.

---

## 🧰 Development Tools Used

- C (GCC Compiler)
- Bash (Bourne Again Shell)
- `make`
- `gdb` (GNU Debugger)
- Git
- Ubuntu (via WSL)

---

## 🏫 Educational Context

This project was developed as the final assignment for **COMP 206: Introduction to Software Systems** at **McGill University**. It reflects a culmination of learned techniques in:

- Writing shell scripts
- Building and debugging C programs
- Automating workflows with Makefiles
- Using version control effectively

---

## 🪪 License

This project is shared under the **MIT License**. Feel free to use it, fork it, or learn from it.

---

## 🙋 Contact

Feel free to reach out with any questions or collaborations.

**GitHub:** [FrizkyTrixter](https://github.com/FrizkyTrixter)
