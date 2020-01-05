/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 14:44:47 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/05 15:47:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_str(t_print **print)
{
	char	*str;
	char	*str_p;
	long	s; //len str
	long	p; //len str_p
	long	width; //width to print

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	s = ft_strlen(str); //first, place where it begins
	p = ft_strlen(str_p); //second
	width = (*print)->width_nb;
	if ((*print)->width_nb < -1)
		(*print)->width_nb = -1;
	if ((*print)->width_nb == -1)
		(*print)->input_str = (*print)->flag_str;
	else if (s == 0 && p == 0)
		(*print)->flag_str = NULL;
	else if (s >= p)
	{
		if ((*print)->min == 1)
			(*print)->flag_str = ft_flag_min(s, print, width);
		else if ((*print)->min != 1)
			(*print)->flag_str = ft_flag_no(s, p, print, width);
	}
	else if (p > s)
		(*print)->flag_str = str_p;//now pointer flag string is it.
	(*print)->flag_str_pre = NULL;
}

char		*ft_flag_min(long s, t_print **print, long width)
{
	char	*str;
	char	*str_p;
	long	i;

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	i = 0;
	while (i != width)
	{
		str[i] = str_p[i];
		i++;
	}
	return (str);
}

char		*ft_flag_no(long s, long p, t_print **print, long width)
{
	char	*str;
	char	*str_p;

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	if (p == 0)
		return (str);
	while (s != 0) //take a look at this
	{
		str[p] = str_p[width];
		p -= 1;
		width -= 1;
	}
	return (str);
}
