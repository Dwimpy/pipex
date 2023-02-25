Pipex - 42 Project
===========================

Summary
-------

Pipex is a program that takes four arguments: two file names and two shell commands with their parameters. It reads the contents of the first file and executes the two shell commands using the contents of the file as input. It then writes the output of the second command to the second file.

Compilation
-----------
```bash
  # Clone the repository in a folder
  git clone https://github.com/Dwimpy/pipex <folder name>
  # Initialize submodules
  git submodule init
  # Get latest submodule updates
  git pull --recurse-submodule
  # Compile and link object files
  make
```

Francinette Results
-------------------
>[Francinette Tester for 42 Students](https://github.com/xicodomingues/francinette) \
> Follow the instructions in the aforementioned link to install the tester

![Paco Tester](https://i.imgur.com/T59gYH5.png)

Usage
-----

```bash
./pipex file1 cmd1 cmd2 file2
```
Where:

*   `file1` is the input file.
*   `cmd1` is the first shell command with its parameters.
*   `cmd2` is the second shell command with its parameters.
*   `file2` is the output file.

The program should behave the same as the shell command below:

```bash
< file1 cmd1 | cmd2 > file2
```
Bonus Features
--------------

In addition to the mandatory requirements, the program includes bonus features:

*   Handling multiple pipes:

```bash
> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Should behave like:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
*   Support for `<<` and `>>` operators when the first parameter is "here\_doc":

```bash
> ./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like:

```bash
cmd << LIMITER | cmd1 >> file
```
