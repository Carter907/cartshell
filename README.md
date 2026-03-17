# Cartshell - A C Shell

Cartshell is a shell used to learn more shells in Unix-like operating systems. It is not intended for Windows machines. It features a simple print-eval-execute loop along with many different builtin commands—but there is more to come.

One goal I have for this project is to make it POSIX compliant. Here are some ways in which I intend to do that:
1. Use the appropriate Feature Test Macros (`man 7 feature_test_macros`)
2. Avoid including any non-standard libraries
3. Use correct compilations flags that are standard

Since simplicity and scalability will be a guiding-principle of this project, developers can fork this repository to make their own shells with different builtins or other functionality.

### State Diagram
<img width="595" height="547" alt="image" src="https://github.com/user-attachments/assets/3a9a2422-0319-4223-8a0f-332d2ec78140" />

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
