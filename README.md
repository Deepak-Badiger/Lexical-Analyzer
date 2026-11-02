# Lexical Analyzer 

## Project Description

Developed a Lexical Analyzer using C programming to analyze source code, identify different lexical tokens, and detect basic lexical errors. The project implements the fundamental phase of compiler design, where source code is scanned character by character and converted into meaningful tokens.

Implemented token recognition and classification to identify keywords, identifiers, numeric constants, floating-point constants, character constants, string literals, operators, symbols, and comments. Used predefined keyword tables and operator lists to distinguish reserved words from user-defined identifiers.

Designed separate functions for scanning and validating different token types, including keyword recognition, numeric validation, string and character constant processing, comment identification, and operator recognition.

Implemented basic lexical error detection to identify invalid numeric constants, unterminated comments, invalid character constants, and unmatched brackets. Used line tracking to report errors with their corresponding line numbers.

The project follows a modular programming approach using structures, enumerations, pointers, arrays, and file handling techniques to make the lexical analysis process organized and efficient.

## Key Features

- Reads source code from an input file.
- Scans source code character by character.
- Identifies and classifies different token types.
- Recognizes C language reserved keywords.
- Differentiates keywords and identifiers.
- Identifies integer, octal, hexadecimal, and floating-point constants within supported formats.
- Recognizes string literals and character constants.
- Identifies single-line and multi-line comments.
- Recognizes single-character and multi-character operators.
- Identifies special symbols and delimiters.
- Tracks opening and closing brackets.
- Detects basic lexical errors and reports line numbers.
- Uses modular functions for token recognition and validation.

## Technologies Used

- Programming Language: C
- Concepts: Compiler Design, Lexical Analysis, File Handling, Structures, Pointers, Enumerations, Arrays, String Handling, Character Classification, Error Handling.

## C Programming Concepts Implemented

- File operations using `fopen()`, `fclose()`, and `fgetc()`.
- Character classification using `isalpha()`, `isdigit()`, and `isalnum()`.
- String handling and comparison functions.
- Structures and enumerations for token management.
- Pointers and modular function implementation.
- Command-line argument handling using `argc` and `argv`.
- Buffer management and input stream handling using `ungetc()`.

## Learning Outcomes

Gained practical understanding of compiler design fundamentals and the lexical analysis phase. Improved knowledge of C programming, file handling, pointers, structures, string manipulation, character classification, tokenization, and lexical error detection. Developed problem-solving skills through implementing a modular token recognition system.
