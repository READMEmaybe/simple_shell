#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PROMPT "$ "
#define DELIMITERS " \t\n\v\f\r"
#define NEWLINE "\n"
#define BUFFER_SIZE 1024

extern char **environ;

/**
 * struct builtin_t - Struct for builtins
 * @name: Name of builtin
 * @func: Function pointer to builtin
 */
typedef struct builtin_t
{
	char *name;
	void (*func)(char **args);
} builtin_t;


/* main.c*/
int file_mode(char *argv[]);
int non_interactive_mode(char *argv[]);
int interactive_mode(char *p_name);

/* parse.c */
size_t parse(char ***args, char *line, size_t size, const char *delims);

/* helpers.c */
void free_mem(char **args, char *expression, char *command);
void free_vec(char **vec);
int remove_comment(char *str);
int handle_eof_empty(char *line, ssize_t size);


/* execute.c */
int execute(char *p_name, char **args, char *expression);
int execute_command(char *command, char **args);
char *get_command(char *arg);

/* path_utils.c */
char *_getenv(const char *name);
char *get_stat(char *filename);
char *append_slash(char *filename);
char *get_file_path(char *directory, char *filename);

/* get_input.c */
ssize_t _getline(char **lineptr, size_t *n, int fd);
ssize_t get_input(char **line, int fd);

/* utils.c*/
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(char *s1, char *s2, size_t bytes);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, char *src, int n);

/* utils2.c */
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strpbrk(const char *s, const char *accept);
char *_strchr(const char *s, int c);
char *_strtok(char *str, const char *delim);

/* utils3.c */
char *_strstr(char *haystack, char *needle);
int _isspace(char c);
int _atoi(char *s);
void _memcpy(char *dest, char *src, unsigned int bytes);
void *_realloc(void *ptr, size_t size);

/* builtins.c */
int execute_builtin(char **args);
void handle_exit(char **args);
void handle_env(char **args);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
void handle_cd(char **args);
void set_args(char *oldpwd, char *newpwd);


#endif
