# Simple Shell
## Description
    - a UNIX command line interpreter
    - Alx team project

# Compilation
    - gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Team members
    - Yohannes Mekonnen
    - Marwane Madini
# Testing
    - this shell works in interactive mode:
        $ ./hsh
        ($) /bin/ls
        hsh main.c shell.c
        ($)
        ($) exit
        $
    - also in non-interactive mode:
        $ echo "/bin/ls" | ./hsh
        hsh main.c shell.c test_ls_2
        $
        $ cat test_ls_2
        /bin/ls
        $
        $ cat test_ls_2 | ./hsh
        hsh main.c shell.c test_ls_2
        $

# File and function content included in this project
    ========== builtins1.c ==========
    sh_env
    sh_cd
    sh_help
    sh_exit
    ========== builtins2.c ==========
    sh_setenv
    sh_unsetenv
    ========== execute.c ==========
    get_function
    execute
    ========== main.c ==========
    main
    ========== new_process.c ==========
    new_process
    ========== read_line.c ==========
    read_line
    ========== read_stream.c ==========
    read_stream
    ========== shell.h ==========
    struct builtin
    ========== split_line.c ==========
    split_line

# Reference
- https://medium.com/@santiagobedoa/coding-a-shell-using-c-1ea939f10e7e
- https://brennan.io/2015/01/16/write-a-shell-in-c/
