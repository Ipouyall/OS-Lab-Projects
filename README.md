# OS-Lab-Projects

Operating System Lab Projects, University of Tehran, fall 01

## Lab 1: Introduction to xv6

### 1: Adding member's names to Boot Message

The following message will be displayed the system boots up:

```text
Group #3 (TAYAMA) Members:
1- Pouya Sadeghi
2- Ali Ataollahi
3- Ali Hodaee (Nima)
```

### 2: Improving Console Features

The following features added to console:

`Ctrl+N` : Removes all the digits in the current line

`Ctrl+R` : Reverses the current line

`Tab` : Replaces the current line with a command before entered

### 3: Developing & Runing User Program

A user program added to system to find all prime numbers between i to j or j to i:

```text
prime_numbers i j
```

and it stores result in `prime_numbers.txt`.

```text
cat prime_numbers.txt
```

## Lab 2: System Calls

### 1: System Call Using Registers for Parameters

The system call, `find_largest_prime_factor`, finds the largest prime factor of a given number. and the parameter should be passed in `ebx` register.

```c++
int find_largest_prime_factor(void);
```

and you can test it by command bellow:

```text
test_find_largest_prime_factor num
```

### 2: System Calls Using Stack

1. The system call, `get_callers`, returns a history of the callers of each system call.

   ```c++
   int get_callers(int);
   ```

   and you can test it by command bellow:

   ```text
   test_get_callers
   ```

2. The system call, `get_parent_pid`, returns the parent's pid of the current process.

   ```c++
   int get_parent_pid(void);
   ```

   and you can test it by command bellow:

   ```text
   test_get_parent_pid
   ```

3. The system call, `change_file_size`, changes the size of a file by adding `\0` to the end of the file if the new size is larger than the current size or removing the last bytes of the file.

   ```c++
   int change_file_size(const char*, int);
   ```

   and you can test it by command bellow:

   ```text
   test_change_file_size fileName newSize
   ```
