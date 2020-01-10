/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utills.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 15:01:08 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/10 15:04:25 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_find_nb_z(t_print **print)
{
	char	*str;
	int		nb;

	nb = (*print)->width_nb;
	str = ((char *)malloc(nb * sizeof(char)));
	if (str == NULL)
		return (NULL);
	while (nb)
	{
		nb -= 1;
		str[nb] = '0';
	}
	return (str);
}

char		*nwstr(void)
{
	char	*w_fd;

	w_fd = (char *)malloc(sizeof(char));
	if (!(w_fd))
		return (0);
	w_fd[0] = '\0';
	return (w_fd);
}
