#ifndef FUNCTION_POINTER_H_
    #define FUNCTION_POINTER_H_

typedef struct command_s {
    char *command;
    int (*fptr)(int);
} command_t;

const command_t *find_command(char *your_var);

#endif /* !FUNCTION_POINTER_H_ */
