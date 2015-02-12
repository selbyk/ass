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
#define HISTORY_SIZE 10 /* history */

/**
* After reading user input, the steps are:
* (1) fork a child process using fork()
* (2) the child process will invoke execvp()
* (3) if command included &, parent will invoke wait()
*/
void interactive();
int execute_command(char *bin, char **args);
int save_history(char **history, char *cmd_input);

int main(int argc, char *argv[]) {
  if(argc > 1) {
    char *args[MAX_LINE/2 + 1];
    int real_index,
        i,
        offset = 1;
    /* iterate over all arguments, without the meta */
    for (i=1, real_index = i-offset; i < (argc); real_index = ++i-offset) { // printf("string = %s\n", argv[i]);
      args[real_index] = argv[i]; // printf("args[%d] = %s\n", real_index, args[real_index]);
    }
    args[real_index] = NULL; // printf("args[%d] = %s\n", real_index, args[real_index]);
    execvp(args[0], args);
  } else interactive();
  return 0;
}

void interactive(){
  char **args, /* command line arguments */
       **history; /* hold our history */
  args = malloc(MAX_LINE * sizeof(char *));
  history = malloc(HISTORY_SIZE * sizeof(char *));
  int i;
  for (i = 0; i < MAX_LINE; i++){
    args[i] = malloc(MAX_LINE * sizeof(char));
    args[i][0] = '\0';
  }
  for (i = 0; i < HISTORY_SIZE; i++){
    history[i] = malloc(HISTORY_SIZE * sizeof(char));
    history[i][0] = '\0';
  }
  int run = 1, /* flag to determine when to exit program */
      counter = 0; /* position on each string */
  while (run) {
    printf("osh> ");
    fflush(stdout);
    size_t argc = 0;
    char c;
    do {
      c = getchar();
      for(counter = 0; !isspace(c); counter++,c = getchar()) {
        args[argc][counter] = c; //putchar (c);  //printf("%c", c);
      }
      args[argc++][counter] = '\0';
    } while (c == ' ');
    free(args[argc]);
    args[argc] = NULL;
    execute_command(args[0], args);
    if(!(argc > 0 && args[argc-1][0] == '&')) wait(); // Wait if & is appended to command
    args[argc] = malloc(MAX_LINE * sizeof(char));
    args[argc][0] = '\0';
  }
}

int execute_command(char *bin, char **args){
  pid_t pid = fork();
  if (pid == 0) { // Code only executed by child process //printf("Child PID: %i", pid); //printf("user input: `%s`", bin);
    execvp(args[0], args);
  }
  else if (pid < 0) { // failed to fork //printf("Failed to fork"); // Throw exception
  }
  else { // parent
    pid = getpid(); //printf("parent_pid = %d\n", pid);  //printf("Process Complete.\n");
  }
  return 0;
}

int save_history(char **history, char *cmd_input){
  return 0;
}
