/*
 * =========================
 * Rust Tutorial File
 * =========================
 
 * Key Notes:
 * - Rust is a compiled, strongly typed systems programming language.
 * - Ownership, borrowing, and lifetimes prevent data races and memory leaks.
 * - Primitive types: i32, u32, i64, f32, f64, bool, char.
 * - Strings: String (heap-allocated, mutable) and &str (string slice, borrowed).
 * - Variables are immutable by default; use `mut` to make mutable.
 * - Shadowing allows reusing variable names.
 * - Functions use fn keyword; expressions return values.
 * - Structs and enums are primary ways to define custom data types.
 * - Traits define shared behavior; implement traits with `impl`.
 * - Collections: Vec, HashMap, HashSet, etc.
 * - Error handling: panic!, Result<T, E>, Option<T>.
 * - Threads and concurrency are safe and supported in the standard library.
 * - Pattern matching: match expressions are exhaustive and powerful.
 * 
 * Compiling and Running (Console):
 * 1. Compile: rustc rust_tutorial.rs
 * 2. Run: ./rust_tutorial
 * OR using Cargo (recommended):
 * 1. cargo new project_name
 * 2. cargo run
 */


// =========================
// IMPORTS / USE STATEMENTS
// =========================
use std::collections::{HashMap, HashSet};
use std::time::{SystemTime, UNIX_EPOCH};

// =========================
// CONSTANTS
// =========================
const PI: f64 = 3.14159;
const MAX_SIZE: usize = 100;

// =========================
// STRUCTS
// =========================
struct Person {
    name: String,
    age: u32,
}

// =========================
// ENUMS
// =========================
enum Level {
    Low,
    Medium,
    High,
}

// =========================
// TRAITS
// =========================
trait Animal {
    fn make_sound(&self);
}

// =========================
// IMPLEMENTATIONS
// =========================
impl Animal for Dog {
    fn make_sound(&self) {
        println!("Woof!");
    }
}

struct Dog;

// =========================
// MAIN FUNCTION
// =========================
fn main() {
    // =========================
    // PRIMITIVE DATA TYPES
    // =========================
    let i: i32 = 42;
    let f: f32 = 3.14;
    let d: f64 = 3.1415926535;
    let c: char = 'A';
    let b: bool = true;

    println!("Integer: {}", i);
    println!("Float: {}", f);
    println!("Double: {}", d);
    println!("Char: {}", c);
    println!("Boolean: {}", b);

    // =========================
    // STRINGS
    // =========================
    let s1 = String::from("Hello, World!");
    let s2 = &s1; // String slice
    println!("String: {}", s2);

    // =========================
    // ARRAYS & VECTORS
    // =========================
    let arr = [1, 2, 3, 4, 5];
    println!("Array: {:?}", arr);

    let mut vec = vec![10, 20, 30];
    vec.push(40);
    println!("Vector: {:?}", vec);

    // =========================
    // LOOPS
    // =========================
    println!("For loop:");
    for x in 0..5 {
        println!("{}", x);
    }

    println!("While loop:");
    let mut y = 0;
    while y < 3 {
        println!("{}", y);
        y += 1;
    }

    println!("Loop (do-while equivalent using loop + break):");
    let mut z = 0;
    loop {
        println!("{}", z);
        z += 1;
        if z >= 2 {
            break;
        }
    }

    // =========================
    // CONDITIONALS
    // =========================
    if i > 50 {
        println!("i is greater than 50");
    } else {
        println!("i is 50 or less");
    }

    let day = 2;
    match day {
        1 => println!("Monday"),
        2 => println!("Tuesday"),
        _ => println!("Other day"),
    }

    // =========================
    // FUNCTIONS
    // =========================
    let sum = add(5, 7);
    println!("Sum: {}", sum);

    // =========================
    // MUTABILITY & SHADOWING
    // =========================
    let mut x = 10;
    println!("Mutable x before: {}", x);
    x += 5;
    println!("Mutable x after: {}", x);

    let x = x * 2; // shadowing
    println!("Shadowed x: {}", x);

    // =========================
    // OWNERSHIP & BORROWING
    // =========================
    let s = String::from("Ownership");
    print_string(&s); // borrowing
    println!("Original string after borrow: {}", s);

    // =========================
    // STRUCTS
    // =========================
    let person = Person {
        name: String::from("Alice"),
        age: 25,
    };
    println!("Person: {} ({})", person.name, person.age);

    // =========================
    // ENUMS
    // =========================
    let level = Level::High;
    match level {
        Level::Low => println!("Level: Low"),
        Level::Medium => println!("Level: Medium"),
        Level::High => println!("Level: High"),
    }

    // =========================
    // COLLECTIONS
    // =========================
    let mut set = HashSet::new();
    set.insert(1);
    set.insert(2);
    println!("HashSet: {:?}", set);

    let mut map = HashMap::new();
    map.insert("Alice", 25);
    println!("HashMap: {:?}", map);

    // =========================
    // CLOSURES
    // =========================
    let square = |x: i32| x * x;
    println!("Square of 5: {}", square(5));

    // =========================
    // TIME
    // =========================
    let start = SystemTime::now();
    match start.duration_since(UNIX_EPOCH) {
        Ok(n) => println!("Current timestamp: {:?}", n.as_secs()),
        Err(_) => println!("SystemTime before UNIX EPOCH!"),
    }

    // =========================
    // THREADS (BASIC)
    // =========================
    use std::thread;

    let handle = thread::spawn(|| {
        println!("Thread running");
    });
    handle.join().unwrap();
}

// =========================
// FUNCTIONS
// =========================
fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn print_string(s: &String) {
    println!("Borrowed string: {}", s);
}
