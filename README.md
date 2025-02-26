
```markdow
# get_next_line 📖

A function that reads a line from a file descriptor, implemented in C. Part of the 42 School curriculum.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Norminette](https://github.com/your-username/get_next_line/actions/workflows/norminette.yml/badge.svg)](https://github.com/your-username/get_next_line/actions)

---

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Bonus](#bonus)
- [Testing](#testing)


---

## Introduction

The `get_next_line` function reads one line at a time from a file descriptor or standard input. It maintains state between calls using static variables, making it efficient for reading large files line by line without loading the entire file into memory.

**Key Concepts:**
- Static variables for buffer management
- File descriptor management
- Memory allocation optimization
- Error handling

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/get_next_line.git
   cd get_next_line
   ```

2. Compile the library:
   ```bash
   make
   ```

3. Compile with bonus (multiple file descriptors support):
   ```bash
   make bonus
   ```

4. Clean object files:
   ```bash
   make clean
   ```

5. Clean everything:
   ```bash
   make fclean
   ```

---

## Usage

Basic implementation in your code:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) 
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile with:
```bash
gcc -Wall -Wextra -Werror your_program.c get_next_line.c get_next_line_utils.c
```

---

## Features

- Reads from standard input and file descriptors
- Handles multiple file descriptors simultaneously (bonus)
- Configurable BUFFER_SIZE (1 to 1,000,000+)
- Memory leak protection
- Full error handling
- Efficient memory management
- Supports very long lines (up to INT_MAX characters)

---

## Bonus

The bonus version adds support for:
- Managing multiple file descriptors simultaneously
- No data mixing between different file descriptors
- Static variable management without leaks
- All features from mandatory part

Test with:
```bash
./test_multiple_fds file1.txt file2.txt file3.txt
```

---

## Testing

1. Basic tests:
```bash
echo "Hello\nWorld" > test.txt
gcc main.c get_next_line.c get_next_line_utils.c && ./a.out
```

2. Memory check:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

3. Buffer size tests:
```bash
for BUFSIZE in 1 10 32 1024 4096 9999
do
    gcc -D BUFFER_SIZE=$BUFSIZE main.c get_next_line.c get_next_line_utils.c
    ./a.out
done
```

Recommended testers:
- [gnl-war-machine]([https://github.com/some-tester/gnl-war-machine](https://github.com/Tripouille/gnlTester))
- [42TESTERS-GNL]([https://github.com/Mazoise/42TESTERS-GNL](https://github.com/kodpe/gnl-station-tester))



---

Created by [Your Name] • 42 School Project • [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mohamed-el-ayyady/)
