/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struct_zero.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 22:27:56 by ybakker        #+#    #+#                */
/*   Updated: 2020/01/11 18:04:04 by ybakker       ########   odam.nl         */
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
	(*print)->flag_str_pre = NULL;
	(*print)->input_str = NULL;
	(*print)->width_nb = 0;
	(*print)->width = 0;
	(*print)->precision = 0;
	(*print)->positive = 0;
	(*print)->start = 0;
	(*print)->w_width = 0;
	(*print)->p_width = -1;
	(*print)->error = 0;
}
