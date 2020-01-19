/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struct_zero.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 22:27:56 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/19 16:44:20 by ybakker       ########   odam.nl         */
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
	(*print)->input_str = NULL;
	(*print)->null_str = NULL;
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

char		*ft_fill_w_null(t_print **print)
{
	(*print)->null_str = ((char *)malloc(6 * sizeof(char)));
	if ((*print)->null_str != NULL)
	{
		(*print)->null_str[6] = '\0';
		(*print)->null_str[5] = ')';
		(*print)->null_str[4] = 'l';
		(*print)->null_str[3] = 'l';
		(*print)->null_str[2] = 'u';
		(*print)->null_str[1] = 'n';
		(*print)->null_str[0] = '(';
	}
	return ((*print)->null_str);
}
