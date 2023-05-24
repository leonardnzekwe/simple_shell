#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global Variable */
extern char **environ;

/* Macro Definition */
#define BUFFER_SIZE 1024

/* REPL Function Prototypes */
int get_args(char *exe);
int exe_args(char *exe, char *cmd, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int dup_args(char *line_buffer, char **line_buffer_dup);
int tok_args(char *line_buffer, char *line_buffer_dup,
int *arg_count, char ***arg_vector);
int check_get_args(char *line_buffer, size_t buffer_size);
char *_getenv(const char *name);
int free_mem(char **arg_vector, char *line_buffer, char *line_buffer_dup);
int tok_path(char **command_path, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int process_args(char *exe, int arg_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup, char *command_path);
int print_env(void);
void sigint_handler(int signum);
ssize_t get_line(char **lineptr, size_t *n);
ssize_t refill_buffer(char *buffer, size_t *buffer_pos, size_t *buffer_size);
int read_buffer(char *buffer, size_t *buffer_pos, size_t buffer_size,
size_t *total_read, char **line_ptr, size_t *n);
void exit_shell(int arg_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup);

/* String Manipulation Functions */
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strchr(const char *str, int c);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);
void *_memcpy(void *destination, const void *source, size_t num);
char *_strtok(char *str, const char *delimiters);
int _atoi(const char *str);

#endif /* MAIN_H */
