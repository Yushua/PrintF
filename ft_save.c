/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_save.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:57:16 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/19 18:53:41 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_save_nb(t_print **print, int i, const char *format)
{
	int		e;
	char	*nb;
	int		j;
	int		b;

	e = (*print)->end;
	b = i;
	j = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		j++;
		i++;
	}
	nb = ((char *)malloc(sizeof(char) * (j + 1)));
	//protect
	j = 0;
	while (format[b] >= '0' && format[b] <= '9')
	{
		nb[j] = format[b];
		j++;
		b++;
	}
	(*print)->width_nb = ft_atoi(nb); //how big the string
	free(nb);
	return (i);
}

/*
**use ft_calloc for the malloc
**	//malloc is never only '\0'
*/
