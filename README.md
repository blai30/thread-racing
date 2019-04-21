# CSC 415 - Project 4 - Thread Racing

## Student Name: Brian Lai

## Student ID : 916818167

## Build Instructions
### Windows
```
gcc threadracer.c [filename]
```
or if `make` is configured in %PATH% with MinGW or Cygwin
```
make
```

### Windows Subsystem for Linux (WSL)
```
make
```

### Mac OS X
```
make
```

### Linux
```
make
```

## Run Instructions
### Windows
If no filename was given
```
./a
```
If filename was given while building
```
./[filename]
```
If `make` was used
```
./threadracer
```

### Windows Subsystem for Linux (WSL)
```
./threadracer
```

### Mac OS X
```
./threadracer
```

### Linux
```
./threadracer
```

## Explain why your program produces the wrong output
The program creates 36 threads with the even number threads being designated to adding and odd threads subtracting.
Adder threads will add a value of 10 to the global variable and subtractor threads will subtract 10 from the global variable.
A nanosleep function is called during every iteration which causes a race condition.
When a thread is sleeping, other threads read from the same global variable whether or not that global variable is supposed to be updated by then.
This causes the threads to perform addition or subtraction on the same global variable with its initial value before it gets updated by the other threads.
The temporary value gets written into the global variable by different threads on top of each other causing each thread to read a different value from the global variable when performing addition or subtraction and replacing it.
There is a conflict produced by the threads trampling over each other modifying the same global variable.
