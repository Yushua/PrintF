/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_i_or_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:01:45 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 17:11:58 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print		ft_i_or_c(void)
{
	char	str;

	str = (*print)->convegions;
	if (str == 's' || str == 'c')
		(*print)->ccode = 1;
	else
		(*print)->ccode = 2;
	return (0);
}
