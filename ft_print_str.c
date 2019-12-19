/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:38:38 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/19 20:04:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_save_c(t_print **print, va_list ap, int i, const char *format)
{
	char		c;

	(*print)->input_str = '\0';
//	(*print)->input_str = 
	c = (va_arg(ap, int));
	write(1, &c, 1);
//	(*print)->input_str;
	printf("hello");
}

void		ft_print_s(t_print **print, va_list ap, int i, const char *format)
{
	(*print)->input_str = '\0';
	(*print)->input_str = (va_arg(ap, unsigned int));
}

void		ft_save_input(t_print **print, va_list ap, int i, const char *format)
{
	char	c;

	c = (*print)->input_str;

	c = (*print)->convergance;
	if (c == 'c')
		ft_save_c(print, ap, i, format);
	else if (c == 's')
		ft_print_s(print, ap, i, format);
}

//(*print)->input_str;
//(*print)->width_nb
//(*print)->width