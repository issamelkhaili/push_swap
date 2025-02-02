#include "push_swap.h"

int    check_input(int ac, char **av)
{
        int    i;

        i = 1;
        while (i < ac)
        {
                if (!is_valid_argument(av[i]))
                        return (0);
                i++;
        }
        return (1);
}

int    is_valid_argument(char *str)
{
        int    i;

        i = 0;
        if (!str || !str[0])
                return (0);
        while (str[i] && str[i] == ' ')
                i++;
        if (!str[i])
                return (0);
        while (str[i])
        {
                if (str[i] == '-' || str[i] == '+')
                {
                        if (!ft_isdigit(str[i + 1]))
                                return (0);
                        if (i > 0 && str[i - 1] != ' ')
                                return (0);
                        i++;
                }
                while (str[i] && ft_isdigit(str[i]))
                        i++;
                while (str[i] && str[i] == ' ')
                        i++;
                if (str[i] && !ft_isdigit(str[i]) && 
                    str[i] != '-' && str[i] != '+')
                        return (0);
        }
        return (1);
}
