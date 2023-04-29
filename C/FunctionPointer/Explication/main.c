#include <stdio.h>
#include "function_pointer.h"

int main(void)
{
    const command_t *com = NULL;
    char str_working[5] = {'t', 'e', 's', 't', '\0'}; // Working example
    char str_non_working[2] = {'r', '\0'}; // Non-working example
    int nb = 5;

    com = find_command(str_working); // Search the function
    if (com == NULL)
        return 84;
    com->fptr(nb); // Function call
    com = NULL;
    com = find_command(str_non_working); // Search the function
    if (com == NULL)
        printf("Error: command not found (but it's normal here...)\n");
    return 0;
}
