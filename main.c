#include "push_swap.h"

void    print_numbers(char *str)
{
    int i;

    i = 0;
    printf("Numbers found:\n");
    while (str[i])
    {
        // Skip spaces
        while (str[i] == ' ')
            i++;
        // If we're not at the end of string
        if (str[i])
        {
            // Print from current char until we hit a space or end
            printf("Sequence: ");
            while (str[i] && str[i] != ' ')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("\n");
        }
    }
}

int main(int ac, char **av)
{
    char    *joined_arguments;

    if (ac < 2 || !av)
        exit_error(NULL, NULL);
    
    if (ac == 2)
         joined_arguments = ft_strdup(av[1]);
    else
        joined_arguments = join_arguments(ac, av);
    if (!joined_arguments)
	    exit_error(NULL, NULL);
    print_numbers(joined_arguments);
    free(joined_arguments);
    return (0);
}
