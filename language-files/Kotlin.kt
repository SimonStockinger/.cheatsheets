/*
 * =========================
 * Kotlin Tutorial File
 * =========================
 *
 * Key Notes:
 * - Kotlin is a statically typed, modern programming language for JVM, Android, and more.
 * - Fully interoperable with Java.
 * - Supports object-oriented and functional programming.
 * - Variables: use 'val' for immutable, 'var' for mutable.
 * - Null safety: types are non-null by default; use '?' for nullable types.
 * - Common primitive types: Int, Long, Float, Double, Boolean, Char, String.
 * - Functions can be top-level, inside classes, or objects.
 * - Classes support inheritance, interfaces, and data classes.
 * - Collections: List, MutableList, Set, Map, etc.
 * - Lambda expressions and higher-order functions are supported.
 * - Exception handling uses try-catch-finally.
 *
 * Compiling and Running (Console):
 * 1. Compile: kotlinc Kotlin.kt -include-runtime -d Kotlin.jar
 * 2. Run: java -jar Kotlin.jar
 */


///////////////////////////
// PRIMITIVE TYPES
///////////////////////////
val num: Int = 42
var f: Float = 3.14f
val d: Double = 3.1415926535
val c: Char = 'A'
val b: Boolean = true
val str: String = "Hello, Kotlin!"

println("Integer: $num")
println("Float: $f")
println("Double: $d")
println("Char: $c")
println("Boolean: $b")
println("String: $str")

///////////////////////////
// ARRAYS & COLLECTIONS
///////////////////////////
val numbers = arrayOf(1, 2, 3, 4, 5)
val list: MutableList<Int> = mutableListOf(10, 20, 30)
list.add(40)

println("Array: ${numbers.joinToString()}")
println("List: $list")

///////////////////////////
// LOOPS
///////////////////////////
for (x in 0 until 5) println("For loop: $x")

var y = 0
while (y < 3) {
    println("While loop: $y")
    y++
}

var z = 0
do {
    println("Do-while loop: $z")
    z++
} while (z < 2)

///////////////////////////
// CONDITIONALS
///////////////////////////
if (num > 50) {
    println("num is greater than 50")
} else {
    println("num is 50 or less")
}

val day = 2
when(day) {
    1 -> println("Monday")
    2 -> println("Tuesday")
    else -> println("Other day")
}

///////////////////////////
// FUNCTIONS
///////////////////////////
fun add(a: Int, b: Int): Int = a + b
println("Sum: ${add(5,7)}")

fun greet(name: String, greeting: String = "Hello") {
    println("$greeting, $name!")
}

greet("Alice")
greet("Bob", "Hi")

///////////////////////////
// DATA CLASSES & CLASSES
///////////////////////////
data class Person(val name: String, val age: Int)

val alice = Person("Alice", 25)
println("Person: ${alice.name} (${alice.age})")

class Animal(val name: String) {
    open fun move(distance: Int = 0) {
        println("$name moved $distance meters")
    }
}

class Dog(name: String) : Animal(name) {
    fun bark() {
        println("Woof!")
    }
}

val dog = Dog("Buddy")
dog.bark()
dog.move(10)

///////////////////////////
// ENUMS
///////////////////////////
enum class Level { LOW, MEDIUM, HIGH }
val level = Level.HIGH
println("Enum Level: $level")

///////////////////////////
// HIGHER-ORDER FUNCTIONS & LAMBDAS
///////////////////////////
val numbers2 = listOf(1,2,3,4,5)
val squares = numbers2.map { it * it }
println("Squares: $squares")

val evens = numbers2.filter { it % 2 == 0 }
println("Even numbers: $evens")

///////////////////////////
// NULL SAFETY
///////////////////////////
var nullableStr: String? = null
println("Nullable string length: ${nullableStr?.length ?: "null"}")

///////////////////////////
// EXCEPTION HANDLING
///////////////////////////
try {
    val result = 10 / 0
} catch(e: ArithmeticException) {
    println("Division by zero!")
} finally {
    println("Finally block executed")
}

///////////////////////////
// TIME / DATE
///////////////////////////
import java.time.LocalDateTime
val now = LocalDateTime.now()
println("Current date and time: $now")
