/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 12:56:03 by ybakker        #+#    #+#                */
/*   Updated: 2019/12/11 15:59:14 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**check *
**check .
**check -
**check 0
***/
char    ft_flag_check(t_print **print, const char *format, int  i, va_list ap) //i is where its last used, but i cna use begin
{
    i = (*print)->begin; //begin whrre to look for, so it doens't stop the loop
    i++; //looks after %
    if (ft_is_there_pre(&print, format, i, ap) == 1)//check dot '.' precision for everything combination of * and 0 and -
    {
        ft_print_pre(&print, format, i, ap);
        return(0);
    }
    else if (ft_check_star(&print, format, i, ap) == 1) //check * and 0 and -
        return (0);
    else if (ft_check_min(&print, format, i, ap) == 1) //check min '-' and 0
        return (0);
    else if (ft_check_zero(&print, format, i, ap) == 1) //check if only 0 used
        return (0);
    return (0); //no flags, improve this
}
/*
** check for 0, if minus is in it before the converagnce go to minus
**
**
*/

ft_convergance_check() //print with va_arg the value and make the input
{

}

//check convergions with va_arg, then combine what you got and make the string you add to the main string