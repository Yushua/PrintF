/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_place_zero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:29:29 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/21 19:16:01 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_find_nb_z(t_print **print, long nb)
{
	char			*str;

	nb = (*print)->width_nb;
	str = ((char *)malloc(nb * sizeof(char)));
	if (str == NULL)
		return ;
	while (nb)
	{
		nb -= 1;
		str[nb] = '0';
	}
	printf("%s", str);
	(*print)->flag_str = str;
}
