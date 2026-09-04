# Contributing to OSvia

First off, thank you for considering contributing to OSvia! It's people like you that make OSvia such a great project.

## Code of Conduct

This project and everyone participating in it is governed by our Code of Conduct. By participating, you are expected to uphold this code.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the issue list as you might find out that you don't need to create one. When you are creating a bug report, please include as many details as possible:

* **Use a clear and descriptive title**
* **Describe the exact steps which reproduce the problem**
* **Provide specific examples to demonstrate the steps**
* **Describe the behavior you observed after following the steps**
* **Explain which behavior you expected to see instead and why**
* **Include screenshots if possible**
* **Include your system information** (OS, compiler, C++ version)

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

* **Use a clear and descriptive title**
* **Provide a step-by-step description of the suggested enhancement**
* **Provide specific examples to demonstrate the steps**
* **Describe the current behavior** and **the expected behavior**
* **Explain why this enhancement would be useful**

### Pull Requests

* Fill in the required template
* Follow the C++ styleguide
* Include appropriate test cases
* End all files with a newline
* Document new code as per the documentation styleguide
* Avoid platform-dependent code

## Styleguides

### C++ Style Guide

* Use 4 spaces for indentation
* Use camelCase for variable and function names
* Use UPPER_SNAKE_CASE for constants
* Use PascalCase for class names
* Include guard format: `#pragma once`
* Maximum line length: 100 characters (where reasonable)
* Write comments in English
* Use meaningful variable names

Example:

```cpp
#pragma once

class MyClass {
private:
    int myVariable;
    const int MAX_SIZE = 100;

public:
    MyClass();
    void myMethod();
};
```

### Commit Messages

* Use the present tense ("Add feature" not "Added feature")
* Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
* Limit the first line to 72 characters or less
* Reference issues and pull requests liberally after the first line
* Start commit message with a type followed by a scope

Example:
```
feat(calculator): Add division operation

Implement basic division functionality in the calculator
application with proper error handling for division by zero.

Fixes #123
```

Types:
- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation only changes
- `style`: Changes that don't affect code meaning
- `refactor`: Code change that neither fixes a bug nor adds a feature
- `perf`: Code change that improves performance
- `test`: Adding missing tests or correcting existing tests

### Documentation Style Guide

* Use Markdown for all documentation
* Document public APIs
* Include code examples where helpful
* Keep language simple and clear
* Use active voice

## Development Workflow

1. Fork the repository
2. Create a new branch for your feature or fix:
   ```bash
   git checkout -b feature/my-awesome-feature
   ```
3. Make your changes
4. Add or update tests (if applicable)
5. Commit your changes with proper commit messages
6. Push to your fork
7. Create a Pull Request

## Building and Testing

```bash
# Build the project
mkdir build
cd build
cmake ..
make

# Run the application
./osvia

# Test your changes
# Manual testing required for now
```

## Adding a New Application

1. Create header file: `src/apps/myapp.h`
2. Create implementation: `src/apps/myapp.cpp`
3. Update `CMakeLists.txt`
4. Add to main menu in `src/main.cpp`
5. Update `README.md` documentation
6. Submit a Pull Request

See [README.md](README.md) for the application template.

## Adding a New Game

1. Create header file: `src/games/mygame.h`
2. Create implementation: `src/games/mygame.cpp`
3. Inherit from `Application` class
4. Update `CMakeLists.txt`
5. Add to main menu in `src/main.cpp`
6. Update `README.md` documentation
7. Submit a Pull Request

## Questions?

Feel free to open an issue with your question, and we'll do our best to help.

---

Thank you for contributing to OSvia! 🎉
