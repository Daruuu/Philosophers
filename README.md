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