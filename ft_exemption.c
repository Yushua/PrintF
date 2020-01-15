/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exemption.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 20:34:11 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/15 20:39:12 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_exemption1(t_print **print, int w)
{
	int		s;

	w--;
	s = ft_strlen((*print)->input_str);
	if (w < s || w == 0)
	{
		w = s;
		w--;
	}
	(*print)->flag_str = ft_fill_z(w, print);
	while (s != 0)
	{
		(*print)->flag_str[w] = (*print)->input_str[s];
		w--;
		s--;
	}
	(*print)->flag_str = ft_strjoin("-", (*print)->flag_str);
	return ((*print)->flag_str);
}
