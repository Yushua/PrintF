/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 10:34:08 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_input(t_print **print, va_list ap, int i)
{
	char	c;

	c = (*print)->convergence;
	if (c == 'c')
		ft_print_c(print, ap);
	else if (c == '%')
		ft_print_cc(print, ap);
	else if (c == 's')
		ft_print_s(print, ap);
	else if (c == 'i' || c == 'd')
		ft_print_i(print, ap, i);
	else if (c == 'u')
		ft_print_u(print, ap);
	else if (c == 'p')
		ft_print_p(print, ap);
	else if (c == 'x' || c == 'X')
		ft_print_x(print, ap, i);
}

void	ft_print_c(t_print **print, va_list ap)
{
	char	c;

	(*print)->input_str = NULL;
	c = (va_arg(ap, int));
	write(1, &c, 1);
	(*print)->len++;
}

void	ft_print_cc(t_print **print, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = ((char *)malloc(1));
	str[i] = '%';
	(*print)->input_str = &str[i];
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_s(t_print **print, va_list ap)
{
	(*print)->input_str  = (va_arg(ap, char *));
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_i(t_print **print, va_list ap, int i)
{
	ft_flag_str(print);
	i = (va_arg(ap, int));
	(*print)->input_str  = ft_itoa(i);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_u(t_print **print, va_list ap)
{
	(*print)->input_str  = ft_long_itoa((va_arg(ap, unsigned)));
	ft_flag_str(print);
	ft_write_str(print);
	ft_write_string_1(print);
}
