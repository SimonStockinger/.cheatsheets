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
 *
 * Debugging
 * gcc -Wall -o out
 */


#include <stdint.h>
#include <stdio.h>      // Standard I/O
#include <stdlib.h>     // malloc, free, exit
#include <string.h>     // string functions
#include <stdbool.h>    // boolean type
#include <time.h>       // date/time functions

// CONSTANTS
#define PI 3.14159
#define MAX_SIZE 100

// STRUCTS (dt.: "Strukturvariablen")
struct coord {
	uint32_t x;
	uint32_t y;
};

// Mit bezeichner durch `typedef`
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

enum thread_flags {
	TF_READY = 1,
	TF_BLOCKED = 2,
	TF_CRITICAL = 4
};

// FUNCTION DECLARATIONS
int add(int a, int b);
void printArray(int arr[], int size);
void swap(int *a, int *b);
void pointerExample();
void structExample();
void enumExample();

// =========================
// MAIN FUNCTION
// Entry point of the programm
// =========================
int main() {

    // =========================
    // PRIMITIVE DATA TYPES
    // =========================
    int i = 10; // Decimal
	int j = 0x400f; // Hexadecimal
	int k = 040017; // Octal (dec: 16399)
	int l = 'a';
	long ;
	long long ;
    float f = 3.14f;
    double d = 3.1415926535;
    char c = 'A'; // 1 byte, ASCII
    char str[20] = "Hello, World!";
    bool flag = true;


	// Vorzeichen
	signed int i;
	unsigned int j; // usually [0... 4,29...]
	// -> 


	// Fixed size datatypes
	sizeof(int); // 4 (Linux, x86)
	sizeof(l);

	#include <inttypes.h>
	uint8_t a; // unsigned 1 byte [0...255]
	int_fast8_t b; // signed 1 byte [-128...127]

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


	int a[4]; // No initilization
	int a[] = {41, 0, 0, 42}; // Full initilization (In memory: [41|0|0|42])
	int a[4] = {41, 42}; // Unfinished initilization. Undefined fields will be set to 0 [41|42|0|0]
	int a[4] = {0}; // 0 initilization [0|0|0|0]
	coord c[4] = {{1,1}, {2,2}, {3,3}, {4,4}};

	// access
	a[0] = 42;
	a[3] = 42;
	c[0].x = 42;

	// a[232] = 42; // COMPILES AND MAY EXECUTE FINE BUT CORRUPTS MEMORY!


	// Get number of elements
	sizeof(a) / sizeof(a[0]);




	struct coord c1;
	c1.x = 5;
	c1.y = 10;

	Person simon;
	simon.age = 21;
	simon.name = "Simon Stockinger";










	// POINTERS 
	int i = 5;
	int *p = &i;
	void *r = p;
	struct coord c, *d = NULL // COnvention: Null = invalid pointer


	// Dereferencing
	int j = *p;
	int k = *(int*)r;
	int x = (*d).x;
	int y = d->y; // short for (*d).y


	// Anwendung: 
	// 1.
	//Compiler erstellt lokale Kopie von eingabe-variable und arbeitet auf dieser innerhalb einer Funktion, wenn Parameter übergeben werden (pass-by-value)
	// -> Pointer: pass-by-reference -> Arbeiten auf originalen Daten (+schneller)
	void setX(coord c, int x) {
		c.x = x;
	}

	void setX(cord *c; int x) {
		c->x = x;
	}


	// 2.
	// Komplexe Datentypen
	// f.e. Linked list via next pointer
	struct entry {
		int item;
		struct entry *next;
	} first, second; // Variablen initialisierung

	first.item = 123;
	first.next = &second;
	
	second.item = 456;
	second.next = NULL;

	// iterate:
	struct entry *e = &first;
	while (e != NULL) {
		// do something with e -> item
		e = e->next;
	}


	// Poiner Arithmetrik
	int a[10];
	int *p = a;
	int i = *p;

	int i = p[1];

	p = p + 1; // p = 0x100 + sizeof(*p) [das ist sizeof(int) nicht sizeof(int*)] = 0x100 + 4 = 0x104
	int i = *p;


	// Use after free: lokale Variablen
	// Allocation auf dem Stack
	

	// Allocation auf dem Heap -> Datenmanagement selber kümmern
	# include <stdlib.h>
	void *malloc(size_t size); // Allocates memory on heap
	void free(void *prt); // Frees memory on heap


	// Double Pointers: Pointer -> Pointer -> Datatype
	

	// Function Pointers
	typedef int (*myfunc)(int, int);

	int sum(int a, int b) 
	{
		return a + b;
	}


	int calc() 
	{
		myfunc f = sum;
		return sum(1,2);
	}

	// =========================
    // POINTERS
    // =========================
    pointerExample();




	// Strings [H|e|l|l|o|!|\0] chars + terminating null (\0)
	char c[] = "Hello World!";
	char c[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'}


	char *c = "Hello World!";
	// c[1] CRASH
	
	const char *c = "Hello World!"; // Keine Schreibzugriffe zulassen
	// c[1] Compilierfehler


	//printf()
	int printf(const char *format, ...); // "..." bedeutet: Variable Anzahl an Parametern








	// Bit Arithmetrik
	// Für Arbeiten auf Hardware-Registern (Low-level) oder arbeiten mit hoher Datendichte 
	//
	


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
	// * -> Pointer declaration
	// & -> Address of pointer
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
