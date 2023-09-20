#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char **line_to_av(char *s, char *deli);
int word_count(char *s, char *deli);
int compare_cs(char c, char *s);
void new_process(pid_t *);
char *_getenv(const char *name);
void exec_cmd(char **arr, char **env, char *cmd);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void print(char *);
int _putchar(char c);
void print_num(int num);
void print_err(char *p_name, char *cmd, char *msg);
int print_env(void);
void print_buf(char *buffer, int *index);
char **path_handler(char **arr);
void _free(void *);
void interactive_mode(char **argv, char **env);
void non_interactive_mode(char **, char **);
int cmd_check(char *cmd, char **arr);
char *path_cat(char *dest, char *path, char *file);

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

#define BUFFER_SIZE 1024

#endif
