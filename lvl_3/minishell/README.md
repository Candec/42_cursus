# minishell
## Build a simplified version of a shell - (under development :gear:)
### Our shell should:
- [ ] Not interpret unclosed quotes or unspecified special characters like \ or ;.
- [ ] Not use more than one global variable, think about it and be ready to explain why
you do it.
- [x] Show a prompt when waiting for a new command.
- [x] Have a working History.
- [x] Search and launch the right executable (based on the PATH variable or by using
relative or absolute path)
- It must implement the builtins:
 - [x]   echo with option -n
 - [ ]   cd with only a relative or absolute path
 - [x]   pwd with no options
 - [x]   export with no options
 - [x]   unset with no options
 - [x]   env with no options or arguments
 - [x]   exit with no options
 - [x]   ’ inhibit all interpretation of a sequence of characters.
 - [ ]   " inhibit all interpretation of a sequence of characters except for $.
- Redirections:
 - [x]   "<" should redirect input.
 - [x]   ">" should redirect output.
 - [x]   “<<” read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
 - [x]   “>>” should redirect output with append mode.
 - Pipes 
   - [x]  "|". The output of each command in the pipeline is connected via a pipe to the
	  input of the next command.
 - [x]   Environment variables ($ followed by characters) should expand to their values.
 - [x]   $? should expand to the exit status of the most recently executed foreground
	  pipeline.
 - [x]   ctrl-C ctrl-D ctrl-\ should work like in bash.
- When interactive:
  - [x]   ctrl-C print a new prompt on a newline.
  - [x]   ctrl-D exit the shell.
  - [x]   ctrl-\ do nothing.
 
readline function can produce some leaks, no need to fix this.

For every point, if you have any doubt take bash as a reference.

### File Organization
| Folder      | Description |
| ----------- | ----------- |
| Parser     | Contains a parser and a lexer that build an Abstract Syntax Tree. The goal is to read the input provided from the user and separate it into actionable commands. Also checks for syntax errors.      |
| Cleaning   | Contains functions to make sure that we go into the next phase (i.e. exiting or new line from user) cleanly. Frees any unnecessary memory. |
| Commands   | Contains functions to replicate bash commands that need to be hardcoded. "cd" is a good example, since we cannot fork and then call chdir because when we exit the fork we'll be left in the same directory. |
| Executing   | Executes commands given by the parser via ```execve```. |
| Redirecting | Takes care of redirecting STDIN and STDOUT when necessary. A good example is that it creates the pipes needed between two processes when givne the ```pipe``` command. |
| Reader | Uses the ```readline``` functions to read a line from the user and create a working history. |
| Utils | Helpful everyday functions. |

### Usage
This project uses a makefile, so to run the program you can compile with ```make``` and then enter ```./minishell```. Minishell usually runs with no arguments but for debugging you can use the ```-debug``` flag (i.e. ```./minishell -debug```).

### External functions that are allowed
- readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history,
- printf, malloc, free, write,
- access, open, read, close,
- fork, wait, waitpid, wait3, wait4,
- signal, sigaction, kill,
- exit,
- getcwd,
- chdir,
- stat, lstat, fstat,
- unlink,
- execve, dup, dup2, pipe,
- opendir, readdir, closedir,
- strerror, perror,
- isatty, ttyname, ttyslot,
- ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs.


### Know bugs
-- Tested on Linux & OSx --
- [x] ~~Shell hangs when echo is written without quotes~~
- [x] ~~echo -n enters in a loop and would not exit~~
- [x] ~~exit -v enters in a loop and would not exit~~
- [x] ~~Typing 'echo "ls"' would produce the following output Expanding quote\n --> ls command~~
- [ ] Pressing tab without input written would try to autocomplete with the files in the directory
- [x] ~~ls works, ls -l doesn't. Shell enters in a loop and would not exit~~
- [x] ~~$? works, but it also prints "minishell: command not found:"~~
- [ ] $? + $? prints minishell: command not found: X
- [x] ~~After typing something and pressing CTRL + C a couple of times, it keeps saving the typed text in the buffer with the message "minishell: command not found:"~~
- [x] ~~After typing the commnad "cat" without arguments the Shell enters in a loop and would not exit~~
- [x] ~~export var=x doesn't export the var~~
