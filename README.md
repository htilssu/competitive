# Competitive Programming Solutions

This repository contains solutions for competitive programming problems, primarily from LeetCode.

## Completed Problems

| Problem Number | Problem Title | Directory Path |
|----------------|---------------|----------------|
| 1123 | Lowest Common Ancestor of Deepest Leaves | [leetcodes/1123_lowest-common-ancestor-of-deepest-leaves](./leetcodes/1123_lowest-common-ancestor-of-deepest-leaves) |
| 1936 | Add Minimum Number of Rungs | [leetcodes/1936_add-minimum-number-of-rungs](./leetcodes/1936_add-minimum-number-of-rungs) |
| 3070 | Count Submatrices With Top Left Element And Sum Less Than K | [leetcodes/3070-Count-Submatrices-With-Top-Left-Element-And-Sum-Less-Than-K](./leetcodes/3070-Count-Submatrices-With-Top-Left-Element-And-Sum-Less-Than-K) |

## Repository Structure

- `leetcodes/` - Contains LeetCode problem solutions
  - Each subdirectory is named with the format `{problem_number}_{problem_title}`
  - Each problem directory contains:
    - `main.cpp` - The solution implementation
    - `CMakeLists.txt` - Build configuration

## How to Build and Run

Each problem can be built and run independently using CMake:

```bash
cd leetcodes/{problem_directory}
mkdir build
cd build
cmake ..
make
./main
```