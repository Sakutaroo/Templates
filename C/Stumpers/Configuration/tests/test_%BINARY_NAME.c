/*
** EPITECH PROJECT, %YEAR
** test_%BINARY_NAME
** File description:
** test_%BINARY_NAME
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macros.h"
#include "%BINARY_NAME.h"

void redirect_all_std(void)
{
\\x20\\x20\\x20\\x20cr_redirect_stdout();
\\x20\\x20\\x20\\x20cr_redirect_stderr();
}

Test(%BINARY_NAME, test_success)
{
\\x20\\x20\\x20\\x20char *av[] = {"./%BINARY_NAME", NULL};
\\x20\\x20\\x20\\x20int ac = 1;

\\x20\\x20\\x20\\x20cr_assert_eq(%BINARY_NAME(ac, av), SUCCESS);
}

Test(%BINARY_NAME, test_error)
{
\\x20\\x20\\x20\\x20char **av = NULL;
\\x20\\x20\\x20\\x20int ac = 0;

\\x20\\x20\\x20\\x20cr_assert_eq(%BINARY_NAME(ac, av), EPITECH_ERROR);
}
