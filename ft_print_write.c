/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_write.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 16:09:06 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_string_1(t_print **print)
{
	char	*str;
	long	i;

	i = 0;
	str = (*print)->input_str;
	while (str != NULL && str[i] != '\0')
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

	if ((*print)->error == -1)
		(*print)->input_str = (*print)->flag_str;
	str_f = (*print)->flag_str;
	str = (*print)->input_str;
	s = ft_strlen(str);
	f = ft_strlen(str_f);
	if (f == 0)
	{
		f = s;
		(*print)->flag_str = (*print)->input_str;
	}
	f--;
	if ((*print)->min == 1)
		(*print)->input_str = ft_str_min(s, f, print, width);
	else if ((*print)->min != 1)
		(*print)->input_str = ft_str_no(s, f, print, width);
}

char		*ft_str_min(long s, long f, t_print **print, long width)
{
	char	*str;
	char	*str_f;
	long	ff;
	int		i;

	i = 0;
	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	if (f <= 0 || f < s)
		return (str);
	else
	{
		while (str_f[i] != '\0' && str[i] != '\0')
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
	long	ff;
	int		i;

	i = 0;
	str = (*print)->input_str;
	str_f = (*print)->flag_str;
	if (f < s && (*print)->p_width < 0)
		return (str);
	if (f <= 0 || (*print)->p_width > s)
		return (str);
	else
	{
		if ((*print)->p_width < s && (*print)->p_width > 0)
			ft_special_case_width(print, f, str, str_f);
		else
		{
			ff = f - s;
			while (str_f[ff] != '\0' && str[i] != '\0' && ff != f && i <= s)
			{
				ff++;
				str_f[ff] = str[i];
				i++;
			}
		}
		return (str_f);
	}
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

char	*ft_special_case_width(t_print **print, long f, char *str, char *str_f)
{
	int		i;
	int		ff;
	int		s;

	i = 0;
	s = (*print)->p_width;
	s--;
	ff = f - s;
	s++;
	while (i != s)
	{
		str_f[ff] = str[i];
		i++;
		ff++;
	}
	return (str_f);
}
