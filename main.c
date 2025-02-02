#include "push_swap.h"

int check_numbers(char *joined_arguments)
{
    int     i;

    i = 0;
    while (joined_arguments[i])
    {
        while (joined_arguments[i] == ' ')
            i++;
        if (joined_arguments[i])
        {
            if (ft_atol(joined_arguments + i) == 0)
                return (0);
            while (joined_arguments[i] && joined_arguments[i] != ' ')
                i++;
        }
    }
    return (1);
}

int main(int ac, char **av)
{
    char    *joined_arguments;
    int     i;
    char    **split;

    if (!av || check_input(ac, av) == 0)
        exit_error(NULL, NULL);
    
    if (ac == 2)
    {
        joined_arguments = ft_strdup(av[1]);
        if (!joined_arguments)
            exit_error(NULL, NULL);
    }
    else
    {
        joined_arguments = join_arguments(ac, av);
        if (!joined_arguments)
            exit_error(NULL, NULL);
    }
	if (check_numbers(joined_arguments) == 0)
		error_free(joined_arguments);
	write (1, "good", 4);
    free(joined_arguments);
	return (0);
}
