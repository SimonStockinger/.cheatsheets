/*
 * =========================
 * C++ Tutorial File
 * =========================
 
 * Key Notes:
 * - C++ is a compiled, strongly typed, object-oriented language.
 * - Supports both procedural and object-oriented programming.
 * - Primitive types: int, float, double, char, bool.
 * - Strings: std::string from <string>, mutable and powerful.
 * - Pointers and references allow direct memory manipulation.
 * - Memory management: new/delete or smart pointers (unique_ptr, shared_ptr).
 * - Classes and structs support encapsulation, inheritance, and polymorphism.
 * - Templates provide generics (like Java generics).
 * - Standard Template Library (STL) provides containers (vector, list, map, set), algorithms, and iterators.
 * - Exception handling: try-catch-throw.
 * - Namespaces prevent name conflicts (e.g., std::).
 * - Entry point: int main()
 *
 * Compiling and Running:
 * 1. Compile: g++ Cpp.cpp -o CppProgram
 * 2. Run: ./CppProgram
 */


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory> // smart pointers
#include <algorithm> // STL algorithms

using namespace std;

// =========================
// CONSTANTS
// =========================
const double PI = 3.14159;
const int MAX_SIZE = 100;

// =========================
// STRUCTS
// =========================
struct Person {
    string name;
    int age;
};

// =========================
// ENUMS
// =========================
enum Level { LOW, MEDIUM, HIGH };

// =========================
// CLASS & INHERITANCE
// =========================
class Animal {
public:
    virtual void makeSound() const = 0; // pure virtual
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};

// =========================
// FUNCTION DECLARATIONS
// =========================
int add(int a, int b);
void printVector(const vector<int>& vec);
void pointerExample();
void smartPointerExample();
void structExample();
void enumExample();

// =========================
// MAIN FUNCTION
// =========================
int main() {
    // =========================
    // PRIMITIVE DATA TYPES
    // =========================
    int i = 42;
    float f = 3.14f;
    double d = 3.1415926535;
    char c = 'A';
    bool b = true;

    cout << "Integer: " << i << endl;
    cout << "Float: " << f << endl;
    cout << "Double: " << d << endl;
    cout << "Char: " << c << endl;
    cout << "Boolean: " << b << endl;

    // =========================
    // STRINGS
    // =========================
    string s = "Hello, World!";
    cout << "String: " << s << endl;

    // =========================
    // VECTORS
    // =========================
    vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);

    // =========================
    // POINTERS
    // =========================
    pointerExample();

    // =========================
    // SMART POINTERS
    // =========================
    smartPointerExample();

    // =========================
    // CONDITIONALS
    // =========================
    if(i > 50) {
        cout << "i is greater than 50" << endl;
    } else {
        cout << "i is 50 or less" << endl;
    }

    int day = 2;
    switch(day) {
        case 1: cout << "Monday" << endl; break;
        case 2: cout << "Tuesday" << endl; break;
        default: cout << "Other day" << endl; break;
    }

    // =========================
    // LOOPS
    // =========================
    cout << "For loop: ";
    for(int x = 0; x < 5; ++x) cout << x << " ";
    cout << endl;

    cout << "While loop: ";
    int w = 0;
    while(w < 3) { cout << w << " "; ++w; }
    cout << endl;

    cout << "Do-while loop: ";
    int dw = 0;
    do { cout << dw << " "; ++dw; } while(dw < 2);
    cout << endl;

    // =========================
    // FUNCTIONS
    // =========================
    int sum = add(5, 7);
    cout << "Sum: " << sum << endl;

    // =========================
    // STRUCTS
    // =========================
    structExample();

    // =========================
    // ENUMS
    // =========================
    enumExample();

    // =========================
    // CLASSES
    // =========================
    Dog myDog;
    myDog.makeSound();

    return 0;
}

// =========================
// FUNCTION DEFINITIONS
// =========================
int add(int a, int b) {
    return a + b;
}

void printVector(const vector<int>& vec) {
    cout << "Vector elements: ";
    for(const int& n : vec) cout << n << " ";
    cout << endl;
}

void pointerExample() {
    int x = 10;
    int* p = &x;
    cout << "Pointer example - value: " << *p << ", address: " << p << endl;

    int y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << endl;
    int temp = x; x = y; y = temp;
    cout << "After swap: x=" << x << ", y=" << y << endl;
}

void smartPointerExample() {
    auto ptr = make_unique<int>(100);
    cout << "Smart pointer value: " << *ptr << endl;
    // automatic cleanup when ptr goes out of scope
}

void structExample() {
    Person alice = {"Alice", 25};
    cout << "Struct Example - Name: " << alice.name << ", Age: " << alice.age << endl;
}

void enumExample() {
    Level level = HIGH;
    switch(level) {
        case LOW: cout << "Level: LOW" << endl; break;
        case MEDIUM: cout << "Level: MEDIUM" << endl; break;
        case HIGH: cout << "Level: HIGH" << endl; break;
    }
}
