/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/06 14:47:25 by ybakker       ########   odam.nl         */
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
		ft_print_u(print, ap, format);
	else if (c == 'p')
		ft_print_p(print, ap, format);
	else if (c == 'x' || c == 'X')
		ft_print_x(print, ap, i, format);
}

void	ft_print_c(t_print **print, va_list ap, int i, const char *format)
{
	char	c;
	int		len;

	len = (*print)->len;
	(*print)->input_str = NULL;
	c = (va_arg(ap, int));
	write(1, &c, 1);
	len++;
	(*print)->len = len;
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

void	ft_print_u(t_print **print, va_list ap, const char *format)
{
	unsigned int	i;

	i = (va_arg(ap, unsigned int));
	if (i < 0)
		i = 4294967196;
	(*print)->input_str  = ft_long_itoa(i);
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}
