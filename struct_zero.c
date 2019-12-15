/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 17:02:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/15 16:42:43 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_zero(t_print **print)
{
	(*print)->begin = 0;
	(*print)->end = 0;
	(*print)->convergance = '\0';
	(*print)->flag_str = '\0';
	(*print)->flag_str_pre = '\0';
	(*print)->input_str = '\0';
	(*print)->precision = 0;
	(*print)->pre_value = 0;
	(*print)->pre_n_c = 0;
	(*print)->min = 0;
	(*print)->zero = 0;
	(*print)->position = 0;
	(*print)->value = 0;
	(*print)->width_v = 0;
	(*print)->width_nb = 0;
	(*print)->width_save_nb = 0;
}

/* 
c == cordinates
nb == number
str == string
*/
