/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 17:02:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/22 15:16:07 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		struct_zero(t_print **print)
{
	(*print)->min = 0;
	(*print)->zero = 0;
	(*print)->convergance = '\0';
	(*print)->flag_str = NULL;
	(*print)->flag_str_pre = NULL;
	(*print)->input_str = NULL;
	(*print)->width_nb = 0;
}
