Certainly! Here's a quick README.md based on the provided information:

---

# DNA Sequencing Project

This project, created by Marijn Grashoff on 5-1-2024, is a DNA sequencing algorithm implemented in C++ using the Needleman-Wunsch algorithm. The purpose of this project is to align two DNA sequences and calculate their similarity, utilizing a substitution matrix for biological significance.

## Project Overview

The project is organized into several components:

- **NWAlgo.h:** Header file containing the class declaration for NWAlgo.
- **NWAlgo.cpp:** Implementation file for the NWAlgo class.
- **SubstitutionMatrix.h:** Header file for the SubstitutionMatrix ENUM.

## Project Structure

- **main.cpp:** Main file to instantiate and utilize the NWAlgo class for testing.

## How It Works

The Needleman-Wunsch algorithm is employed to align two DNA sequences. The key components include:

- **Initialization (init()):** The algorithm initializes a matrix based on the lengths of the input DNA sequences and applies gap and mismatch penalties.

- **Substitution Scoring (FindSubstitutionScore()):** The substitution matrix is used to determine the score for substituting one element with another in the DNA sequences.

- **Algorithm Execution (run()):** The Needleman-Wunsch algorithm is executed, considering gap penalties, mismatch penalties, and substitution scores.

- **Printing the Matrix (printMatrix()):** A function is provided to print the alignment matrix in a readable format for debugging purposes.

- **information on how to use the program (Help()):** 


## Usage

To use the algorithm, instantiate the NWAlgo class with the desired DNA sequences, gap penalty, mismatch penalty, and substitution matrix (optional). Call the `run()` function to perform the alignment and traceback. The results can be visualized using the `printMatrix()` function.

## Compilation

Compile the project using a C++ compiler, ensuring all necessary header and source files are included in the compilation process.

## Note

This project is created for educational purposes as part of a school assignment. While it is not considered a finished product, it is in a decent state and serves its primary purpose of demonstrating the implementation of the Needleman-Wunsch algorithm for DNA sequencing.

For any questions or assistance, please refer to Marijn Grashoff on GitHub.