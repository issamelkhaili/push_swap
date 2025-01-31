#include "push_swap.h"

int     is_space(char *str)
{
        write(1, "Line 1: Entering is_space\n", 26);
        if (!str || !*str)
                return (1);
        while (*str && *str == ' ')
                str++;
        write(1, "Line 2: Exiting is_space\n", 25);
        return (*str == '\0');
}

static void     free_split(char **split)
{
        int     i;
        
        write(1, "Line 3: Entering free_split\n", 28);
        if (!split)
                return ;
        i = 0;
        write(1, "Line 4: Starting split freeing loop\n", 35);
        while (split[i])
                free(split[i++]);
        write(1, "Line 5: Freeing split array itself\n", 35);
        free(split);
        write(1, "Line 6: Finished free_split\n", 28);
}

static int      handle_error(char **split)
{
        write(1, "Line 7: Entering handle_error\n", 30);
        free_split(split);
        write(2, "Error\n", 6);
        return (1);
}

int     main(int ac, char **av)
{
        t_stacks        *stacks;
        char            **split;
        int             i;
        int             num;

        write(1, "Line 8: Starting main\n", 22);
        if (ac < 2 || !av[1] || is_space(av[1]))
        {
                write(1, "Line 9: Initial argument check failed\n", 37);
                return (handle_error(NULL));
        }
        
        write(1, "Line 10: Checking for space-only arguments\n", 42);
        i = 1;
        while (i < ac)
                if (is_space(av[i++]))
                {
                        write(1, "Line 11: Found space-only argument\n", 35);
                        return (handle_error(NULL));
                }
        
        write(1, "Line 12: Calling split_input\n", 29);
        split = split_input(ac, av, NULL);
        if (!split)
        {
                write(1, "Line 13: split_input failed\n", 28);
                return (1);
        }
        
        write(1, "Line 14: Checking integer validity\n", 34);
        i = 0;
        while (split[i])
        {
                write(1, "Line 15: Checking number: ", 25);
                write(1, split[i], ft_strlen(split[i]));
                write(1, "\n", 1);
                if (!is_valid_integer(split[i], &num))
                {
                        write(1, "Line 16: Invalid integer found\n", 31);
                        return (handle_error(split));
                }
                i++;
        }
        
        write(1, "Line 17: Parsing numbers\n", 25);
        stacks = parse_numbers(split, i);
        write(1, "Line 18: Freeing split array\n", 29);
        free_split(split);
        
        if (!stacks)
        {
                write(1, "Line 19: parse_numbers failed\n", 30);
                return (1);
        }
        
        write(1, "Line 20: Printing numbers\n", 26);
        i = 0;
        while (i < stacks->size_a)
                printf("%d ", stacks->a[i++]);
        printf("\n");
        
        write(1, "Line 21: Freeing stacks\n", 24);
        free_stacks(stacks);
        write(1, "Line 22: Program ending\n", 24);
        return (0);
}
