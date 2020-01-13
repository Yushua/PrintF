/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/13 17:39:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_int(t_print **print)
{
	int		s;
	int 	p;
	int		w;

	p = (*print)->p_width;
	s = ft_strlen((*print)->input_str);
	if ((*print)->neg < 0)
		ft_take_min(print);
	s = ft_strlen((*print)->input_str);
	if (p < s)
		p = s;
	ft_att_z(print, p, s);
	if ((*print)->neg < 0)
		(*print)->input_str = ft_strjoin("-", (*print)->input_str);
	s = ft_strlen((*print)->input_str);
	w = (*print)->w_width;
	if (w < s || w == 0)
		w = s;
	if (s == 0)
		(*print)->input_str = NULL;
	if ((*print)->min == 1)
		(*print)->input_str = ft_int_min(s, w, print);
	else if ((*print)->min != 1)
		(*print)->input_str = ft_int_no(s, w, print, p);
}

char		*ft_int_no(long s, int w, t_print **print, long p)
{
	int		i;
	char	*str;

	i = 0;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w, s, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	while (s != -1)
	{
		(*print)->flag_str[w] = (*print)->input_str[s];
		s--;
		w--;
	}
	return ((*print)->flag_str);
}

char		*ft_int_min(long s, int w, t_print **print)
{
	int		i;

	i = 0;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w, s, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	while (i != s && (*print)->input_str[i] != '\0' && (*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[i] = (*print)->input_str[i];
		i++;
	}
	return ((*print)->flag_str);
}

void		ft_att_z(t_print **print, int p, int s) // uses precision and add str on it, then places min at the end if needed
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(p + 1);
	str[p] = '\0';
	p--;
	i = p;
	while (i != 0)
	{
		str[i] = '0';
		i--;
	}
	i = 0;
	p = p - s;
	while ((*print)->input_str[i] != '\0')
	{
		str[p] = (*print)->input_str[i];
		i++;
		p++;
	}
	(*print)->flag_str = str;
}

char		*ft_empty_int(long w, long s, t_print **print)
{
	char	*str;
	int		i;
	int		l;

	str = (char *)malloc(w + 1);
	if (str == NULL)
		return (NULL);
	str[w] = '\0';
	i = 0;
	while (i != w)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}

char		*ft_fill_z(long w, long s, t_print **print)
{
	char	*str;
	int		i;

	str = (char *)malloc(w + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (i != w)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

//min is taken away, make sure that the - is placed maybe combine the two, or something else simpler
//negative stil has some issues, work on that