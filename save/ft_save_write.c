/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 14:44:47 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 10:12:44 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_str(t_print **print)
{
	char	*str;
	char	*str_p;
	long	s;
	long	p;
	long	width;

	str = (*print)->flag_str;
	str_p = (*print)->flag_str_pre;
	s = ft_strlen(str);
	p = ft_strlen(str_p);
	width = (*print)->width_nb;
	if ((*print)->width_nb < -1)
		(*print)->width_nb = -1;
	if ((*print)->width_nb == -1)
		(*print)->input_str = NULL;
		printf("|%s.|\n", (*print)->input_str );
	else if (s == 0 && p == 0)
		(*print)->input_str = NULL;
	else if (s > p)
		(*print)->input_str = str;
	else
	{
		if ((*print)->min == 1)
			(*print)->flag_str = ft_flag_min(print, width);
		else if ((*print)->min != 1)
			(*print)->flag_str = ft_flag_no(s, p, print, width);
	}
}

char		*ft_flag_min(t_print **print, long width)
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
	while (s != 0)
	{
		str[p] = str_p[width];
		p -= 1;
		width -= 1;
	}
	return (str);
}
