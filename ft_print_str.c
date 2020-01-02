/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/02 16:50:03 by ybakker       ########   odam.nl         */
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
	else if (c == 'p')
		ft_print_p(print, ap, i, format);
	else if (c == 'u')
		ft_print_u(print, ap, i, format);
	else if (c == 'x' || c == 'X')
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
	char		*str;

	str = (va_arg(ap, char *));
	(*print)->input_str = str;
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_i(t_print **print, va_list ap, int i, const char *format)
{
	char		*str;
	int			i;

	i = (va_arg(ap, int));
	str = ft_itoa(i);
	(*print)->input_str = str;
	ft_flag_str(print);
	ft_write_str(print)
	ft_write_string_1(print);
}

void	ft_print_p(t_print **print, va_list ap, int i, const char *format)
{
	
}

void	ft_print_u(t_print **print, va_list ap, int i, const char *format)
{
	
}

void	ft_print_x(t_print **print, va_list ap, int i, const char *format)
{
	//check both x and X
}
