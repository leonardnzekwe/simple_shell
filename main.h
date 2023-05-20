#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global Variable */
extern char **environ;

/* REPL Function Prototypes */
int get_args(char *exe);
int exe_args(char *exe, char *cmd, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int dup_args(char *line_buffer, char **line_buffer_dup);
int tok_args(char *line_buffer, char *line_buffer_dup,
int *arg_count, char ***arg_vector);
int check_get_args(char *line_buffer);
char *_getenv(const char *name);
int free_mem(char **arg_vector, char *line_buffer, char *line_buffer_dup);
int tok_path(char **command_path, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int process_args(char *exe, int arg_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup, char *command_path);
int print_env(void);

/* String Manipulation Functions */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strchr(const char *str, int c);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);

#endif /* MAIN_H */
