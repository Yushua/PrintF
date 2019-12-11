/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 17:02:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/10 16:28:53 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print     struct_zero(t_print **print);
{
	(*print)->width = 0;
	(*print)->widthf = 0;
	(*print)->convergions = strdup("");
	(*print)->flags = strdup("");
	(*print)->(*input) = strdup("");
	(*print)->begin = 0; 
	(*print)->positive = 0;
	(*print)->negative = 0;
	(*print)->locationper = 0;
//  (*print)->precisionc = 0;
//	(*print)->widthc = 0;
//  (*print)->zero = 0;
}

/*
**werkt nog niet maar verwerk ik later wel
** no begin as begin needs to keep its value as it says where ou begin after %
**is found
*/