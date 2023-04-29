#include <string.h>
#include <stdio.h>
#include "function_pointer.h"

int your_function(int nb)
{
    printf("number = %d\n", nb);
    return nb;
}

static const command_t command_map[] = {
    {.command = "test", .fptr = your_function}, // Add items if needed
    {.command = NULL, .fptr = NULL}
};

const command_t *find_command(char *your_var)
{
    if (your_var == NULL)
        return NULL;
    // The loop traverses the map to find the function to call
    for (int index = 0; command_map[index].fptr != NULL; index += 1) {
        if (strcmp(your_var, command_map[index].command) == 0) {
            return &command_map[index];
        }
    }
    return NULL;
}
