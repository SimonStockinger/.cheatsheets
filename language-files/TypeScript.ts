/*
 * =========================
 * TypeScript Tutorial File
 * =========================
 * 
 * Key Notes:
 * - TypeScript is a strongly typed superset of JavaScript.
 * - Supports static typing, interfaces, classes, and generics.
 * - Type inference can automatically assign types if not explicitly declared.
 * - Common primitive types: number, string, boolean, null, undefined.
 * - Arrays, tuples, enums, and objects are supported.
 * - Functions can have typed parameters, return types, and optional/default parameters.
 * - Classes support inheritance, access modifiers (public, private, protected), and static members.
 * - Interfaces define contracts for objects or classes.
 * - TypeScript code needs to be compiled to JavaScript before running in Node.js or browsers.
 *
 * Compiling and Running (Console):
 * 1. Compile: tsc typescript_tutorial.ts
 * 2. Run: node typescript_tutorial.js
 */


///////////////////////////
// DATATYPES
///////////////////////////

// PRIMITIVE TYPES
let num: number = 42;
let str: string = "Hello, TypeScript!";
let bool: boolean = true;

console.log("Number:", num);
console.log("String:", str);
console.log("Boolean:", bool);

// ARRAYS & TUPLES
let numbers: number[] = [1, 2, 3, 4, 5];
let tuple: [string, number] = ["Alice", 25];

console.log("Array:", numbers);
console.log("Tuple:", tuple);

// ENUM
enum Level {
    Low,
    Medium,
    High
}
let level: Level = Level.High;
console.log("Enum Level:", Level[level]);

///////////////////////////
// FUNCTIONS
///////////////////////////
function add(a: number, b: number): number {
    return a + b;
}
console.log("Sum:", add(5, 7));

// Optional & Default Parameters
function greet(name: string, greeting: string = "Hello"): void {
    console.log(`${greeting}, ${name}!`);
}
greet("Alice");
greet("Bob", "Hi");

///////////////////////////
// INTERFACES
///////////////////////////
interface Person {
    name: string;
    age: number;
    greet(): void;
}

let alice: Person = {
    name: "Alice",
    age: 25,
    greet() {
        console.log(`Hello, my name is ${this.name}`);
    }
};

alice.greet();

///////////////////////////
// CLASSES & INHERITANCE
///////////////////////////
class Animal {
    constructor(public name: string) {}
    move(distance: number = 0) {
        console.log(`${this.name} moved ${distance} meters`);
    }
}

class Dog extends Animal {
    bark() {
        console.log("Woof!");
    }
}

let dog = new Dog("Buddy");
dog.bark();
dog.move(10);

///////////////////////////
// GENERICS
///////////////////////////
function identity<T>(arg: T): T {
    return arg;
}
console.log("Generic identity:", identity<string>("Test"));

///////////////////////////
// ARRAY METHODS
///////////////////////////
numbers.forEach(n => console.log("forEach:", n));
let squares = numbers.map(n => n * n);
console.log("Squares:", squares);
let evens = numbers.filter(n => n % 2 === 0);
console.log("Even numbers:", evens);

///////////////////////////
// TYPE ASSERTION
///////////////////////////
let someValue: any = "This is a string";
let strLength: number = (someValue as string).length;
console.log("String length via assertion:", strLength);

///////////////////////////
// ASYNC/AWAIT & PROMISE
///////////////////////////
function delay(ms: number): Promise<string> {
    return new Promise(resolve => setTimeout(() => resolve("Done!"), ms));
}

async function asyncExample() {
    console.log("Waiting...");
    let result = await delay(1000);
    console.log(result);
}

asyncExample();
