/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 17:02:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/13 14:03:42 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_zero(t_print **print)
{
	(*print)->begin = 0;
	(*print)->end = 0;
	(*print)->convergions = '\0';
	(*print)->flag_str = '\0';
	(*print)->input_str = '\0';
	(*print)->pre_c = 0;
	(*print)->pre = 0;
	(*print)->pre_n_c = 0;
	(*print)->min = 0;
	(*print)->zero = 0;
	(*print)->value = 0;
}
