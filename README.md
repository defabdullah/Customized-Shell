
# CUSTOMIZED SHELL
CMPE 322 Operation Systems Course Homework.

This project consists implementation of some UNIX-like commands which is written in C++
language. It consists of three files main.cpp, main.h and Makefile. All implementations are inside of
main.cpp file. Beginning of the main function it gets necessary environment variables (USER and
EDITOR). Then allocates spaces for dynamic variables with the determined lengths in header files. Then
goes into main loop to take inputs. Unless there is exit command loop continue to take input and run it.
After exit command it deallocate dynamic memory and program terminated.

## COMMANDS

**- listdir**

It creates a directory pointer to current directory then reads all the filenames inside of it.

**- mycomputername**

It gets computer name from gethostname method then prints it.

**- whatsmyip**

It executes “hostname -i” command.

- **hellotext**

It executes default editor command in environment variable.

**- printfile**

If there is only file name after command, it open file and prints line by line when pressed enter. But
there can be redirection operation among 2 files with this command. In this situation it executes “cp”
command with given files in that format “printfile file1 > file2”

**- dididothat**

It takes an argument within quotation marks then search it in last 15 commands. If it founds prints
“YES”, else “NO”.

Notes:

* All necessary constants defined in header file.

* Make file create an executable myShell with “make” command




