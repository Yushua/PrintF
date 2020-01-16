/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 21:51:18 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/16 22:30:43 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_hex(t_print **print)
{
	int		s;
	int		p;
	int		w;

	p = (*print)->p_width;
	s = ft_strlen((*print)->input_str);
	w = (*print)->w_width;
	if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' && p == 0 && w == 0)
		(*print)->input_str = NULL;
	else if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' && p == -1 && w == 0 && (*print)->pre == 1)
		(*print)->input_str = NULL;
	else
	{
		if (p < s)
			p = s;
		ft_att_z(print, p, s);
		if (s < p)
			s = p;
		if (w < s || w == 0)
			w = s;
		if (s == 0)
			(*print)->input_str = NULL;
		if ((*print)->min == 1)
			(*print)->input_str = ft_hex_min(s, w, print);
		else if ((*print)->min != 1)
			(*print)->input_str = ft_hex_no(s, w, print, p);
		free((*print)->flag_str);
	}
}

char		*ft_hex_no(long s, int w, t_print **print, long p)
{
	int		i;
	char	*str;

	i = 0;
	if ((*print)->zero == 1 && (*print)->pre != 1)
		(*print)->flag_str = ft_fill_z(w, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' && (*print)->pre == 1)
		return ((*print)->flag_str);
	while (s != -1)
	{
		(*print)->flag_str[w] = (*print)->input_str[s];
		s--;
		w--;
	}
	free((*print)->input_str);
	return ((*print)->flag_str);
}

char		*ft_hex_min(long s, int w, t_print **print)
{
	int		i;

	i = 0;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' && (*print)->pre == 1)
		return ((*print)->flag_str);
	while (i != s && (*print)->input_str[i] != '\0' && (*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[i] = (*print)->input_str[i];
		i++;
	}
	free((*print)->input_str);
	return ((*print)->flag_str);
}
