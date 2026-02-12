/*
 * =========================
 * C Tutorial File
 * =========================
 
 * Key Notes:
 * - C is a procedural, compiled language.
 * - Strongly typed: variables must have a declared type.
 * - Primitive types: int, float, double, char, _Bool (or bool via stdbool.h)
 * - Strings are char arrays; use null-termination '\0'.
 * - Pointers are essential: allow direct memory access.
 * - Memory management is manual (malloc/free).
 * - Structs allow grouping of related data.
 * - Enums define named integral constants.
 * - Functions can return values or void, support pass-by-value or pass-by-reference using pointers.
 * - Standard input/output: printf, scanf.
 * - Loops: for, while, do-while; Conditionals: if, switch.
 * - Header files (.h) can be used to declare functions/structs for modular code.
 * - Preprocessor directives: #include, #define.
 *
 * Compiling and Running:
 * 1. Compile: gcc C.c -o CProgram
 * 2. Run: ./CProgram
 */


#include <stdio.h>      // Standard I/O
#include <stdlib.h>     // malloc, free, exit
#include <string.h>     // string functions
#include <stdbool.h>    // boolean type
#include <time.h>       // date/time functions

// CONSTANTS
#define PI 3.14159
#define MAX_SIZE 100

// STRUCTS
typedef struct {
    char name[50];
    int age;
} Person;

// ENUM
typedef enum {
    LOW,
    MEDIUM,
    HIGH
} Level;

// FUNCTION DECLARATIONS
int add(int a, int b);
void printArray(int arr[], int size);
void swap(int *a, int *b);
void pointerExample();
void structExample();
void enumExample();

// =========================
// MAIN FUNCTION
// =========================
int main() {

    // =========================
    // PRIMITIVE DATA TYPES
    // =========================
    int i = 10;
    float f = 3.14f;
    double d = 3.1415926535;
    char c = 'A';
    char str[20] = "Hello, World!";
    bool flag = true;

    printf("Integer: %d\n", i);
    printf("Float: %f\n", f);
    printf("Double: %lf\n", d);
    printf("Char: %c\n", c);
    printf("String: %s\n", str);
    printf("Boolean: %d\n", flag);

    // =========================
    // ARRAYS
    // =========================
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    printArray(numbers, size);

    // =========================
    // POINTERS
    // =========================
    pointerExample();

    // =========================
    // CONDITIONALS
    // =========================
    if (i > 5) {
        printf("i is greater than 5\n");
    } else {
        printf("i is 5 or less\n");
    }

    int day = 2;
    switch(day) {
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        default: printf("Other day\n"); break;
    }

    // =========================
    // LOOPS
    // =========================
    printf("For loop:\n");
    for(int j = 0; j < 5; j++) {
        printf("%d ", j);
    }
    printf("\n");

    printf("While loop:\n");
    int w = 0;
    while (w < 3) {
        printf("%d ", w);
        w++;
    }
    printf("\n");

    printf("Do-While loop:\n");
    int dw = 0;
    do {
        printf("%d ", dw);
        dw++;
    } while(dw < 2);
    printf("\n");

    // =========================
    // FUNCTIONS
    // =========================
    int sum = add(5, 7);
    printf("Sum: %d\n", sum);

    // =========================
    // STRUCTS
    // =========================
    structExample();

    // ENUMS
    enumExample();

    // =========================
    // DYNAMIC MEMORY
    // =========================
    int *dynamicArray = malloc(5 * sizeof(int));
    if (dynamicArray == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for(int k = 0; k < 5; k++) dynamicArray[k] = k*2;
    printArray(dynamicArray, 5);
    free(dynamicArray);

    // TIME
    time_t t;
    time(&t);
    printf("Current time: %s\n", ctime(&t));

    // 
    return 0;
}

// =========================
// FUNCTION DEFINITIONS
// =========================
int add(int a, int b) {
    return a + b;
}

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pointerExample() {
    int x = 10;
    int *p = &x;
    printf("Pointer example - value: %d, address: %p\n", *p, (void*)p);

    int y = 20;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After swap: x=%d, y=%d\n", x, y);
}

void structExample() {
    Person alice;
    strcpy(alice.name, "Alice");
    alice.age = 25;
    printf("Struct Example - Name: %s, Age: %d\n", alice.name, alice.age);
}

void enumExample() {
    Level level = HIGH;
    switch(level) {
        case LOW: printf("Level: LOW\n"); break;
        case MEDIUM: printf("Level: MEDIUM\n"); break;
        case HIGH: printf("Level: HIGH\n"); break;
    }
}
