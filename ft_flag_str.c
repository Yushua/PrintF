/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_flag_str.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 17:07:56 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/16 18:01:55 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_flag_min(long s, long p)
{
	char    *str;
	char    *str_p;
	long	i;

	str = 	(*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	i = 	0;

	while (i != s)
	{
		str[i] = str_p[i]
		i++;
	}
	return (str);
}

char		ft_flag_no(long s, long p)
{
	char    *str;
	char    *str_p;

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;

	while (s != 0)
	{
		str[p] = str_p[s];
		p -= 1;
		s -= 1;
	}
	return (str);
}

void		ft_flag_str(t_print **print, va_list ap, int i, const char *format)
{
	char    *str;
	char    *str_p;
	long	s; //len str
	long	p; //len str_p

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	s = ft_strlen(str); //first, place where it begins
	p = ft_strlen(str_p); //second
	width_nb = p; //lenght of width
	if (s >= p)
	{
		if ((*print)->min == 1)
			(*print)->flag_str = ft_flag_min(s);
		else //else min != 1;
			(*print)->flag_str = ft_flag_no(s, p);
	}
	else if (p > s)
		(*print)->flag_str = str_p;
	(*print)->flag_str_pre = '\0';
}
