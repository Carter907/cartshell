# Cartshell - A C Shell

Cartshell is a shell used to learn more shells in Unix-like operating systems. It is not intended for Windows machines. It features a simple print-eval-execute loop along with many different builtin commands—but there is more to come.

Since simplicity and scalability will be a guiding-principle of this project, developers can fork this repository to make their own shells with different builtins or other functionality.

### State Diagram
<img width="400" height="390" alt="image" src="https://github.com/user-attachments/assets/b83b6d3f-3180-4809-9bc9-cf0040829994" />

### Executing the program

Clone the repository using gh (or traditionally git):
```
gh repo clone Carter907/cartshell
```
Change dir and run the program:
```
cd cartshell && make run
```
Example session:
```
> echo hi
hi
> timenow
Tue Mar 10 09:49:30 2026
> schedtime
-- shell has executed for 0.049173 secs on a CPU --
>
```
