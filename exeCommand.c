#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Function to execute a command using fork and execlp
// Parameters:
//   - command: The command to be executed
//   - command_size: Size of the command string
// Returns:
//   - 0 on success, -1 on failure
int exeCommand(char *command, ssize_t command_size) {
    // Fork the process to create a child process
    int pid = fork();
    int status;

    if (pid == 0) {
        // Child process
        // Execute the command using execlp
        execlp(command, command, NULL);

        // If execlp fails, exit the child process with failure status
        exit(EXIT_FAILURE);

    } else {
        // Parent process
        // Wait for the child process to complete
        wait(&status);

        // Check if the child process exited normally
        if (WIFEXITED(status)) {
            // Return the exit status of the child process
            return WEXITSTATUS(status);
        } else {
            // Return -1 to indicate failure (child process did not exit normally)
            return -1;
        }
    }
}
