/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_i_or_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:01:45 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 18:17:19 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print		ft_i_or_c(void)
{
	char	c;

	c = (*print)->convegions;
	if (c == 's' || c == 'c')
		(*print)->ccode = 1;
	else
		(*print)->ccode = 2;
	return (0);
}
