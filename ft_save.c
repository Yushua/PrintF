/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:57:16 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 17:40:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        ft_save_n(t_print **print, int i)
{
	int     e;
	char    nb;
	int		j;
	int		b;

	e = (*print)->end;
	b = i;
	while (format[i] => '0' || format[i] =< '9' format || i < e)
		j++;
	nb = ((char *)malloc(sizeof(char) * (j + 1)));
	//malloc is never only '\0'
	j = 0;
	while (format[i] => '0' || format[i] =< '9' format || b < e)
	{
		nb[j] = format[b];
		j++
		b++;
	}
	j = ft_atoi(nb);
	free(nb);
	return (j);
}