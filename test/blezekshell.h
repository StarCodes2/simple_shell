#ifndef BLEZEKSHELL_H
#define BLEZEKSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


void read_shell_input(char *shell_input, size_t buffer_size);
void shell_prompt_display(void);
void blezek_print(const char *stdouttext);
void execute_shell_input(const char *shell_input, const char *path_dirs[]);
int confirm_command(const char *cmd, const char *path_dirs[]);

#endif
