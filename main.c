#include "push_swap.h"

void    check_numbers(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i])
        {
            while (str[i] && str[i] != ' ')
            {
                write(1, &str[i], 1);
                i++;
            }
            printf("\n");
        }
    }
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
	print_numbers(joined_arguments);
    free(joined_arguments);
	return (0);
}
