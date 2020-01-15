/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 20:41:12 by ybakker       ########   odam.nl         */
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
	{
		ft_write_pro(print);
		ft_write_string_1(print);		
	}
	else if (c == 's')
		ft_print_s(print, ap);
	else if (c == 'i' || c == 'd')
		ft_print_i(print, ap, i);
	else if (c == 'u')
		ft_print_u(print, ap);
	else if (c == 'p')
		ft_print_p(print, ap);
	else if (c == 'x' || c == 'X')
		ft_print_x(print, ap);
}

void	ft_print_c(t_print **print, va_list ap)
{
	char	c;
	int		w;
	int		i;

	i = (*print)->min;
	w = (*print)->w_width;
	c = (va_arg(ap, int));
	w--;
	if (i == 1)
	{
		write(1, &c, 1);
		(*print)->len++;
	}
	while (w > 0)
	{
		write(1, " ", 1);
		(*print)->len++;
		w--;
	}
	if (i == 0)
	{
		write(1, &c, 1);
		(*print)->len++;
	}
}

void	ft_print_s(t_print **print, va_list ap)
{
	(*print)->input_str = (va_arg(ap, char *));
	if ((*print)->input_str == NULL)
		(*print)->input_str = ft_fill_w_null(print);
	ft_write_str(print);
	ft_write_string_1(print);
}

void	ft_print_i(t_print **print, va_list ap, int i)
{
	i = (va_arg(ap, int));
	(*print)->input_str = ft_itoa(i);
	if (i < 0)
		(*print)->neg = i;
	ft_write_int(print);
	ft_write_string_1(print);
}

void	ft_print_u(t_print **print, va_list ap)
{
	long		i;

	i = (va_arg(ap, unsigned));
	(*print)->input_str = ft_long_itoa(i);
	if (i < 0)
		(*print)->neg = i;
	ft_write_int(print);
	ft_write_string_1(print);
}
