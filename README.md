Longest Common Substring (LCS) - C++ Implementation
Project Overview

This project implements the Longest Common Substring (LCS) algorithm using Dynamic Programming in C++.
The program takes in two strings of equal length, builds a dynamic programming (DP) lookup table, and outputs:

The DP table.

The length of the longest common substring.

All possible longest common substrings (in case of ties).

Example:

Input:
String 1: ABAB
String 2: BABA

Output:
Longest Common Substring length: 3
Substring(s): ABA BAB

Features

Accepts two user-input strings (must be of equal length).

Builds a 2D DP table to calculate substring matches.

Prints the lookup table for transparency.

Supports ties by returning all longest common substrings.

Example Execution
Enter first string: ABAB
Enter second string: BABA

DP Lookup Table:
0 0 0 0 0
0 0 1 0 1
0 1 0 2 0
0 0 2 0 3
0 1 0 3 0

Longest Common Substring length: 3
Substring(s): ABA BAB

Algorithm Explanation

Initialize a DP table of size (m+1) x (n+1) with zeros, where m and n are the lengths of the input strings.

Traverse both strings:

If characters match, set dp[i][j] = dp[i-1][j-1] + 1.

Track the maximum length found.

Store substring(s) corresponding to the maximum length.

If multiple substrings have the same maximum length, output all of them.

 Complexity

Time Complexity: O(m × n)

Space Complexity: O(m × n)
