/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 14:44:47 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 15:16:03 by ybakker       ########   odam.nl         */
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
	width = 0;
	if (str == NULL)
	{
		(*print)->flag_str = (*print)->flag_str_pre;
		str = (*print)->flag_str_pre;
		width = ft_strlen(str);
	}
	if (str_p == NULL)
		(*print)->flag_str = str;
	else if ((*print)->min == 1)
		(*print)->flag_str = ft_flag_min(print, width);
	else if ((*print)->min != 1)
		(*print)->flag_str = ft_flag_no(s, p, print, width);
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
	if (width == 0)
	{
		width = p;
		width--;
	}
	if (p == 0)
		return (str);
	while (s != 0 && str_p[width] != '\0')
	{
		str[s] = str_p[width];
		s -= 1;
		width -= 1;
	}
	return (str);
}
