/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:57:16 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/14 13:47:51 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_save_nb(const char *format, t_print **print, int i)
{
	int		e;
	char	*nb;
	int		j;
	int		b;

	e = (*print)->end;
	b = i;
	while ((format[i] >= '0') || (format[i] <= '9') || i < e)
	{
		j++;
		i++;
	}
	nb = ((char *)malloc(sizeof(char) * (j + 1)));
	j = 0;
	while ((format[b] >= '0') || (format[b] <= '9') || b < e)
	{
		nb[j] = format[b];
		j++;
		b++;
	}
	(*print)->width_nb = ft_atoi(nb);
	free(nb);
	return (i);
}

/*
**use ft_calloc for the malloc
**	//malloc is never only '\0'
*/
