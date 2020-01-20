/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 15:19:07 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/20 11:35:34 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_write_intt(t_print **print, int p, int w, int s)
{
	if ((*print)->neg < 0)
		ft_take_min(print);
	s = ft_strlen((*print)->input_str);
	if (p < s)
		p = s;
	ft_att_z(print, p, s);
	if ((*print)->neg != 0)
	{
		(*print)->flag_str = ft_strjoin("-", (*print)->input_str);
		free((*print)->input_str);
		(*print)->input_str = (*print)->flag_str;
	}
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
	free((*print)->flag_str);
}

static void		ft_write_inttt(t_print **print)
{
	free((*print)->input_str);
	(*print)->input_str = NULL;
}

void			ft_write_int(t_print **print)
{
	int		s;
	int		p;
	int		w;

	p = (*print)->p_width;
	s = ft_strlen((*print)->input_str);
	w = (*print)->w_width;
	if ((*print)->zero == 1 && w > 0 && (*print)->pre != 1 &&
		(*print)->neg != 0)
	{
		(*print)->input_str = ft_exemption1(print, w);
		free((*print)->flag_str);
	}
	else if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' &&
				p == 0 && w == 0)
		ft_write_inttt(print);
	else if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' &&
				p == -1 && w == 0 && (*print)->pre == 1)
	{
		free((*print)->input_str);
		(*print)->input_str = NULL;
	}
	else
		ft_write_intt(print, p, w, s);
}

char			*ft_int_no(long s, int w, t_print **print, long p)
{
	int		i;
	char	*str;

	i = 0;
	if ((*print)->zero == 1 && (*print)->pre != 1)
		(*print)->flag_str = ft_fill_z(w, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' &&
		(*print)->pre == 1)
	{
		free((*print)->input_str);
		return ((*print)->flag_str);
	}
	while (s != -1)
	{
		(*print)->flag_str[w] = (*print)->input_str[s];
		s--;
		w--;
	}
	free((*print)->input_str);
	return ((*print)->flag_str);
}

char			*ft_int_min(long s, int w, t_print **print)
{
	int		i;

	i = 0;
	if ((*print)->zero == 1)
		(*print)->flag_str = ft_fill_z(w, print);
	else
		(*print)->flag_str = ft_empty_int(w, s, print);
	if ((*print)->input_str[0] == '0' && (*print)->input_str[1] == '\0' &&
		(*print)->pre == 1)
		return ((*print)->flag_str);
	while (i != s && (*print)->input_str[i] != '\0' &&
			(*print)->flag_str[i] != '\0')
	{
		(*print)->flag_str[i] = (*print)->input_str[i];
		i++;
	}
	free((*print)->input_str);
	return ((*print)->flag_str);
}
