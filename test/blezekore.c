#include "blezekshell.h"

/**
 * execute_shell_input - Executea shell command in a child process
 *
 * @shell_input: Path to the shell command to be executed
 * @args: Array of strings of the command and its arguments
 * Return: The exit status of the command
 * or -1, on failure
 *
 */

void execute_shell_input(const char *shell_input, char *const args[]) {
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Failed to create a child process (fork)");
		return (EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(shell_input, args, NULL) == -1)
		{
			perror("Failed to execute the shell_input (execve)");
			return (EXIT_FAILURE);
		}
	}
	int status;

	waitpid(child_pid, &status, 0);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {
	const char *shell_input = "/bin/ls";
	char *const args[] = {"/bin/ls", "-1", NULL};
	int exit_status = execute_shell_input(shell_input, args);

	if (exit_status != -1)
	{
		/* Handle the exit status as needed*/
	}
	return (0);
}
