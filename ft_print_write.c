/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_write.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/08 22:58:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_string_1(t_print **print)
{
	char	*str;
	long	i;

	i = 0;
	str = (*print)->input_str;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
		(*print)->len++;
	}
}

void		ft_write_str(t_print **print)
{
	char	*str;
	char	*str_f;
	long	s;
	long	f;
	long	width;

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	s = ft_strlen(str);
	f = ft_strlen(str_f);
	f--;
	width = (*print)->width_nb;
	if ((*print)->width_nb < -1)
		(*print)->width_nb = -1;
	if ((*print)->width_nb == -1)
		(*print)->input_str = NULL;
	else if (s <= f)
	{
		if ((*print)->min == 1)
			(*print)->input_str = ft_str_min(s, print, width);
		else if ((*print)->min != 1)
			(*print)->input_str = ft_str_no(s, f, print, width);
	}
	else if (f < s)
		(*print)->input_str = str;
}

char		*ft_str_min(long s, t_print **print, long width)
{
	char	*str;
	char	*str_f;
	long	i;

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	i = 0;
	if (width == 0)
		width = s;
	if ((*print)->convergence == '%')
		str_f[i] = '%';
	else
	{
		while (i != width)
		{
			str_f[i] = str[i];
			i++;
		}
	}
	return (str_f);
}

char		*ft_str_no(long s, long f, t_print **print, long width)
{
	char	*str;
	char	*str_f;

	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	if (width == 0)
		width = s;
	if ((*print)->convergence == '%')
		str_f[f] = '%';
	else
	{
		while (width >= 0 && str_f != '\0')
		{
			str_f[f] = str[width];
			f -= 1;
			width -= 1;
			s -= 1;
		}
	}
	return (str_f);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i += 1;
	return (i);
}
