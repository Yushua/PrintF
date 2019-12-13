/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 13:27:40 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 15:39:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print(t_print **print, va_list ap, int i, const char *format)
{
	i++; //next character after the frist %
	i = (*print)->begin;
	(*print)->convergions = ft_convergions(&print, i, format); //get the ending
	if ((*print)->convergions == '%')
	{
		write(1, &format[i], 1);
		return ;
	}
	ft_print_flag(&print, ap, i, format);
	//ft_print_str(&print, ap, i, format);
}

void		ft_print_f(t_print **print, va_list ap, int i, const char *format)
{
	ft_check_print(&print, ap, i, format);
}
