/*
ASS: A Simple Shell

A simple UNIX shell with history feature

Author: Selby Kendrick
*/

/* Import required libraries */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h> // Required by for routine
#include <sys/types.h>
#include <stdlib.h>   // Declaration for exit()

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


/* Global Definitions */
#define MAX_LINE 80 /* The maximum length command */

/* Global Variables */
char **input;

int main(int argc, char *argv[]) {
  /* if cmd line args given, run them without interactive interface */
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
    //char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int run = 1; /* flag to determine when to exit program */
    while (run) {
      run = 0;
      printf("ass> ");
      //fflush(stdout);

      char *buffer = NULL;
      int read;
      size_t len = MAX_LINE;
      read = getline(&buffer, &len, stdin);
      if (-1 != read)
          puts(buffer);
      else
          printf("No line read...\n");

      int counter = 0;

      //input[0] = split_string(buffer, " ");
      printf("user input: `%s`", input[0]);
      /**
      * After reading user input, the steps are:
      * (1) fork a child process using fork()
      * (2) the child process will invoke execvp()
      * (3) if command included &, parent will invoke wait()
      */
      //pid_t pID = fork();
      /*if (pID == 0)                // child
      {
          // Code only executed by child process
          printf("Child PID: %i", pID);
          printf("user input: `%s`", input);
          exit(0);
      }
      else if (pID < 0)            // failed to fork
      {
          printf("Failed to fork");
          exit(1);
          // Throw exception
      }
      else                                   // parent
      {
        printf("Process Complete.\n");
        exit(0);
      }*/
    }
  }

  return 0;
}
