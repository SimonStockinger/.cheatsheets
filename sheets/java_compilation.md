# Java 21 Cheat Sheet — **Compilation Focus**

---

## 1. Basic Java Compilation Workflow

### File Naming
- **One public class per file**
- Filename **must match** public class name  
  ```java
  public class Hello {}
  ```
  File → `Hello.java`

---

## 2. Compile a Single File

```bash
javac Hello.java
```

- Produces: `Hello.class`
- Bytecode target: JVM
- Default output: same directory as source

---

## 3. Run Compiled Code

```bash
java Hello
```

- Do **not** include `.class`
- JVM looks for `public static void main(String[] args)`

---

## 4. Compile & Run Without Explicit Compilation (Java 11+)

Java 21 supports **single-file source execution**:

```bash
java Hello.java
```

- Internally compiles + runs
- No `.class` file stored
- Good for scripts / quick tests

---

## 5. Multiple Files Compilation

```bash
javac Main.java Utils.java
```

Or compile all:

```bash
javac *.java
```

Dependencies are automatically resolved if in same directory/package.

---

## 6. Output Directory (`-d`)

Specify where `.class` files go:

```bash
javac -d out Hello.java
```

Creates directory if missing.

---

## 7. Packages

### Source Structure
```
src/com/example/Main.java
```

### Compile
```bash
javac -d out src/com/example/Main.java
```

### Run
```bash
java -cp out com.example.Main
```

---

## 8. Classpath (`-cp` or `-classpath`)

Defines where Java looks for classes and JARs.

```bash
javac -cp lib/* Main.java
java -cp "out:lib/*" Main
```

Windows:
```bash
out;lib/*
```

Linux/macOS:
```bash
out:lib/*
```

---

## 9. Modules (Java 9+)

### Compile Module
```bash
javac -d mods --module-source-path src $(find src -name "*.java")
```

### Run Module
```bash
java --module-path mods -m com.example/com.example.Main
```

---

## 10. JAR Compilation & Execution

### Create JAR
```bash
jar cf app.jar -C out .
```

### Run JAR
```bash
java -jar app.jar
```

### Executable JAR (Manifest)
`MANIFEST.MF`
```
Main-Class: com.example.Main
```

---

## 11. Compiler Options

| Option | Purpose |
|--------|--------|
| `-d` | Output directory |
| `-cp` | Classpath |
| `--release 21` | Target Java version |
| `-g` | Include debug info |
| `-Xlint` | Enable warnings |
| `-verbose` | Show compilation details |
| `-encoding UTF-8` | Source encoding |

Example:

```bash
javac --release 21 -Xlint -d out Main.java
```

---

## 12. Preview Features (Java 21)

Enable preview compilation:

```bash
javac --enable-preview --release 21 Main.java
java --enable-preview Main
```

---

## 13. JShell (REPL)

Interactive compilation/testing:

```bash
jshell
```

Useful for:
- Quick syntax tests
- API exploration
- No file creation

---

## 14. Environment Variables

### `JAVA_HOME`
Path to JDK.

### `PATH`
Must include:
```
$JAVA_HOME/bin
```

Check versions:

```bash
java -version
javac -version
```

---

## 15. Common Errors

| Error | Cause |
|------|------|
| `ClassNotFoundException` | Wrong classpath |
| `NoClassDefFoundError` | Missing dependency at runtime |
| `package does not exist` | Compile order / classpath issue |
| `public class must match filename` | Naming mismatch |

---

## 16. Quick Command Summary

```bash
# compile
javac File.java

# run
java File

# single-file run
java File.java

# with classpath
javac -cp lib/* File.java
java -cp .:lib/* File

# preview
javac --enable-preview --release 21 File.java
java --enable-preview File
```

---

## 17. Java 21 Notes Relevant to Compilation

- Java 21 = **LTS**
- Preview features require explicit flags
- Pattern Matching, Virtual Threads, Sequenced Collections may require `--enable-preview` depending on usage
- Default source/target = current JDK unless `--release` specified

---

**Core Principle:**  
`javac` → produces bytecode  
`java` → executes bytecode or source (Java 11+)
