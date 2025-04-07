# 🏛️ Philosophers - The Philosophy of Concurrency

## 📜 Description
The **Philosophers** project is a simulation of the classic **Dining Philosophers Problem**. It introduces the management of **threads**, **mutexes**, and **synchronization** in C, covering essential concepts of concurrency and shared resource access.

## 🔧 Project Rules
- A group of philosophers sits around a table with a bowl of spaghetti.
- Each philosopher can **think**, **eat**, or **sleep**, but never do two actions simultaneously.
- To eat, a philosopher must pick up two forks, but only one fork is available between each pair of philosophers.
- If a philosopher doesn’t eat within a given time, they will starve, and the simulation ends.
- **Goal**: Coordinate philosophers so they can eat without causing **deadlocks** or **race conditions**.

## 🏗️ Implementation
### 🔹 Mandatory Part (`philo/`)
- Uses **threads** and **mutexes** to manage forks.
- Must prevent race conditions and deadlocks.
- Strict memory management and error handling.

### ✨ Bonus (`philo_bonus/`)
- Uses **processes** instead of threads.
- **Semaphores** replace mutexes for fork management.
- Each philosopher is a separate process.

## 📌 Usage
Compile the project with:
```bash
make
```
Run the simulation with:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [times_each_philosopher_must_eat]
```
Example:
```bash
./philo 5 800 200 200
```
For the bonus version:
```bash
make bonus
./philo_bonus 5 800 200 200
```

## 📂 Submitted Files
- `Makefile` (with `all`, `clean`, `fclean`, `re` rules)
- C source files (`*.c, *.h`)
- Directories:
    - `philo/` → Thread-based implementation
    - `philo_bonus/` → Process & semaphore-based implementation

## 🚀 Key Learnings
✅ Thread and process management  
✅ Synchronization using mutexes and semaphores  
✅ Avoiding race conditions and deadlocks  
✅ Efficient memory management

---

### 🧪 Testing Cases

| Command | Expected Result |
|---------|-----------------|
| `./philo` | ❌ Error: wrong number of arguments |
| `./philo 5 800 200 200` | ✅ Valid |
| `./philo 5 800 200 200 -3` | ❌ Error: must be > 0 |
| `./philo 3 800 abc 200` | ❌ Error: must be numbers |
| `./philo 0 800 200 200` | ❌ Error: must be > 0 |
| `./philo 3 800 200 200 3` | ✅ Valid |

---

### 🔍 How to Check for Memory Leaks in Your Project

#### 🧪 Option 1: Use `valgrind` (the most thorough method)

```bash
valgrind --leak-check=full --show-leak-kinds=all ./philo 3 800 200 200 3
```

#### 📌 Explanation of the flags:

- `--leak-check=full`: shows all memory leaks, even the smallest ones.
- `--show-leak-kinds=all`: displays direct, indirect, and other types of leaks.
- You can also add:  
  `--track-origins=yes` to identify the origin of the leak.

---

#### 🔥 Example of expected output:

```bash
❯ ./philo 5 800 200 200 -3
Error: invalid input(solo integers :(
❯ valgrind --leak-check=full --show-leak-kinds=all ./philo 3 800 200 200 3
==263492== Memcheck, a memory error detector
==263492== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==263492== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==263492== Command: ./philo 3 800 200 200 3
==263492== 
581 2 has taken left fork
591 2 has taken right fork
591 2 is eating
1373 3 has taken left fork
1374 3 has taken right fork
1374 2 is sleeping
1393 2 died
1396 1 has taken left fork
==263492== 
==263492== HEAP SUMMARY:
==263492==     in use at exit: 0 bytes in 0 blocks
==263492==   total heap usage: 7 allocs, 7 frees, 2,272 bytes allocated
==263492== 
==263492== All heap blocks were freed -- no leaks are possible
==263492== 
==263492== For lists of detected and suppressed errors, rerun with: -s
==263492== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
