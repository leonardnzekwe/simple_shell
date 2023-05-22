# C - SIMPLE SHELL

A simple UNIX command interpreter.
An ALX SWE Project.

## Authors

- [@rahma-cloud](https://www.github.com/rahma-cloud)
- [@leonardnzekwe](https://www.github.com/leonardnzekwe)

## Features

- **Reads, Evalutes, Prints and Loops (REPL)**
- Read Command Line Arguments
- Evalute the Arguments
- Print the Evaluted Arguments Output
- Loop Re-Prompting for New Input to Read

## Task Roadmap

- [x]  **Task 0:** A beautiful code that passes the Betty checks.
- [x]  **Task 1:** A UNIX command line interpreter.
    - **Usage:** simple_shell
    - **Features:**
    - Displays a prompt and waits for the user to type a command.
    - The prompt is displayed again each time a command has been executed.
    - The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
    - The command lines are made only of one word. No arguments will be passed to programs.
    - If an executable cannot be found, it prints an error message and displays the prompt again.
    - Executes commands with `execve`
    - It handles errors with `perror`
    - It handles the “end of file” condition `Ctrl+D`
    - Didn't use the `PATH`, nor implemented any built-ins at this point.
- [x]  **Task 2:** Handling command lines with arguments.
- [x]  **Task 3:** Handling the `PATH`. Calling `fork` only if command exits.
- [x]  **Task 4:** Implementing the `exit` built-in, that exits the shell
    - Usage: `exit`. Didn't handle any argument to the built-in exit at this point.
- [x]  **Task 5:** Implementing the `env` built-in, that prints the current environment.
- [x]  **Task 6:** Implementing a custom `getline` function
    - Features: Uses a buffer to read many chars at once and calls the least possible the read system call. Uses static variables. Doesn't move the cursor.
- [x]  **Task 7:** Implementing a custom `strtok` function.
- [x]  **Task 8:** Handling arguments for the built-in `exit`.
    - Usage: `exit status`, where `status` is an integer used to exit the shell.
- [ ]  **Task 9:** Implement the `setenv` and `unsetenv` builtin commands.
- [ ]  **Task 10:** Implement the builtin command `cd`.
- [ ]  **Task 11:** Handle the commands separator `;`.
- [ ]  **Task 12:** Handle the `&&` and `||` shell logical operators.
- [ ]  **Task 13:** Implement the `alias` builtin command.
- [ ]  **Task 14:** Handle variables replacement. Handle the `$?` variable. Handle the `$$` variable.
- [ ]  **Task 15:** Handle comments `#`.
- [ ]  **Task 15:** Implement the simple shell taking a file as a command line argument.
    - Usage: simple_shell [filename]
    - The file contains all the commands that the simple shell should run before exiting, one command per line.
    - In this mode, the shell should not print a prompt and should not read from stdin

## Files

- **_getenv.c:** contains the `_getenv`, a custom definition of the `getenv` function.
- **AUTHORS:** conatains git log generated list of contributors to the project.
- **dup_args.c:** contains the `dup_args` function that duplicates the arguments.
- **exe_args.c:** conatains the `exe_args` and `free_mem` function that executes valid commands and free dynamically allocated memories, respectively.
- **exit_shell.c:** contains the `exit_shell` function that exit the shell either with a status code or without.
- **get_args.c:** contains the `get_args` REPL base function and `check_get_args` function that catches the error cases of the `get_args` function.
- **get_line.c:** contains `get_line` function with its helper functions `refill_buffer` and `read_buffer`. The `get_line` is a custom implementation of the C standard `getline`  function.
- **main.c:** contains the `main` function, which is the entry point of the program. It also contains the `sigint_handler` function which gets excutes when the program recieves a `SIGINT` in the `signal` std functions.
- **main.h:** contains all the header files, global variables, macro definition, REPL function protoytpes and string manipulation functions prototypes.
- **more_str_funcs:** contains `_strcmp` `_strdup` `_memcpy` `_strtok` `_atoi` functions, which are used for string manipulation operations.
- **print_env.c:** contains the `print_env` function, that prints the environment variables.
- **process_args.c:** contains `process_args`, a helper function to `get_args` function.
- **str_funcs:** contains `_strlen` `_strcpy` `strchr` `strncmp` `strcat` functions, which are used for string manipulation operations.
- **tok_args:** contains `tok_args` function, whic is used to tokenise the command line arguments.
- **tok_path:** contains `tok_path` function, whic is used to tokenise the enviroment `PATH`.

## Testing Directory

**test:** contains the `text_cmds` file, which has some commands that the simple shell should run before exiting, one command per line.

## Notes

- Underway Features: `setenv` `unsetenv`, `cd`, `;`, `&&` `||`, `alias`, `Variables`, `Comments` and `File as input`; which are task 9, 10, 11, 12, 13, 14, 15, 16 conditons respectively.

## Limitations

- The simple shell implementation doesn't yet handle special characters : ", ', `, \, *, &, #
- It's yet to be able to move the cursor
