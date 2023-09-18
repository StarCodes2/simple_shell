#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char **line_to_av(char *s, char *deli);
int word_count(char *s, char *deli);
int compare_cs(char c, char *s);
void new_process(pid_t *);
char *_getenv(const char *name);
void exec_cmd(char **arr, char **env);

/**
 * struct path_list - Singly linked list for the directories in PATH
 * @path: points to a string path of a directory
 * @next: points to the next node in the list
 */

typedef struct path_list
{
	char *path;
	struct path_list *next;
} p_list;
extern char **environ;

p_list *c_path_list(char *path);

#endif
