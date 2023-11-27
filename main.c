#include "exeCommand.h"  // Assuming exeCommand.h contains the necessary declarations

#define BUFFER_SIZE 1024
#define WELCOME_MESSAGE "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define EXIT_MESSAGE "Bye bye ...\n"
#define PROMPT "enseash %"

int main() {
    char buffer[BUFFER_SIZE];
    write(1, WELCOME_MESSAGE, strlen(WELCOME_MESSAGE));

    while (1) {
        write(1, PROMPT, strlen(PROMPT));

        // Read user input into the buffer
        int command_size = read(0, buffer, BUFFER_SIZE);
        buffer[command_size - 1] = '\0';  // Null-terminate the string

        // Check if the user entered the "exit" command
        if (strcmp(buffer, "exit") == 0) {
            write(1, EXIT_MESSAGE, strlen(EXIT_MESSAGE));
            break;
        }

        // Execute the command using the exeCommand function
        int response = exeCommand(buffer, command_size);

        // Check the response from exeCommand
        if (response == -1) {
            write(1, "Commande introuvable.\n", strlen("Commande introuvable.\n"));
        }
    }

    return 0;
}


