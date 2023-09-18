#include "blezekshell.h"

/**
 * confirm_command - confirms if path directories exist before execution
 * @cmd: Command to be confirmed
 * @path-dirs: Array of directory paths in the PATH
 *
 * Return: 1 if the command exists, 0 otherwise
 */
int confirm_command(const char *cmd, const char *path_dirs[])
{
	int i = 0;
	while (path_dirs[i] != NULL)
	{
		char full_path[256];
		snprintf(full_path, sizeof(full_path), "%s/%s", path_dirs[i], cmd);

		if (access(full_path, X_OK) == 0)
		{
			return 1;
		}
		i++;
	}
	return 0;
}

/**
 * execute_shell_input - function that executes user input
 *
 * @shell_input: User input string
 * @path_dirs: Array of directories in the PATH
 */
void execute_shell_input(const char *shell_input, const char *path_dirs[])
{
	char *token;
	char *args[64];
	int arg_count = 0;

	token = strtok((char*)shell_input, " ");
	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	if (arg_count > 0)
	{
		int i = 0;
		while (path_dirs[i] != NULL)
		{
			char full_path[256];
			snprintf(full_path, sizeof(full_path), "%s/%s", path_dirs[i], args[0]);

			if (access(full_path, X_OK) == 0)
			{
				pid_t child_pid = fork();

				if (child_pid == -1)
				{
					blezek_print("Error forking process\n");
					return;
				}

				if (child_pid == 0)
				{
					execve(full_path, args, NULL);
					blezek_print("Error executing the command\n");
					_exit(EXIT_FAILURE);
				}
				else
				{
					int status;
					waitpid(child_pid, &status, 0);
				}
				return;
			}
			i++;
		}

		blezek_print("Command not found\n");
	}
}
