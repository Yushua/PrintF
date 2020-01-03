/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/03 16:59:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_input(t_print **print, va_list ap, int i, const char *format)
{
	char	c;

	c = (*print)->convergence;
	if (c == 'c')
		ft_print_c(print, ap, i, format);
	else if (c == 's')
		ft_print_s(print, ap, i, format);
	else if (c == 'i' || c == 'd')
		ft_print_i(print, ap, i, format);
	else if (c == 'u')
		ft_print_u(print, ap, i, format);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_print_x(print, ap, i, format);
}

void	ft_print_c(t_print **print, va_list ap, int i, const char *format)
{
	char		c;

	(*print)->input_str = NULL;
	c = (va_arg(ap, int));
	write(1, &c, 1);
}

void	ft_print_s(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->input_str  = (va_arg(ap, char *));
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_i(t_print **print, va_list ap, int i, const char *format)
{
	i = (va_arg(ap, int));
	(*print)->input_str  = ft_itoa(i);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_u(t_print **print, va_list ap, int i, const char *format)
{
	i = (va_arg(ap, unsigned int));
	(*print)->input_str  = ft_itoa(i);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_x(t_print **print, va_list ap, int i, const char *format)
{
	int		j;

	j = 0;
	if ((*print)->convergence == 'p')
		j = 2;
	i = (va_arg(ap, int));
	(*print)->input_str  = ft_hex(i, j, print);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}
