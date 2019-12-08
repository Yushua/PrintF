/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/08 17:02:47 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/08 17:44:27 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

t_print     struct_zero(t_print **print);
{
    (*print)->width = 0;
    (*print)->widthf = 0;
    (*print)->convergions = strdup("");
    (*print)->flags = strdup("");
    (*print)->(*input) = strdup("");
    (*print)->end = 0;
    (*print)->positive = 0;
    (*print)->negative = 0;
    (*print)->(*error) = strdup("");
    (*print)->size = 0;
}

/*
**werkt nog niet maar verwerk ik later wel
** no begin as begin needs to keep its value as it says where ou begin after %
**is found
*/