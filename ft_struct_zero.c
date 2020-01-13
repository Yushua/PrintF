/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struct_zero.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 22:27:56 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/13 18:52:23 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_zero(t_print **print)
{
	(*print)->end = 0;
	(*print)->position = 0;
	(*print)->convergence = '\0';
	(*print)->min = 0;
	(*print)->zero = 0;
	(*print)->flag_str = NULL;
	(*print)->null = NULL;
	(*print)->input_str = NULL;
	(*print)->width_nb = 0;
	(*print)->precision = 0;
	(*print)->positive = 0;
	(*print)->start = 0;
	(*print)->w_width = 0;
	(*print)->p_width = -1;
	(*print)->error = 0;
	(*print)->neg = 0;
	(*print)->pre = 0;
}

char	*ft_fill_w_null(t_print **print)
{
	char	*str;

	str = ((char *)malloc(6 * sizeof(char)));
	if (str == NULL)
		return (NULL);
	str[6] = '\0';
	str[5] = ')';
	str[4] = 'l';
	str[3] = 'l';
	str[2] = 'u';
	str[1] = 'n';
	str[0] = '(';
	return (str);
}
