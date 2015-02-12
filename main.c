/*
ASS: A Simple Shell

A simple UNIX shell with history feature

Author: Selby Kendrick
*/

/* Import required libraries */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE 80 /* The maximum length command */

/**
* After reading user input, the steps are:
* (1) fork a child process using fork()
* (2) the child process will invoke execvp()
* (3) if command included &, parent will invoke wait()
*/
int execute_command(char *bin, char **args);

int i;

int main(int argc, char *argv[]) {
  size_t size = MAX_LINE;

  if(argc > 1) {
    char *args[MAX_LINE/2 + 1];
    /* iterate over all arguments */
    int i=1,
        real_index,
        offset = 1;
    for (real_index = i-offset; i < (argc); real_index = ++i-offset) {
      printf("string = %s\n", argv[i]);
      args[real_index] = argv[i];
      printf("args[%d] = %s\n", real_index, args[real_index]);
    }
    args[real_index] = NULL;
    printf("args[%d] = %s\n", real_index, args[real_index]);
    execvp(args[0], args);
  } else {
    char **args; /* command line arguments */
    args = malloc(size * sizeof(char *));
    for (i = 0; i < size; i++){
      args[i] = malloc(size * sizeof(char));
      args[i][0] = '\0';
    }
    int run = 1; /* flag to determine when to exit program */
    int counter = 0;

    while (run) {
      printf("osh> ");
      fflush(stdout);
      char *buf = NULL;

      if (getline(&buf, &size, stdin) == -1) {
          printf("No line\n");
      } else {
        size_t argc = 0;
        if(buf[0] != '\0') {
          counter = 0;
          for(i = 0; !isspace(buf[i]); i++) {
            if(buf[i] == ' '){
              args[argc++][counter] = '\0';
              counter = 0;
            };
            args[argc][counter++] = buf[i];
            //printf("%c", buf[i]);
          }
          if(i > 1){
            args[argc++][counter] = '\0';
            args[argc] = NULL;
            printf("%d\n", argc);
            for(i = 0; i < argc; i++) {
              //printf("%s ", args[i]);
            }
            printf("%s - %d args\n", args[0], argc-1);
            execute_command(args[0], args);
            if(!(argc > 0 && args[argc-1] == '&')) wait(); // Wait if & is appended to command
          }
        }
      }
    }
  }
  return 0;
}

int execute_command(char *bin, char **args){
  pid_t pid = fork();
  if (pid == 0) { // Code only executed by child process
      printf("Child PID: %i", pid);
      printf("user input: `%s`", bin);
      execvp(args[0], args);
  }
  else if (pid < 0) { // failed to fork
      printf("Failed to fork"); // Throw exception
  }
  else { // parent
    pid = getpid();
    printf("parent_pid = %d\n", pid);
    printf("Process Complete.\n");
  }
  return 0;
}
