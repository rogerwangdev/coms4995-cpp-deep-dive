# COMS 4995 — C++ Deep Dive

Course work and experiments for COMS 4995 (C++ Deep Dive).

## Goals

- Practice modern C++ (C++17/20) with an emphasis on correctness, performance, and readability
- Build intuition for language fundamentals (value categories, RAII, move semantics, templates)
- Get comfortable with tooling (compiler warnings, sanitizers, debugging, formatting)

## Repository structure

This repo will grow over the semester. Typical folders you may see:

- `notes/` — lecture notes and references
- `labs/` — small guided exercises
- `hw/` — homework assignments
- `projects/` — larger projects / final project

## Tooling

Recommended:

- Compiler: `clang++` or `g++`
- Build system: `cmake` (when projects start using it)
- Formatter: `clang-format`
- Static analysis (optional): `clang-tidy`

Useful flags:

- Warnings: `-Wall -Wextra -Wpedantic -Werror`
- Debugging: `-g`
- Sanitizers (Clang/GCC): `-fsanitize=address,undefined`

## Build & run (example)

When a CMake project exists under a subfolder (e.g. `labs/lab01/`):

```bash
cmake -S . -B build
cmake --build build
./build/<executable-name>
```

For single-file experiments:

```bash
clang++ -std=c++20 -O2 -Wall -Wextra -Wpedantic main.cpp -o main
./main
```

## Conventions

- Keep code warning-clean at high warning levels
- Prefer small, focused commits with clear messages
- Add a short `README.md` in each lab/homework folder with build/run instructions

## Notes

If you’re a classmate/instructor looking at this repo: some folders may be empty or private until their release dates.
