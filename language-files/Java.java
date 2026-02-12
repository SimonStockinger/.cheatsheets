/*
 * =========================
 * Java Tutorial File
 * =========================
 * 
 * Key Notes:
 * - Java is an object-oriented, class-based language.
 * - File name must match class name.
 * - Only one class per file allowed.
 * - Code is organized in classes and packages.
 * - Strongly typed: variables must have a declared type.
 * - Everything (except primitives) is a reference type.
 * - Common primitive types: byte, short, int, long, float, double, char, boolean.
 * - Strings are objects (java.lang.String) and immutable.
 * - Java supports OOP features: classes, inheritance, interfaces, abstract classes, enums.
 * - Memory management is handled by the Garbage Collector.
 * - Arrays are fixed-size, use java.util.Collections for dynamic collections.
 * - Exception handling uses try-catch-finally blocks.
 * - Lambda expressions and functional interfaces are supported since Java 8.
 * - Entry point: public static void main(String[] args)
 * 
 * Compiling and Running:
 * 1. Compile: javac Java.java
 * 2. Run: java Java
 */


// Package declaration (optional)
// package com.example.tutorial;

import java.util.*;          // Collections, Scanner, etc.
import java.io.*;           // Input / Output
import java.time.*;         // Date / Time API
import java.util.function.*; // Functional interfaces

/**
 * Main tutorial class demonstrating Java concepts.
 */
public class Java {

    // =========================
    // CONSTANTS & STATIC FIELDS
    // =========================
    public static final double PI = 3.14159;
    private static int staticCounter = 0;

    // =========================
    // INSTANCE FIELDS
    // =========================
    private String name;
    private int age;

    // =========================
    // CONSTRUCTORS
    // =========================
    public Java() {
        this("Default", 0);
    }

    public Java(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // =========================
    // GETTERS / SETTERS
    // =========================
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // MAIN METHOD - Entry Point of the Programm
    public static void main(String[] args) {

        // PRIMITIVE DATA TYPES
        byte b = 127;
        short s = 32000;
        int i = 100000;
        long l = 10000000000L;

        float f = 3.14f;
        double d = 3.1415926535;

        char c = 'A';
        boolean bool = true;

        // REFERENCE TYPES
        String text = "Hello World";
        Integer boxedInt = 42; // Autoboxing

        // ARRAYS
        int[] numbers = {1, 2, 3, 4, 5};
        String[] words = new String[3];

        // =========================
        // CONTROL STRUCTURES
        // =========================

        // IF / ELSE
        if (i > 50) {
            System.out.println("i is greater than 50");
        } else {
            System.out.println("i is 50 or less");
        }

        // SWITCH
        int day = 2;
        switch (day) {
            case 1 -> System.out.println("Monday");
            case 2 -> System.out.println("Tuesday");
            default -> System.out.println("Other day");
        }

        // FOR LOOP
        for (int x = 0; x < 5; x++) {
            System.out.println("For loop: " + x);
        }

        // WHILE LOOP
        int y = 0;
        while (y < 3) {
            y++;
        }

        // DO WHILE LOOP
        int z = 0;
        do {
            z++;
        } while (z < 2);

        // FOREACH LOOP
        for (int n : numbers) {
            System.out.println(n);
        }

        // =========================
        // METHODS
        // =========================
        int sum = add(3, 4);

        // =========================
        // OBJECT CREATION
        // =========================
        Java person = new Java("Alice", 25);

        // =========================
        // COLLECTIONS
        // =========================

        // LIST
        List<String> list = new ArrayList<>();
        list.add("A");
        list.add("B");

        // SET
        Set<Integer> set = new HashSet<>();
        set.add(1);
        set.add(2);

        // MAP
        Map<String, Integer> map = new HashMap<>();
        map.put("Alice", 25);

        // =========================
        // LAMBDA EXPRESSIONS
        // =========================
        Runnable r = () -> System.out.println("Lambda running");
        r.run();
        list.forEach(element-> System.out.println(element));
        

        // FUNCTIONAL INTERFACE
        Function<Integer, Integer> square = x -> x * x;
        System.out.println(square.apply(5));

        // EXCEPTIONS
        try {
            int result = 10 / 0;
        } catch (ArithmeticException e) {
            System.out.println("Division by zero!");
        } finally {
            System.out.println("Finally block executed");
        }

        // DATE / TIME
        LocalDate today = LocalDate.now();
        LocalDateTime now = LocalDateTime.now();

        // INPUT (Scanner) C
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        // ENUM USAGE
        Level level = Level.HIGH;
        System.out.println(level);

        // THREAD (BASIC)
        Thread t = new Thread(() -> {
            System.out.println("Thread running");
        });
        t.start();
    }

    // STATIC METHOD
    // Does not access class attributes. Only works with parameters.
    public static int add(int a, int b) {
        return a + b;
    }

    // INNER CLASS
    class InnerClass {
        void hello() {
            System.out.println("Hello from Inner Class");
        }
    }
}

// ENUM
enum Level {
    LOW,
    MEDIUM,
    HIGH
}

// INTERFACE
interface Animal {
    void makeSound();
}

// ABSTRACT CLASS
abstract class Vehicle {
    abstract void drive();
}

// INHERITANCE & IMPLEMENTATION
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

// GENERICS
class Box<T> {
    private T value;

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return value;
    }
}
