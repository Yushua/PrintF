/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_place_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:29:29 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/19 22:34:52 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_find_nb_z(t_print **print, long nb)
{
	char	*str;
	char	c;

	c = '0';
	nb = (*print)->width_nb;
	str = ((char *)malloc(sizeof(nb + 1)));
	if (str == NULL)
		return ;
	while (nb)
	{
		*str = (unsigned char)c;
		str++;
		nb -= 1;
	}
	*(*print)->flag_str = *str;
	free(str);
}
