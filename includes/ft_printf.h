/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:09:38 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 14:32:10 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// includes/ft_printf.h
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

// Printf function declarations
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_printptr(void *ptr);
int	ft_print_x(unsigned int num, char format);

#endif
