# C++ - Module 06: Type Conversion and Casting

  <img src="cpp_logo.png" alt="C++ Logo" width="100" height="100">

## Table of Contents

1. [Introduction](#introduction)
2. [Key Concepts](#key-concepts)
3. [Relevance](#relevance)
4. [Exercise 00: Conversion of Scalar Types](#exercise-00-conversion-of-scalar-types)
5. [Exercise 01: Serialization](#exercise-01-serialization)
6. [Exercise 02: Identify Real Type](#exercise-02-identify-real-type)
7. [Submission and Peer-Evaluation](#submission-and-peer-evaluation)
8. [General Rules](#general-rules)

## Introduction

Module 06 focuses on type conversion and casting in C++. This module will delve into various methods of converting data types and handling conversions between them. The exercises are designed to provide practical experience in implementing these concepts.

Please follow the provided guidelines and restrictions as they are crucial for successfully completing this module.

## Key Concepts

- **Type Conversion**: The process of converting a value from one data type to another.
- **Casting**: Explicitly changing the type of a variable. In C++, this can be done through different casting operators.
- **Scalar Types**: The basic data types in C++, including integers, floating-point numbers, and characters.

## Relevance

Understanding type conversion and casting is essential for writing efficient and error-free C++ code. These concepts are fundamental for working with different data types and ensuring data integrity in a program.

## How to run the exercises
For each exercise, follow these general steps to compile and execute the code:

1. Navigate to the exercise directory using the command line.

2. Use the provided `Makefile` to compile the code. You can do this by running the following command:

```bash
make run
```

## Exercise 00: Conversion of Scalar Types

### Introduction

This exercise focuses on implementing a static class `ScalarConverter` that contains a method `convert`. This method takes a string representation of a C++ literal and converts it to one of the following scalar types: `char`, `int`, `float`, or `double`. The exercise also handles special cases and displays appropriate messages.

### Relevance

Proficiency in handling different scalar types and conversions is crucial for writing robust C++ code. This exercise provides hands-on experience in managing type conversions.

### Key Concepts

- Type Conversion
- String Manipulation
- Special Values Handling

## Exercise 01: Serialization

### Introduction

In this exercise, you will work on serialization, which involves converting objects or data structures into a format that can be easily stored or transmitted. You'll create a class with serialization and deserialization methods.

### Relevance

Serialization is a fundamental concept in software development, especially when dealing with file operations or network communication. This exercise provides practical experience in implementing serialization techniques.

### Key Concepts

- Serialization
- Object Persistence
- File Handling

## Exercise 02: Identify Real Type

### Introduction

Building on the previous exercise, you will implement a class that can identify the real type of an object, even if it's a pointer to a base class. This exercise emphasizes polymorphism and type identification.

### Relevance

Understanding the real type of an object is crucial for effective object-oriented programming. This exercise provides practical experience in working with polymorphic objects.

### Key Concepts

- Polymorphism
- Type Identification
- Dynamic Casting

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
