#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdbool.h>

/* Global Variable */
extern char **environ;

/* Macro Definition */
#define BUFFER_SIZE 1024

/* REPL Function Prototypes */
int get_args(char *exe);
int exe_args(char *exe, int prompt_count, char *cmd, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int dup_args(char *line_buffer, char **line_buffer_dup);
int tok_args(char *line_buffer, char *line_buffer_dup,
int *arg_count, char ***arg_vector);
int check_get_args(char *line_buffer, size_t buffer_size);
int free_mem(char **arg_vector, char *line_buffer, char *line_buffer_dup);
int tok_path(char *exe, int prompt_count, char **command_path,
char **arg_vector, char *line_buffer, char *line_buffer_dup);
int process_args(char *exe, int prompt_count, int arg_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup, char *command_path);
int print_env(void);
void sigint_handler(int signum);
ssize_t refill_buffer(char *buffer, size_t *buffer_pos, size_t *buffer_size);
int read_buffer(char *buffer, size_t *buffer_pos, size_t buffer_size,
size_t *total_read, char **line_ptr, size_t *n);
void exit_shell(int prompt_count, char *exe, int arg_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup);
int is_all_white_space(const char *line_buffer);
int parent_wait(char **arg_vector, char *line_buffer, char *line_buffer_dup);
int path_err(char *exe, int prompt_count,
char **arg_vector, char *line_buffer, char *line_buffer_dup);
int exit_err(char *exe, int prompt_count, char **arg_vector,
char *line_buffer, char *line_buffer_dup);

/* Custom C Library Functions */
char *_getenv(const char *name);
ssize_t get_line(char **lineptr, size_t *n);

/* Custom String Manipulation Functions */
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
int _isspace(int character);
int _putchar(char c);
int _isdigit(int c);

/**
 * struct format_specifier - format specifier structure
 * For the printf function
 * @fmt_sign: fomat sign parameter
 * @fmt_func_ptr: format function parameter
 */

typedef struct format_specifier
{
	char fmt_sign;
	void (*fmt_func_ptr)(char, va_list, int *, char);
} fmt;

/* Custom printf function */
/* From our (0x11: C - printf) project */
/* Only change is in the stream of the write */
/* In the _putchar function, it writes to stderr */

int _printf(const char *format, ...);
int print_fmt(const char *format, va_list args,
int *count, int *num_args, fmt fmt_specs[], int fmt_len);
void char_print(char flag, va_list args, int *count, char space);
void string_print(char flag, va_list args, int *count, char space);
void int_print(char flag, va_list args, int *count, char space);
void dec_print(char flag, va_list args, int *count, char space);
void bin_print(char flag, va_list args, int *count, char space);
void uint_print(char flag, va_list args, int *count, char space);
void oct_print(char flag, va_list args, int *count, char space);
void hex_print(char flag, va_list args, int *count, char space);
void cap_hex_print(char flag, va_list args, int *count, char space);
void str_hex_print(char flag, va_list args, int *count, char space);
void ptr_print(char flag, va_list args, int *count, char space);
void zero(char *nil, int *count);
bool handle_fmt_spec(char fmt_char, va_list args,
int *count, int *num_args, fmt fmt_specs[], char *flag, char *space);

#endif /* MAIN_H */
