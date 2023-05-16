#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prototypes */
int get_args(char *cmd);
int exe_args(char *cmd, char **arg_vector, int arg_count);
int cpy_args(char *line_buffer, char **line_buffer_cpy);
int tok_args(char *cmd, char *line_buffer, char *line_buffer_cpy,
int *arg_count, char ***arg_vector);

#endif /* MAIN_H */
