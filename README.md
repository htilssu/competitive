# Competitive Programming Solutions

This repository contains solutions for competitive programming problems, primarily from LeetCode.

## Completed Problems

| Problem Number | Problem Title | Difficulty | Directory Path |
|----------------|---------------|------------|----------------|
| 176 | Second Highest Salary | Medium | [leetcodes/176_second-highest-salary_medium](./leetcodes/176_second-highest-salary_medium) |
| 1123 | Lowest Common Ancestor of Deepest Leaves | Medium | [leetcodes/1123_lowest-common-ancestor-of-deepest-leaves_medium](./leetcodes/1123_lowest-common-ancestor-of-deepest-leaves_medium) |
| 1936 | Add Minimum Number of Rungs | Medium | [leetcodes/1936_add-minimum-number-of-rungs_medium](./leetcodes/1936_add-minimum-number-of-rungs_medium) |
| 1977 | Number of Ways to Separate Numbers | Hard | [leetcodes/1977_number-of-ways-to-separate-numbers](./leetcodes/1977_number-of-ways-to-separate-numbers) |
| 2195 | Append K Integers With Minimal Sum | Medium | [leetcodes/2195_append-k-integers-with-minimal-sum_medium](./leetcodes/2195_append-k-integers-with-minimal-sum_medium) |
| 3070 | Count Submatrices With Top Left Element And Sum Less Than K | Medium | [leetcodes/3070-Count-Submatrices-With-Top-Left-Element-And-Sum-Less-Than-K_medium](./leetcodes/3070-Count-Submatrices-With-Top-Left-Element-And-Sum-Less-Than-K_medium) |

## Repository Structure

- `leetcodes/` - Contains LeetCode problem solutions
  - Each subdirectory is named with the format `{problem_number}_{problem_title}_{difficulty}`
  - Each problem directory contains:
    - `main.cpp` - The solution implementation (or `main.sql` for database problems)
    - `CMakeLists.txt` - Build configuration (for C++ problems)

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