/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/02 16:10:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_input(t_print **print, va_list ap, int i, const char *format)
{
	char	c;

	c = (*print)->convergance;
	if (c == 'c')
		ft_save_c(print, ap, i, format);
	else if (c == 's')
		ft_print_s(print, ap, i, format);
}

void	ft_save_c(t_print **print, va_list ap, int i, const char *format)
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
	ft_write_str(print)
	ft_write_string_1(print);
}
