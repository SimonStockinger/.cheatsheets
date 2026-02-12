
# Java Tutorial File – Overview

This document demonstrates core Java concepts using commented code examples.

---

## Imports

```java
// Package declaration (optional)
// package com.example.tutorial;

import java.util.*;          // Collections, Scanner, etc.
import java.io.*;            // Input / Output
import java.time.*;          // Date / Time API
import java.util.function.*; // Functional interfaces
```

---

## Main Class

```java
/**
 * Main tutorial class demonstrating Java concepts.
 */
public class Java {
```

---

### Constants & Static Fields

```java
public static final double PI = 3.14159;
private static int staticCounter = 0;
```

---

### Instance Fields

```java
private String name;
private int age;
```

---

### Constructors

```java
public Java() {
    this("Default", 0);
}

public Java(String name, int age) {
    this.name = name;
    this.age = age;
}
```

---

### Getter / Setter

```java
public String getName() {
    return name;
}

public void setName(String name) {
    this.name = name;
}
```

---

## Main Method – Entry Point

```java
public static void main(String[] args) {
```

---

### Primitive Data Types

```java
byte b = 127;
short s = 32000;
int i = 100000;
long l = 10000000000L;

float f = 3.14f;
double d = 3.1415926535;

char c = 'A';
boolean bool = true;
```

---

### Reference Types

```java
String text = "Hello World";
Integer boxedInt = 42; // Autoboxing
```

---

### Arrays

```java
int[] numbers = {1, 2, 3, 4, 5};
String[] words = new String[3];
```

---

## Control Structures

### If / Else

```java
if (i > 50) {
    System.out.println("i is greater than 50");
} else {
    System.out.println("i is 50 or less");
}
```

### Switch

```java
int day = 2;
switch (day) {
    case 1 -> System.out.println("Monday");
    case 2 -> System.out.println("Tuesday");
    default -> System.out.println("Other day");
}
```

### Loops

```java
for (int x = 0; x < 5; x++) {
    System.out.println("For loop: " + x);
}

int y = 0;
while (y < 3) {
    y++;
}

int z = 0;
do {
    z++;
} while (z < 2);

for (int n : numbers) {
    System.out.println(n);
}
```

---

## Methods

```java
int sum = add(3, 4);
```

---

## Object Creation

```java
Java person = new Java("Alice", 25);
```

---

## Collections

```java
List<String> list = new ArrayList<>();
list.add("A");
list.add("B");

Set<Integer> set = new HashSet<>();
set.add(1);
set.add(2);

Map<String, Integer> map = new HashMap<>();
map.put("Alice", 25);
```

---

## Lambda Expressions

```java
Runnable r = () -> System.out.println("Lambda running");
r.run();

list.forEach(element -> System.out.println(element));
```

---

## Functional Interfaces

```java
Function<Integer, Integer> square = x -> x * x;
System.out.println(square.apply(5));
```

---

## Exceptions

```java
try {
    int result = 10 / 0;
} catch (ArithmeticException e) {
    System.out.println("Division by zero!");
} finally {
    System.out.println("Finally block executed");
}
```

---

## Date / Time

```java
LocalDate today = LocalDate.now();
LocalDateTime now = LocalDateTime.now();
```

---

## Input (Scanner)

```java
// Scanner scanner = new Scanner(System.in);
// String input = scanner.nextLine();
```

---

## Enum Usage

```java
Level level = Level.HIGH;
System.out.println(level);
```

---

## Threads

```java
Thread t = new Thread(() -> {
    System.out.println("Thread running");
});
t.start();
```

---

## Static Method

```java
public static int add(int a, int b) {
    return a + b;
}
```

---

## Inner Class

```java
class InnerClass {
    void hello() {
        System.out.println("Hello from Inner Class");
    }
}
```

---

# Additional Types

## Enum

```java
enum Level {
    LOW,
    MEDIUM,
    HIGH
}
```

---

## Interface

```java
interface Animal {
    void makeSound();
}
```

---

## Abstract Class

```java
abstract class Vehicle {
    abstract void drive();
}
```

---

## Inheritance & Implementation

```java
class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof");
    }
}

class Car extends Vehicle {
    @Override
    void drive() {
        System.out.println("Car driving");
    }
}
```

---

## Generics

```java
class Box<T> {
    private T value;

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return value;
    }
}
```
