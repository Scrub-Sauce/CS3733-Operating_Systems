/*-----------------------------------*/
/* Author: Kyle Anderson             */
/* abc123: jvh640                    */
/* CS 3733 Operating Systems - Lab 2 */
/*-----------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 80
#define MAX_TOKENS 40

int promptUser(char* userInput);
int tokenizeInput(char* userInput, char* tokens[MAX_TOKENS]);
int letterCount(int* vowelCount, int* consCount, int* wordCount, char** tokens);

int main()
{
    char *userInput = (char *)malloc(MAX_LENGTH * sizeof(char));
    char **tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
    int i, vowelCount, consCount, wordCount;
    
    while(strcmp(userInput, "quit") != 0){
        // Reset count values
        vowelCount = 0;
        consCount = 0;
        wordCount = 0;

        // Promp user for input
        promptUser(userInput);

        // Check for quit input
       if(strcmp(userInput, "quit") == 0){
            printf("Exiting!\n");
            return 0;
        }

        // Tokenize the user input into an array of tokens and return the word count
        wordCount = tokenizeInput(userInput,tokens);
        
        // Count the letters in their categories
        letterCount(&vowelCount, &consCount, &wordCount, tokens);
        
        // Print the final tally
        printf("Number of vowels found: %d\nNumber of consonants found: %d\nNumber of words: %d\n", vowelCount, consCount, wordCount); 
    }
    return 1;
}

int promptUser(char* userInput)
{
    // Prompt user and take input from user
    printf("Please enter a string: ");
    fgets(userInput, MAX_LENGTH, stdin);

    // Sanitize the new line character from user input
    char *sanitizeChar = strchr(userInput, '\n');
    *sanitizeChar = '\0';
   
    return 0;
}

int tokenizeInput(char* userInput, char* tokens[MAX_TOKENS])
{
    int i = 0;
    
    // Break the user input into tokens
    tokens[0] = strtok(userInput, " ");
    i++;
    while(tokens[i-1] != NULL)
    {
        tokens[i] = strtok(NULL, " ");
        i++;
    }

    // Return word count
    return i-1;
}

int letterCount(int* vowelCount, int* consCount, int* wordCount, char** tokens)
{
    int i, j;

    // Loop through words
    for(i = 0; i < *wordCount; i++)
    {
        // Loop through characters in words
        for(j = 0; j < strlen(tokens[i]); j++)
        {
            // Count the letters in the words
            switch(tolower(tokens[i][j])){
                case 'a':
                    *vowelCount += 1;
                    break;
                case 'b':
                    *consCount += 1;
                    break;
                case 'c':
                    *consCount += 1;
                    break;
                case 'd':
                    *consCount += 1;
                    break;
                case 'e':
                    *vowelCount += 1;
                    break;
                case 'f':
                    *consCount += 1;
                    break;
                case 'g':
                    *consCount += 1;
                    break;
                case 'h':
                    *consCount += 1;
                    break;
                case 'i':
                    *vowelCount += 1;
                    break;
                case 'j':
                    *consCount += 1;
                    break;
                case 'k':
                    *consCount += 1;
                    break;
                case 'l':
                    *consCount += 1;
                    break;
                case 'm':
                    *consCount += 1;
                    break;
                case 'n':
                    *consCount += 1;
                    break;
                case 'o':
                    *vowelCount += 1;
                    break;
                case 'p':
                    *consCount += 1;
                    break;
                case 'q':
                    *consCount += 1;
                    break;
                case 'r':
                    *consCount += 1;
                    break;
                case 's':
                    *consCount += 1;
                    break;
                case 't':
                    *consCount += 1;
                    break;
                case 'u':
                    *vowelCount += 1;
                    break;
                case 'v':
                    *consCount += 1;
                    break;
                case 'w':
                    *consCount += 1;
                    break;
                case 'x':
                    *consCount += 1;
                    break;
                case 'y':
                    *consCount += 1;
                    break;
                case 'z':
                    *consCount += 1;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
