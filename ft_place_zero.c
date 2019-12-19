/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_place_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:29:29 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/17 15:32:10 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_find_nb_z(t_print **print, char *str, long nb)
{
	str = ((char *)malloc(sizeof(char) * ((*print)->width_nb + 1)));
	if (str == NULL)
		return ;
	nb = (*print)->width_nb;
	nb++;
	while (nb != 0)
	{
		str[nb] = '0';
		nb -= 1;
	}
	(*print)->flag_str = *str; //save the space
	free(str);
}
