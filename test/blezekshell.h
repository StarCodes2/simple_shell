#ifndef BLEZEKSHELL_H
#define BLEZEKSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


void read_user_input(char *user_input, size_t buffer_size);
void shell_prompt_display(void);
void blezek_print(const char *StdoutText);
void execute_shell_input(const char *shell_input, char *const args[]);
const char *shell_input = "/bin/ls";
int main(void)

#endif
