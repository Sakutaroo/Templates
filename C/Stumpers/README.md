# Stumper-Template

## Description

This is a template for the Epitech's C project called `Stumper`.

## Installation

- Clone
```
git clone git@github.com:Sakutaroo/Templates.git
```

Choose one of the two following options:
1. If you want to use only this template:
```
cd Templates && git sparse-checkout set C/Stumpers/
```

- Launch installation
```
cd C/Stumpers && ./install.sh
```

2. If you probably want to use other templates:
- Launch installation
```
cd Templates/C/Stumpers && ./install.sh
```

- Restart your shell

## Default configuration

The default configuration is in the `Configuration` file.</br>
It is in the following format:

### Makefile

| Command          | Result                                         |
|------------------|------------------------------------------------|
| `make`           | Builds the executable.                         |
| `make debug`     | Builds the executable with debug symbols.      |
| `make clean`     | Removes all of the files created by the build. |
| `make fclean`    | Calls `make clean` and removes executables     |
| `make re`        | Calls `make fclean` and then `make`.           |
| `make tests_run` | Runs the unit tests.                           |
| `make gcovr`     | Shows the coverage for your tests.             |

##### Available variables:</br>
`%YEAR`: The current year.</br>
`%BINARY_NAME`: The name of the binary.</br>

##### Available options:</br>

`CFLAGS`: Flags to pass to the compiler. (default: `-Wall -Wextra`)</br>
`CPPFLAGS`: Flags to pass to the preprocessor. (default: `-I./include`)</br>
`LDFLAGS`: Flags to pass to the linker. (default: `-lcriterion -lgcov --coverage`)</br>
Available variables: `%YEAR` and `%BINARY_NAME`</br>

### Gitignore

The `.gitignore` file is configured to ignore all the files created by the build.</br>
Default: [Gitignore C](https://github.com/github/gitignore/blob/main/C.gitignore) and `*.gc*`, `.vscode/`, `.idea/`, `*vgcore*`, `%BINARY_NAME` files.

### Include

The `include` folder contains the header files of the project.</br>

#### Available files:</br>
`%BINARY_NAME.h`: The header file of the binary.</br>
`macros.h`: The header file containing the macros of the project.</br>

#### Available variables:</br>
`%YEAR`: The current year.</br>
`%BINARY_NAME`: The name of the binary.</br>
`%PROJECT_NAME`: The name of the project.</br>

### Source

The `src` folder contains the source files of the project.</br>

#### Available files:</br>
`main.c`: The source file of the main function.</br>
`%BINARY_NAME.c`: The source file of the binary.</br>

#### Available variables:</br>
`%YEAR`: The current year.</br>
`%BINARY_NAME`: The name of the binary.</br>

### Tests

The `tests` folder contains the unit tests of the project.</br>

#### Available files:</br>
`tests_%BINARY_NAME.c`: The source file of the unit tests of the binary.</br>

#### Available variables:</br>
`%YEAR`: The current year.</br>
`%BINARY_NAME`: The name of the binary.</br>

## Usage
```
stumper BINARY_NAME
```

## Author
- [Kévin Demy](https://github.com/Sakutaroo)
