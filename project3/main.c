/*-------------------------------------------------------------*/
// Author: Kyle Anderson
// Description: Project 3 - Basic Shell
// Class: CS 3733 Operating Systems
/*-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_TOKENS 10
#define MAX_TOK_LGTH 80

int promptUser(char *tokens[MAX_TOKENS]);

int main()
{

    int i = 0, tokenCount, progExitStatus, queueCount = 0, *pidArray, k = 0;
    ;
    char *command, **tokens;
    tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    pidArray = (int *)malloc(5 * sizeof(int));
    char curDir[72];

    while (strcmp(command, "exit") != 0)
    {
        // Call user prompt
        tokenCount = promptUser(tokens);

        // Seperate the command
        command = tokens[0];

        // Command list checking
        if (strcmp(command, "help") == 0)
        {
            printf("-----------------------------------------------------------------\n");
            printf("Here is the list of potential commands for this Shell\n\ncd - Changes the current working directory\npwd - Shows the current working directory\npid - Lists the PID of the last 5 programs created\n./[Program Name] - executes the program\nhelp - Lists all potential commands and there parameters\nexit - Exits the shell\n");
            printf("-----------------------------------------------------------------\n");
        }
        else if (strcmp(command, "cd") == 0)
        {
            if (chdir(tokens[1]) != 0)
            {
                printf("Error: Directory not found of does not exist\n");
            }
        }
        else if (strcmp(command, "pwd") == 0)
        {
            if (getcwd(curDir, sizeof(curDir)) == NULL)
            {
                printf("Error: Unable to get the current directory\n");
            }
            else
            {
                printf("%s\n", curDir);
            }
        }

        else if (strcmp(command, "pid") == 0)
        {
            for (i = 0; i < 5; i++)
            {
                if (pidArray[i] != 0)
                {
                    printf("%d\n", pidArray[i]);
                }
            }
        }
        else if (strcmp(command, "exit") == 0)
        {
            printf("exit\n");
            return 0;
        }
        else
        {
            int pid = fork();
            if (pid == 0)
            {
                int execRes = execvp(tokens[0], tokens);

                if (execRes < 0)
                {
                    printf("Error: Program doesn't exist or unable to execute.\n");
                }
            }
            else if (pid == -1)
            {
                printf("Error: Failed to create child when forked.");
            }
            else
            {

                if (k >= 5)
                {
                    k = 0;
                }
                switch (k)
                {
                case 0:
                    pidArray[0] = getpid();
                    printf("%d\n", pidArray[0]);
                    k++;
                    break;
                case 1:
                    pidArray[1] = getpid();
                    printf("%d\n", pidArray[1]);
                    k++;
                    break;
                case 2:
                    pidArray[2] = getpid();
                    printf("%d\n", pidArray[2]);
                    k++;
                    break;
                case 3:
                    pidArray[3] = getpid();
                    printf("%d\n", pidArray[3]);
                    k++;
                    break;
                case 4:
                    pidArray[4] = getpid();
                    printf("%d\n", pidArray[4]);
                    k++;
                    break;
                }
                wait(NULL);
            }
        }
    }
    return 0;
}

int promptUser(char *tokens[MAX_TOKENS])
{
    int i, tokenCount = 0;
    char delim[] = " ";
    char *username = getenv("USER");
    char curDir[72];

    // Revert array to NULL
    for (i = 0; i < MAX_TOKENS; i++)
    {
        tokens[i] = "\0";
    }
    // Allocate input buffer
    char *input = (char *)malloc(MAX_TOKENS * MAX_TOK_LGTH * sizeof(char));

    // Prompt User for input and get input
    if (getcwd(curDir, sizeof(curDir)) != NULL)
    {
        printf("%s@StudentShell:%s$ ", username, curDir);
    }
    else
    {
        printf("%s@StudentShell:unknown$ ", username);
    }

    // Take input from user and sanitize the newline character
    fgets(input, MAX_TOKENS * MAX_TOK_LGTH, stdin);
    char *sanitizedInput = strchr(input, '\n');
    *sanitizedInput = '\0';

    // Retrieve the command from the beginning of the input
    tokens[tokenCount] = strtok(input, delim);
    tokenCount++;
    while (tokens[tokenCount - 1] != NULL)
    {
        tokens[tokenCount] = strtok(NULL, delim);
        tokenCount++;
    };

    // Remove the null char from token count
    tokenCount--;

    // Verify valid token count
    if (tokenCount > 10)
    {
        for (i = 0; i < MAX_TOKENS; i++)
        {
            tokens[i] = "\0";
        }

        printf("Invalid command: Command must have less than 10 tokens\n");
        return 0;
    }

    // Return the count of tokens
    free(input);
    return tokenCount;
}
